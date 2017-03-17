///////////////////////////////////////////////////////////
//  CmdAbs.h
//  Implementation of the Class CmdAbs
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_CMD_ABS_)
#define _HEADER_CMD_ABS_

#include "Robot.h"

class CmdAbs
{
public:
	CmdAbs(void) {};
	virtual ~CmdAbs() {};

	// Methode pour executer une commande sur le robot
	virtual void executer( Robot& robot ) = 0;

	virtual int getNumberChildren(void) const { return 0; }
	virtual const CmdAbs* getChild(int iChild) const { return NULL; }
	virtual CmdAbs* getChild(int iChild) { return NULL; }
	virtual void addChild(CmdAbs* cmd) { /* echoue silencieusement */ }
};
#endif // !defined(_HEADER_CMD_ABS_)
