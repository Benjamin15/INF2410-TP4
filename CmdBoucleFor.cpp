///////////////////////////////////////////////////////////
//  CmdBoucleFor.cpp
//  Implementation of the Class CmdBoucleFor
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CmdBoucleFor.h"

// Executer m_nbRepetitions fois les commandes enfant
void CmdBoucleFor::executer(Robot & robot)
{
	// A completer
}

// Recuperer le nombre de commandes enfant
int CmdBoucleFor::getNumberChildren(void) const
{ 
	return 0; // A completer
}

// Recuperer l'enfant iChild
const CmdAbs * CmdBoucleFor::getChild(int iChild) const 
{ 
	return nullptr; // A completer
}

// Recuperer l'enfant iChild
CmdAbs * CmdBoucleFor::getChild(int iChild)
{ 
	return nullptr; // A completer
}

// Ajouter un enfant a la fin du vecteur de commandes
void CmdBoucleFor::addChild(CmdAbs * cmd) 
{ 
	// A completer
}
