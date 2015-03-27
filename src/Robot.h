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
//#include "Subsystems/Elevator.h"
//#include "Subsystems/Wrist.h"
//#include "Subsystems/Claw.h"
#include "OI.h"
#include "Subsystems/Vision.h"
#include "Subsystems/Arm.h"
#include "Subsystems/FloperMovement.h"
#include "Subsystems/DIO.h"

class Robot: public IterativeRobot {
public:
	static DriveTrain* drivetrain;
//	static Elevator* elevator;
//	static Wrist* wrist;
//	static Claw* claw;
	static OI* oi;
	static Vision* vision;
	static Arm* arm;
	static FloperMovement *floper;

	static DIO *flopIn;
	static DIO *flopOut;

private:
	Command *autonomousCommand;
//	Command *autonomousLiftAndDrive;
//	Command *autonomousLiftAndDriveStep;
//	Command *autonomousDriveForward;
	SendableChooser *chooser;
	Command *teleopVisionCommand;
	Command *flopCommand;

//	LiveWindow *lw;

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};


#endif /* ROBOT_H_ */
