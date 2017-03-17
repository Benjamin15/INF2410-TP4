///////////////////////////////////////////////////////////
//  CmdPrendrePhoto.h
//  Implementation of the Class CmdPrendrePhoto
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_CMD_PRENDRE_PHOTO_)
#define _HEADER_CMD_PRENDRE_PHOTO_

#include "CmdAbs.h"

class CmdPrendrePhoto : public CmdAbs
{
public:
	CmdPrendrePhoto(void) {};
	virtual ~CmdPrendrePhoto() {};

	// Methode pour executer une commande sur le robot
	virtual void executer(class Robot& robot) { robot.prendrePhoto(); };
};
#endif // !defined(_HEADER_PRENDRE_PHOTO_)
