/*
 * Robot.h
 *
 *  Created on: Jun 3, 2014
 *      Author: alex
 */

#ifndef MY_ROBOT_H_
#define MY_ROBOT_H_

#include "WPILib.h"
#include "Commands/Command.h"

#include "Subsystems/DriveTrain.h"
#include "Subsystems/AnalogSensor.h"
#include "Subsystems/DIO.h"
#include "Subsystems/ArmSystem.h"
//#include "Subsystems/Elevator.h"
//#include "Subsystems/Wrist.h"
//#include "Subsystems/Claw.h"
#include "OI.h"
#include "Subsystems/Vision.h"

class Robot: public IterativeRobot {
public:
	static DriveTrain* drivetrain;
	static DIO *LimitSwitch1;
//	static Elevator* elevator;
//	static Wrist* wrist;
//	static Claw* claw;
	SendableChooser *autoChooser;
	static OI* oi;
<<<<<<< HEAD
	static Vision* vision;

private:
	Command *autonomousCommand;
	Command *teleopVisionCommand;
=======
	static AnalogSensor *analogsensor;
	static ArmSystem *armsystem;

private:
	Command *autonomousCommand;
	Command *analogSensor;
	Command *limitswitch;
	Command *arm_up_down;
>>>>>>> origin/master
//	LiveWindow *lw;

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};


#endif /* ROBOT_H_ */
