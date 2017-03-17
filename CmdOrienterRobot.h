///////////////////////////////////////////////////////////
//  CmdOrienterRobot.h
//  Implementation of the Class CmdOrienterRobot
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_CMD_ORIENTER_ROBOT_)
#define _HEADER_CMD_ORIENTER_ROBOT_

#include "CmdAbs.h"

class CmdOrienterRobot : public CmdAbs
{
	double m_longitude, m_latitude;
public:
	CmdOrienterRobot(double longitude, double latitude)
		: m_longitude(longitude), m_latitude(latitude) {};
	virtual ~CmdOrienterRobot() {};

	// Methode pour executer une commande sur le robot
	virtual void executer(class Robot& robot) { robot.changerOrientationAbsolue(m_longitude, m_latitude); };
};
#endif // !defined(_HEADER_ORIENTER_ROBOT_)
