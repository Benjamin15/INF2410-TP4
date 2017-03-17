/*****************************************************************************/
//  Test_TP4.h
//  Implementation of the Class Test_TP4
//  Created on:      2015-10-14
//  Modified on:     2016-10-26
//  Original author: El Houcine Boudoukha and Farouk Ouenniche
//  Modification:    Francois Guibault - Adapt to PolyScino
/*****************************************************************************/

#ifndef TEST_TP4_H
#define TEST_TP4_H


#include <memory>
#include <exception>

#include "CameraCanin.h"
#include "CameraPakon.h"
#include "Robot.h"
//
// Classe TestTP4
//
// Classe de test pour les elements implementes au TP4
//
class Test_TP4
{
private:
	CameraCanin m_camera1;
	Robot m_robot1;

	CameraPakon m_camera2;
	Robot m_robot2;

public:

	//-------------------------------------------
	// Constructeur & Destructeur
	//-------------------------------------------
	Test_TP4();
	~Test_TP4();

	// Tests
	void executeProxyTest();          // Execute les tests sur le Proxy
	void executeCompositeTest();      // Execute les tests sur les composites
	void executeTemplateMethodTest(); // Execute les tests sur les template methods

};

#endif// TEST_TP4_H
