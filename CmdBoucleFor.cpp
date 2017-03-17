///////////////////////////////////////////////////////////
//  CmdBoucleFor.cpp
//  Implementation of the Class CmdBoucleFor
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CmdBoucleFor.h"

/**
*
*
*Executer m_nbRepetitions fois les commandes enfant
*/
void CmdBoucleFor::executer(Robot & robot)
{
	for (int k = 0; k < m_nbRepetitions; k++)
	{
		for (int i = 0; i < m_commandes.size(); i++)
		{
			m_commandes[i]->executer(robot);
		}
	}
}

/**
*
*
*Recuperer le nombre de commandes enfant
*/
int CmdBoucleFor::getNumberChildren(void) const
{ 
	return m_commandes.size();
}

/**
*
*
* Recuperer l'enfant iChild
*/
const CmdAbs * CmdBoucleFor::getChild(int iChild) const 
{ 
	return m_commandes[iChild].get();
}

/**
*
*
*
* Recuperer l'enfant iChild
*/
CmdAbs * CmdBoucleFor::getChild(int iChild)
{ 
	return m_commandes[iChild].get();
}

/** 
*
*
* Ajouter un enfant a la fin du vecteur de commandes
*/
void CmdBoucleFor::addChild(CmdAbs * cmd) 
{ 
	m_commandes.push_back((std::shared_ptr<CmdAbs>) cmd);
}
