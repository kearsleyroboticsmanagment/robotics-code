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
	static DIO *LeftSide_Top;
	static DIO *LeftSide_Bottom;
	static DIO *RightSide_Top;
	static DIO *RightSide_Bottom;
	static DIO *LeftSide_In;
	static DIO *LeftSide_Out;
	static DIO *RightSide_In;
	static DIO *RightSide_Out;
//	static Elevator* elevator;
//	static Wrist* wrist;
//	static Claw* claw;
	SendableChooser *autoChooser;
	static OI* oi;
	static AnalogSensor *analogsensor;
	static ArmSystem *armsystem;
	static ArmSystem *armsystem_in_out;

private:
	Command *autonomousCommand;
	Command *analogSensor;
	Command *limitswitch;
	Command *arm_up_down;
	Command *armmovementassisted;
//	LiveWindow *lw;

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};


#endif /* ROBOT_H_ */
