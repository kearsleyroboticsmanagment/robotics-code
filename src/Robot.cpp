#include "WPILib.h"
#include "Robot.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/Autonomous.h"
#include "Commands/UltraSonicSensor.h"
#include "Commands/LimitSwitches.h"
#include "Commands/ArmUp_Down.h"
#include "Commands/ArmMovementAssisted.h"

#include <stdio.h>

DriveTrain* Robot::drivetrain = NULL;
AnalogSensor *Robot::analogsensor = NULL;
DIO *Robot::ArmUpDown_LeftSide_Top = NULL;
DIO *Robot::ArmUpDown_LeftSide_Bottom = NULL;
DIO *Robot::ArmUpDown_RightSide_Top = NULL;
DIO *Robot::ArmUpDown_RightSide_Bottom = NULL;
DIO *Robot::ArmInOut_LeftSide_In = NULL;
DIO *Robot::ArmInOut_LeftSide_Out = NULL;
DIO *Robot::ArmInOut_RightSide_In = NULL;
DIO *Robot::ArmInOut_RightSide_Out = NULL;
ArmSystem *Robot::armsystem = NULL;
ArmSystem *Robot::armsystem_in_out = NULL;
//Elevator* Robot::elevator = NULL;
//Wrist* Robot::wrist = NULL;
//Claw* Robot::claw = NULL;
//
OI* Robot::oi = NULL;


void Robot::RobotInit()
{
	autoChooser = new SendableChooser(); //selectable auton
	//printf("ROBOT STARTING!!!/n");
	drivetrain = new DriveTrain();
	//printf("drivetrain created/n");
	analogsensor = new AnalogSensor();
	//printf("analogsensor created/n");
	ArmUpDown_LeftSide_Top = new DIO(0);
	ArmUpDown_LeftSide_Bottom = new DIO(1);
	ArmUpDown_RightSide_Top = new DIO(2);
	ArmUpDown_RightSide_Bottom = new DIO(3);
	ArmInOut_LeftSide_In = new DIO(4);
	ArmInOut_LeftSide_Out = new DIO(5);
	ArmInOut_RightSide_In = new DIO(6);
	ArmInOut_RightSide_In = new DIO(7);
	//printf("LimitSwitch1 created/n");
	ArmUpDown_LeftSide_Top->SetPort(0, "Limit Switch #1");
	ArmUpDown_LeftSide_Bottom->SetPort(1, "Limit Switch #2");
	ArmUpDown_RightSide_Top->SetPort(2, "Limit Switch #3");
	ArmUpDown_RightSide_Bottom->SetPort(3, "Limit Switch #4");
	ArmInOut_LeftSide_In->SetPort(4, "Limit Switch #5");
	ArmInOut_LeftSide_Out->SetPort(5, "Limit Switch #6");
	ArmInOut_RightSide_In->SetPort(6, "Limit Switch #7");
	ArmInOut_RightSide_Out->SetPort(7, "Limit Switch #8");
	//printf("LimitSwitch1 set/n");
	armsystem = new ArmSystem();
	armsystem_in_out = new ArmSystem(1);//Sent a 1 in order to bypass the redeclaration of the victors
	//printf("armsystem created/n");
//	elevator = new Elevator();
//	wrist = new Wrist();
//	claw = new Claw();
	oi = new OI();
	//printf("oi created/n");

	analogSensor = new UltraSonicSensor();
	//printf("analogSensor created/n");
	autonomousCommand = new Autonomous();
	//printf("autonomousCommand created/n");
	limitswitch = new LimitSwitches();
	//printf("limitswitch created/n");
	arm_up_down = new ArmUp_Down();
	//printf("arm_up_down created/n");
	armmovementassisted = new ArmMovementAssisted();

	armsystem_in_out->SetCurrentCommand(Robot::armmovementassisted);

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
