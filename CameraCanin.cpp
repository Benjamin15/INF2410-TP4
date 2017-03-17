///////////////////////////////////////////////////////////
//  CameraCanin.cpp
//  Implementation of the Class CameraCanin
//  Created on:      27-oct.-2016 15:21:34
//  Original author: francois
///////////////////////////////////////////////////////////

#include <iostream>

#include "CameraCanin.h"

CameraCanin::CameraCanin() 
	: m_resolutionX(resolutionsMaxX), m_resolutionY(resolutionsMaxY), m_capaciteMemoire(8 * un_gigabyte),
	m_sensibilite(sensibilite_min), m_flashActif(false), m_chargeBatterie(chargeBatterieMax)
{ 
}

void CameraCanin::prendrePhoto(void)
{
	m_compteTotalPhotos++;
	if ((m_chargeBatterie >= 6) || (!m_flashActif && m_chargeBatterie >= 1))
	{
		m_photos.push_back(std::shared_ptr<Photo>(new Photo(m_resolutionX, m_resolutionY)));
		m_chargeBatterie -= (m_flashActif ? 6 : 1);
	}
}

int CameraCanin::getNbPhotos(void)
{
	return m_photos.size();
}

void CameraCanin::eliminerPhotos(void)
{
	m_photos.clear();
}

PhotoIteratorCanin* CameraCanin::begin(void) const
{ 
	return new PhotoIteratorCanin(m_photos.cbegin());
}

PhotoIteratorCanin* CameraCanin::end(void) const
{ 
	return new PhotoIteratorCanin(m_photos.cend());
}

void CameraCanin::changerResolution(int dimX, int dimY)
{
	if (dimX >= resolutionsMinX && dimX <= resolutionsMaxX && dimY >= resolutionsMinY && dimY <= resolutionsMaxY)
	{
		m_resolutionX = dimX;
		m_resolutionY = dimY;
	}
}

void CameraCanin::changerSensibilite(int sensib)
{
	if (sensib >= sensibilite_min && sensib <= sensibilite_max)
		m_sensibilite = sensib;
}

void CameraCanin::activerFlash(void)
{
	m_flashActif = true;
}

void CameraCanin::desactiverFlash(void)
{
	m_flashActif = false;
}

void CameraCanin::rechargerBatterie(void)
{
	m_chargeBatterie = chargeBatterieMax;
}

CameraCanin::Resolution_type CameraCanin::getMemoireRestante(void) const
{
	Resolution_type memrest = m_capaciteMemoire;

	PhotoIteratorCanin* itb = begin();
	PhotoIteratorCanin* ite = end();

	while (*itb != *ite)
	{
		memrest -= itb->get().getTaille();
		itb->incremente();
	}

	return memrest;
}

int CameraCanin::getChargeRestante(void) const
{
	return m_chargeBatterie;
}

void CameraCanin::getResolution(int & dimX, int & dimY) const
{
	dimX = m_resolutionX;
	dimY = m_resolutionY;
}

int CameraCanin::getSensibilite(void) const
{
	return m_sensibilite;
}

bool CameraCanin::getActivationFlash(void) const
{
	return m_flashActif;
}

ResultatTest CameraCanin::opDiagnostiquerMemoire()
{
	return (getMemoireRestante() >= m_resolutionX*m_resolutionY) ? ResultatTest::succes : ResultatTest::echec;
}

ResultatTest CameraCanin::opDiagnostiquerBatterie()
{
	return (getChargeRestante() >= 5 || (!m_flashActif && getChargeRestante() >= 2)) ? ResultatTest::succes : ResultatTest::echec;;
}

ResultatTest CameraCanin::opDiagnostiquerFlash()
{
	return (getCompteTotalPhotos() < comptePhotoMax) ? ResultatTest::succes : ResultatTest::echec;
}
