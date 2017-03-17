///////////////////////////////////////////////////////////
//  CameraPakon.cpp
//  Implementation of the Class CameraPakon
//  Created on:      14-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include <iostream>

#include "CameraPakon.h"
#include "PhotoIteratorPakon.h"

CameraPakon::CameraPakon() 
	: m_resolutionX(resolutionsMaxX), m_resolutionY(resolutionsMaxY), m_capaciteMemoire(8*un_gigabyte),
	m_sensibilite(sensibilite_min), m_flashActif(false), m_chargeBatterie(chargeBatterieMax)
{ 
}

void CameraPakon::prendrePhoto(void)
{
	m_compteTotalPhotos++;
	if((m_chargeBatterie >= 5) || (! m_flashActif && m_chargeBatterie >=2))
	{ 
		m_photos.push_back(std::shared_ptr<Photo>(new Photo(m_resolutionX, m_resolutionY)));
		m_chargeBatterie -= (m_flashActif ? 5 : 2);
	}
}

int CameraPakon::getNbPhotos(void)
{
	return m_photos.size();
}

void CameraPakon::eliminerPhotos(void)
{
	m_photos.clear();
}

PhotoIteratorPakon* CameraPakon::begin(void) const
{
	return new PhotoIteratorPakon(m_photos.cbegin());
}

PhotoIteratorPakon* CameraPakon::end(void) const
{
	return new PhotoIteratorPakon(m_photos.cend());
}

void CameraPakon::changerResolution(int dimX, int dimY)
{
	if (dimX >= resolutionsMinX && dimX <= resolutionsMaxX && dimY >= resolutionsMinY && dimY <= resolutionsMaxY)
	{
		m_resolutionX = dimX;
		m_resolutionY = dimY;
	}
}

void CameraPakon::changerSensibilite(int sensib)
{
	if (sensib >= sensibilite_min && sensib <= sensibilite_max)
		m_sensibilite = sensib;
}

void CameraPakon::activerFlash(void)
{
	m_flashActif = true;
}

void CameraPakon::desactiverFlash(void)
{
	m_flashActif = false;
}

void CameraPakon::rechargerBatterie(void)
{
	m_chargeBatterie = chargeBatterieMax;
}

CameraPakon::Resolution_type CameraPakon::getMemoireRestante(void)  const
{
	Resolution_type memrest = m_capaciteMemoire;

	PhotoIteratorPakon* itb = begin();
	PhotoIteratorPakon* ite = end();

	while (*itb != *ite)
	{
		memrest -= itb->get().getTaille();
		itb->incremente();
	}

	return memrest;
}

int CameraPakon::getChargeRestante(void) const
{
	return m_chargeBatterie;
}

void CameraPakon::getResolution(int & dimX, int & dimY) const
{
	dimX = m_resolutionX;
	dimY = m_resolutionY;
}

int CameraPakon::getSensibilite(void) const
{
	return m_sensibilite;
}

bool CameraPakon::getActivationFlash(void) const
{
	return m_flashActif;
}

ResultatTest CameraPakon::opDiagnostiquerMemoire()
{
	return (getMemoireRestante() >= m_resolutionX*m_resolutionY) ? ResultatTest::succes : ResultatTest::echec;
}

ResultatTest CameraPakon::opDiagnostiquerBatterie()
{
	return (getChargeRestante() >= 5 || (! m_flashActif && getChargeRestante() >= 2)) ? ResultatTest::succes : ResultatTest::echec;
}

ResultatTest CameraPakon::opDiagnostiquerFlash()
{
	return (getCompteTotalPhotos() < comptePhotoMax) ? ResultatTest::succes : ResultatTest::echec;
}
