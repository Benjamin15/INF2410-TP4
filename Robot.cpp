#include "Robot.h"
#include "CmdAbs.h"

void Robot::executerProgramme(CmdAbs * programme)
{
	programme->executer(*this);
}

void Robot::prendrePhoto(void) 
{ 
	// A completer
}

int Robot::getNbPhotos(void)
{
	return 0; // A completer
}

void Robot::changerResolution(int dimX, int dimY) 
{ 
	// A completer
}

void Robot::changerSensibilite(int sensib) 
{ 
	// A completer
}

void Robot::activerFlash(void) 
{ 
	// A completer
}

void Robot::desactiverFlash(void) 
{ 
	// A completer
}

CameraAbs::Resolution_type Robot::getMemoireRestante(void) 
{ 
	return 0; // A completer
}

int Robot::getChargeRestante(void) const
{
	return 0; // A completer
}

void Robot::getResolution(int & dimX, int & dimY) 
{ 
	// A completer
}

int Robot::getSensibilite(void) 
{ 
	return 0; // A completer
}

bool Robot::getActivationFlash(void) 
{ 
	return false; // A completer
}

void Robot::changerOrientationAbsolue(double longitude, double latitude)
{
	// A completer
}

void Robot::changerOrientationRelative(double incLongitude, double incLatitude)
{
	// A completer
}

void Robot::getOrientation(double & longitude, double & latitude) const
{
	// A completer
}
