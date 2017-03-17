///////////////////////////////////////////////////////////
//  CmdBoucleFor.h
//  Implementation of the Class CmdBoucleFor
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_CMD_BOUCLE_FOR_)
#define _HEADER_CMD_BOUCLE_FOR_

#include "CmdAbs.h"

#include <memory>
#include <vector>

class CmdBoucleFor : public CmdAbs
{
	int m_nbRepetitions;
	std::vector<std::shared_ptr<CmdAbs>> m_commandes;

public:
	CmdBoucleFor(int nbRepetitions = 1) : m_nbRepetitions(nbRepetitions) {};
	virtual ~CmdBoucleFor() {};

	// Methode pour executer une commande sur le robot
	virtual void executer(class Robot& robot);

	virtual int getNumberChildren(void) const;
	virtual const CmdAbs* getChild(int iChild) const;
	virtual CmdAbs* getChild(int iChild);
	virtual void addChild(CmdAbs* cmd);
};
#endif // !defined(_HEADER_BOUCLE_FOR_)
