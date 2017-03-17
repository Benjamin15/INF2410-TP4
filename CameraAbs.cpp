///////////////////////////////////////////////////////////
//  Camera.cpp
//  Implementation of the Class CameraAbs
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include <iostream>

#include "CameraAbs.h"

ResultatTest CameraAbs::diagnostiquer(){
	// Methode servant a appeler les operations de diagnostique pour les differentes composantes de la machine

	ResultatTest res = ResultatTest::echec;

	// Diagnostiquer la memoire
	res = opDiagnostiquerMemoire();
	// Diagnostiquer la batterie
	if (res == ResultatTest::succes)
		res = opDiagnostiquerBatterie();
	// Diagnostiquer le flash.
	if (res == ResultatTest::succes)
		res = opDiagnostiquerFlash();
	return res;
}

