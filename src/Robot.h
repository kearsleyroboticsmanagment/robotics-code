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

class Robot: public IterativeRobot {
public:
	static DriveTrain* drivetrain;
	static DIO *LimitSwitch1;
	static DIO *LimitSwitch2;
	static DIO *LimitSwitch3;
	static DIO *LimitSwitch4;
	static DIO *LimitSwitch5;
	static DIO *LimitSwitch6;
	static DIO *LimitSwitch7;
	static DIO *LimitSwitch8;
//	static Elevator* elevator;
//	static Wrist* wrist;
//	static Claw* claw;
	SendableChooser *autoChooser;
	static OI* oi;
	static AnalogSensor *analogsensor;
	static ArmSystem *armsystem;

private:
	Command *autonomousCommand;
	Command *analogSensor;
	Command *limitswitch;
	Command *arm_up_down;
//	LiveWindow *lw;

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};


#endif /* ROBOT_H_ */
