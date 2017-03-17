///////////////////////////////////////////////////////////
//  CmdTournerRobot.h
//  Implementation of the Class CmdTournerRobot
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_CMD_Tourner_ROBOT_)
#define _HEADER_CMD_Tourner_ROBOT_

#include "CmdAbs.h"

class CmdTournerRobot : public CmdAbs
{
	double m_incLongitude, m_incLatitude;
public:
	CmdTournerRobot(double incLongitude, double incLatitude) 
		: m_incLongitude(incLongitude), m_incLatitude(incLatitude) {};
	virtual ~CmdTournerRobot() {};

	// Methode pour executer une commande sur le robot
	virtual void executer(class Robot& robot) { robot.changerOrientationRelative(m_incLongitude, m_incLatitude); };
};
#endif // !defined(_HEADER_Tourner_ROBOT_)
