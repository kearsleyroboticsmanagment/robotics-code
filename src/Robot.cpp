#include "WPILib.h"
#include "Robot.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/Autonomous.h"
#include "Commands/UltraSonicSensor.h"
#include "Commands/LimitSwitches.h"
#include "Commands/ArmUp_Down.h"

#include <stdio.h>

DriveTrain* Robot::drivetrain = NULL;
AnalogSensor *Robot::analogsensor = NULL;
DIO *Robot::LimitSwitch1 = NULL;
ArmSystem *Robot::armsystem = NULL;
//Elevator* Robot::elevator = NULL;
//Wrist* Robot::wrist = NULL;
//Claw* Robot::claw = NULL;
//
OI* Robot::oi = NULL;
Vision* Robot::vision = NULL;


void Robot::RobotInit()
{
	autoChooser = new SendableChooser();
	printf("ROBOT STARTING!!!/n");
	drivetrain = new DriveTrain();
	printf("drivetrain created/n");
	analogsensor = new AnalogSensor();
	printf("analogsensor created/n");
	LimitSwitch1 = new DIO();
	printf("LimitSwitch1 created/n");
	LimitSwitch1->SetPort(4, "Limit Switch #1");
	printf("LimitSwitch1 set/n");
	armsystem = new ArmSystem();
	printf("armsystem created/n");
//	elevator = new Elevator();
//	wrist = new Wrist();
//	claw = new Claw();
	oi = new OI();
<<<<<<< HEAD
	vision = new Vision();
//
=======
	printf("oi created/n");

	analogSensor = new UltraSonicSensor();
	printf("analogSensor created/n");
>>>>>>> origin/master
	autonomousCommand = new Autonomous();
	printf("autonomousCommand created/n");
	limitswitch = new LimitSwitches();
	printf("limitswitch created/n");
	arm_up_down = new ArmUp_Down();
	printf("arm_up_down created/n");

	autoChooser->AddDefault("Default program", autonomousCommand);
	autoChooser->AddObject("Experimental auto", arm_up_down);
	SmartDashboard::PutData("Autonomous mode chooser", autoChooser);
//	lw = LiveWindow::GetInstance();
//
//    // Show what command your subsystem is running on the SmartDashboard
//    SmartDashboard::PutData(drivetrain);
//	SmartDashboard::PutData(analogsensor);
//    SmartDashboard::PutData(LimitSwitch1);
//    SmartDashboard::PutData(armsystem);
//    SmartDashboard::PutData(elevator);
//    SmartDashboard::PutData(wrist);
//    SmartDashboard::PutData(claw);
}

void Robot::AutonomousInit() {
	autonomousCommand = (Command *) autoChooser->GetSelected();
	autonomousCommand->Start();
//	std::cout << "Starting Auto" << std::endl;
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand->Cancel();
//	std::cout << "Starting Teleop" << std::endl;
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	//lw->Run();
}

START_ROBOT_CLASS(Robot);
