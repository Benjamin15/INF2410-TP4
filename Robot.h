///////////////////////////////////////////////////////////
//  Robot.h
//  Implementation of the Class Robot
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_ROBOT_)
#define _HEADER_ROBOT_

#include <memory>
#include <list>

#include "CameraAbs.h"

class CmdAbs;

class Robot
{
	double m_longitude, m_latitude;
	CameraAbs& m_camera;

public:
	Robot( double longitudeInitiale, double latitudeInitiale, CameraAbs& cam)
		: m_longitude(longitudeInitiale), m_latitude(latitudeInitiale), m_camera(cam) {};
	virtual ~Robot() {};

	virtual void executerProgramme(CmdAbs* programme);

	// Methodes de controle de la camera
	virtual void prendrePhoto(void);
	virtual int getNbPhotos(void);
	virtual void changerResolution(int dimX, int dimY);
	virtual void changerSensibilite(int sensib);
	virtual void activerFlash(void);
	virtual void desactiverFlash(void);

	virtual CameraAbs::Resolution_type getMemoireRestante(void);
	virtual int getChargeRestante(void) const;
	virtual void getResolution(int& dimX, int& dimY);
	virtual int getSensibilite(void);
	virtual bool getActivationFlash(void);

	// Methodes de controle du robot
	virtual void changerOrientationAbsolue(double longitude, double latitude);
	virtual void changerOrientationRelative(double incLongitude, double incLatitude);
	virtual void getOrientation(double& longitude, double& latitude) const;
};
#endif // !defined(_HEADER_ROBOT_)
