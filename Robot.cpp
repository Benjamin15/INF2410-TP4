#include "Robot.h"
#include "CmdAbs.h"

/**
* Methode permettant d'executer un programme
*
*@param cmdAbs
*/
void Robot::executerProgramme(CmdAbs * programme)
{
	programme->executer(*this);
}

/**
* Methode permettant de prendre une photo
*
*
*/
void Robot::prendrePhoto(void) 
{ 
	m_camera.prendrePhoto();
}

/**
*
* Methode permettant d'obtenir le nombre de photo dans la caméra
* @return nbPhoto
*/
int Robot::getNbPhotos(void)
{
	return m_camera.getNbPhotos();
}


/**
* Methode permettant de modifier la résolution
* @param dimX, dimY
*
*/

void Robot::changerResolution(int dimX, int dimY) 
{ 
	m_camera.changerResolution(dimX, dimY);
}

/**
* Methode permettant de modifier la sensibilité
*
* @param sensib
*/

void Robot::changerSensibilite(int sensib) 
{ 
	m_camera.changerSensibilite(sensib);
}

/**
* Methode permettant d'activer le Flash
*
*
*/

void Robot::activerFlash(void) 
{ 
	m_camera.activerFlash();
}

/**
* Methode permettant de désactiver le flash
*
*
*/

void Robot::desactiverFlash(void) 
{ 
	m_camera.desactiverFlash();
}

/**
* Methode permettant d'obtenur la mémoire restante
*
* @return CameraAbs::Resolution_Type
*/

CameraAbs::Resolution_type Robot::getMemoireRestante(void) 
{ 
	return m_camera.getMemoireRestante();
}

/**
* Methode permettant d'obtenir le nombre de charge restante.
*
* @return nbCharge
*/

int Robot::getChargeRestante(void) const
{
	return m_camera.getChargeRestante();
}

/**
*
* Methode permettant d'obtenir la résolution dans les variable dimX et dimY
*
*/

void Robot::getResolution(int & dimX, int & dimY) 
{ 
	m_camera.getResolution(dimX, dimY);
}

/**
*
* Methode permettant d'obtenir la sensibilité
* @return int
*/

int Robot::getSensibilite(void) 
{ 
	return m_camera.getSensibilite();
}

/**
*
* Methode permettant de voir si le flash est activé
* @return bool
*/

bool Robot::getActivationFlash(void) 
{ 
	return m_camera.getActivationFlash();
}

/**
* Methode permettant de modifier l'orientation de façon absolu
* @param longitude, latitude
*
*/

void Robot::changerOrientationAbsolue(double longitude, double latitude)
{
	m_latitude = latitude;
	m_longitude = longitude;
}

/**
*
* Methode permettant de changer l'orientation Relativ
* @param incLongitude, incLatitude
*/

void Robot::changerOrientationRelative(double incLongitude, double incLatitude)
{
	m_latitude *= incLatitude;
	m_longitude *= incLongitude;
}

/**
* Methode permettant d'obtenir l'orientation dans les variable en entrée
*@param longitude, latitude
*
*/

void Robot::getOrientation(double & longitude, double & latitude) const
{
	longitude = m_longitude;
	latitude = m_latitude;
}
