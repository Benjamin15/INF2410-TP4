
#include "Test_TP4.h"

#include <iostream>

#include "CmdBoucleFor.h"
#include "CmdPrendrePhoto.h"
#include "CmdOrienterRobot.h"
#include "CmdTournerRobot.h"

#include "CameraCanin.h"
#include "CameraPakon.h"

Test_TP4::Test_TP4()
: m_camera1(), m_robot1(0, 0, m_camera1), m_camera2(), m_robot2(0, 0, m_camera2)
{
}

Test_TP4::~Test_TP4()
{
}

void Test_TP4::executeProxyTest()
{
	std::cout << std::endl << std::endl << "------------------------- PROXY -------------------------------" << std::endl << std::endl;
	std::cout << std::endl;

	m_robot1.changerOrientationAbsolue(45.216, 171.14);
	m_robot1.changerOrientationRelative(0.784, 0.86);
	double longitude, latitude;
	m_robot1.getOrientation(longitude, latitude);
	std::cout << "PROXY Test 1: " << (((longitude+latitude-218.0) < 0.000001) ? "SUCCES" : "ECHEC") << std::endl;

	for (int iphoto = 0; iphoto < 500; ++iphoto)
		m_robot1.prendrePhoto();
	std::cout << "PROXY Test 2: " << ((m_robot1.getMemoireRestante() == 60330868736) ? "SUCCES" : "ECHEC") << std::endl;
	std::cout << "PROXY Test 3: " << ((m_robot1.getNbPhotos() == 500) ? "SUCCES" : "ECHEC") << std::endl;

	for (int iphoto = 0; iphoto < 500; ++iphoto)
	{
		m_robot2.prendrePhoto();
		m_robot2.activerFlash();
		m_robot2.prendrePhoto();
		m_robot2.desactiverFlash();
	}
	std::cout << "PROXY Test 4: " << ((m_robot2.getChargeRestante() == 1) ? "SUCCES" : "ECHEC") << std::endl;
	std::cout << "PROXY Test 5: " << ((m_robot2.getNbPhotos() == 172) ? "SUCCES" : "ECHEC") << std::endl;
}

void Test_TP4::executeTemplateMethodTest()
{
	std::cout << std::endl << std::endl << "------------------------- TEMPLATE METHOD -------------------------------" << std::endl << std::endl;
	std::cout << std::endl;

	// Executer les diagnostiques sur les cameras
	std::cout << std::endl << std::endl << "------------------------- DIAGNOSTIQUE DE LA 1ere camera (1) ----------" << std::endl << std::endl;
	ResultatTest res1 = m_camera1.diagnostiquer();
	std::cout << "TEMPLATE METHOD diagnostiquer (cam1): " << ((res1 == ResultatTest::succes) ? "SUCCES" : "ECHEC") << std::endl;

	std::cout << std::endl << std::endl << "------------------------- DIAGNOSTIQUE DE LA 2eme camera (1) ----------" << std::endl << std::endl;
	ResultatTest res2 = m_camera2.diagnostiquer();
	std::cout << "TEMPLATE METHOD diagnostiquer (cam2): " << ((res2 == ResultatTest::echec) ? "SUCCES" : "ECHEC") << std::endl;

	m_camera1.rechargerBatterie();
	m_camera2.rechargerBatterie();

	// Executer les diagnostiques sur les cameras
	std::cout << std::endl << std::endl << "------------------------- DIAGNOSTIQUE DE LA 1ere camera (2) ----------" << std::endl << std::endl;
	ResultatTest res3 = m_camera1.diagnostiquer();
	std::cout << "TEMPLATE METHOD diagnostiquer (cam1): " << ((res3 == ResultatTest::succes) ? "SUCCES" : "ECHEC") << std::endl;

	std::cout << std::endl << std::endl << "------------------------- DIAGNOSTIQUE DE LA 2eme camera (2) ----------" << std::endl << std::endl;
	ResultatTest res4 = m_camera2.diagnostiquer();
	std::cout << "TEMPLATE METHOD diagnostiquer (cam2): " << ((res4 == ResultatTest::succes) ? "SUCCES" : "ECHEC") << std::endl;
}

void Test_TP4::executeCompositeTest()
{
	std::cout << std::endl << std::endl << "------------------------- COMPOSITE -------------------------------" << std::endl << std::endl;
	std::cout << std::endl;

	// Construire un programme de controle du robot et de la camera 
	CmdBoucleFor* racine = new CmdBoucleFor();
	racine->addChild(new CmdOrienterRobot(172, 45));
	CmdBoucleFor* repet = new CmdBoucleFor(5);
	repet->addChild(new CmdPrendrePhoto());
	repet->addChild(new CmdTournerRobot(0.05, 0.001));
	racine->addChild(repet);
	racine->addChild(new CmdPrendrePhoto());

	// Verifier la structure du programme composite
	std::cout << std::endl << std::endl << "------------------------- Test du programme ----------" << std::endl << std::endl;
	std::cout << "COMPOSITE Test 1: " << ((racine->getNumberChildren() + repet->getNumberChildren() == 5) ? "SUCCES" : "ECHEC") << std::endl;

	int nbPhotosAv = m_camera1.getNbPhotos();
	m_robot1.executerProgramme(racine);
	int nbPhotosAp = m_camera1.getNbPhotos();
	std::cout << "COMPOSITE Test 2: " << (((nbPhotosAp - nbPhotosAv) == 6) ? "SUCCES" : "ECHEC") << std::endl;
}

