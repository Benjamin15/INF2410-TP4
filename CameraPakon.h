///////////////////////////////////////////////////////////
//  CameraPakon.h
//  Implementation of the Class CameraPakon
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_CAMERA_Pakon_)
#define _HEADER_CAMERA_Pakon_

#include "CameraAbs.h"
#include "PhotoIteratorPakon.h"

#include <list>
#include <memory>

class CameraPakon : public CameraAbs
{
	const static Resolution_type resolutionsMinX = 512;
	const static Resolution_type resolutionsMinY = 384;
	const static Resolution_type resolutionsMaxX = 4096;
	const static Resolution_type resolutionsMaxY = 3072;
	const static int sensibilite_min = 100;
	const static int sensibilite_max = 64000;
	const static int chargeBatterieMax = 600;
	const static int comptePhotoMax = 100000;

	friend class Test_TP4;

	int m_resolutionX, m_resolutionY;
	Resolution_type m_capaciteMemoire;
	int m_sensibilite;
	bool m_flashActif;
	int m_chargeBatterie;
	std::list<std::shared_ptr<Photo> > m_photos;

public:
	CameraPakon(void);
	virtual ~CameraPakon() {};

	virtual void prendrePhoto(void);
	virtual int getNbPhotos(void);
	virtual void eliminerPhotos(void);

	virtual PhotoIteratorPakon* begin(void) const;
	virtual PhotoIteratorPakon* end(void) const;

	virtual void changerResolution(int dimX, int dimY);
	virtual void changerSensibilite(int sensib);
	virtual void activerFlash(void);
	virtual void desactiverFlash(void);
	virtual void rechargerBatterie(void);

	virtual Resolution_type getMemoireRestante(void) const;
	virtual int getChargeRestante(void) const;
	virtual void getResolution(int& dimX, int& dimY) const;
	virtual int getSensibilite(void) const;
	virtual bool getActivationFlash(void) const;

protected:
	// operations elementaires de diagnostique
	virtual ResultatTest opDiagnostiquerMemoire();
	virtual ResultatTest opDiagnostiquerBatterie();
	virtual ResultatTest opDiagnostiquerFlash();
};
#endif // !defined(_HEADER_CAMERA_Pakon_)
