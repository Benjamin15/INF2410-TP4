///////////////////////////////////////////////////////////
//  CameraAbs.h
//  Implementation of the Class CameraAbs
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_CAMERA_ABS_)
#define _HEADER_CAMERA_ABS_

#include "Photo.h"
#include "ResultatTest.h"
#include "PhotoIterator.h"

class CameraAbs
{
public:
	typedef long long unsigned int Resolution_type;

protected:
	const static Resolution_type un_gigabyte = 8589934592;

	int m_compteTotalPhotos;

public:
	CameraAbs(void) : m_compteTotalPhotos(0) {};
	virtual ~CameraAbs() {};

	virtual void prendrePhoto( void ) = 0;
	virtual int getNbPhotos(void) = 0;
	virtual void eliminerPhotos(void) = 0;
	virtual int getCompteTotalPhotos(void) const { return m_compteTotalPhotos; }
	
	virtual PhotoIterator* begin(void) const = 0;
	virtual PhotoIterator* end(void) const = 0;

	virtual void changerResolution(int dimX, int dimY) = 0;
	virtual void changerSensibilite(int sensib) = 0;
	virtual void activerFlash(void) = 0;
	virtual void desactiverFlash(void) = 0;
	virtual void rechargerBatterie(void) = 0;

	virtual Resolution_type getMemoireRestante(void) const = 0;
	virtual int getChargeRestante(void) const = 0;
	virtual void getResolution(int& dimX, int& dimY) const = 0;
	virtual int getSensibilite(void) const = 0;
	virtual bool getActivationFlash(void) const = 0;

	ResultatTest diagnostiquer();

protected:
	// operations elementaires de diagnostique
	virtual ResultatTest opDiagnostiquerMemoire() = 0;
	virtual ResultatTest opDiagnostiquerBatterie() = 0;
	virtual ResultatTest opDiagnostiquerFlash() = 0;
};
#endif // !defined(_HEADER_CAMERA_ABS_)
