///////////////////////////////////////////////////////////
//  CameraCanin.h
//  Implementation of the Class CameraCanin
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_CAMERA_CANIN_)
#define _HEADER_CAMERA_CANIN_

#include "CameraAbs.h"
#include "PhotoIteratorCanin.h"

#include <vector>
#include <memory>

class CameraCanin : public CameraAbs
{
	const static Resolution_type resolutionsMinX = 1024;
	const static Resolution_type resolutionsMinY = 1024;
	const static Resolution_type resolutionsMaxX = 4096;
	const static Resolution_type resolutionsMaxY = 4096;
	const static int sensibilite_min = 100;
	const static int sensibilite_max = 16000;
	const static int chargeBatterieMax = 800;
	const static int comptePhotoMax = 150000;

	friend class Test_TP4;

	int m_resolutionX, m_resolutionY;
	Resolution_type m_capaciteMemoire;
	int m_sensibilite;
	bool m_flashActif;
	int m_chargeBatterie;
	std::vector<std::shared_ptr<Photo> > m_photos;

public:
	CameraCanin(void);;
	virtual ~CameraCanin() {};

	virtual void prendrePhoto(void);
	virtual int getNbPhotos(void);
	virtual void eliminerPhotos(void);

	virtual PhotoIteratorCanin* begin(void) const;
	virtual PhotoIteratorCanin* end(void) const;

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
#endif // !defined(_HEADER_CAMERA_CANIN_)
