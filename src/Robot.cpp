#include "WPILib.h"
#include "Robot.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/Autonomous.h"
#include "Commands/AutonNothing.h"
#include "Commands/ArmVertical.h"

DriveTrain* Robot::drivetrain = NULL;
//Elevator* Robot::elevator = NULL;
//Wrist* Robot::wrist = NULL;
//Claw* Robot::claw = NULL;
//
OI* Robot::oi = NULL;
Vision* Robot::vision = NULL;
Arm* Robot::arm = NULL;

void Robot::RobotInit() {
	autoChooser = new SendableChooser();
	drivetrain = new DriveTrain();
//	elevator = new Elevator();
//	wrist = new Wrist();
//	claw = new Claw();
//
	oi = new OI();
	vision = new Vision();
	arm = new Arm();
//
	autonomousCommand = new Autonomous();
	autonDoNothing = new AutonNothing();
//	lw = LiveWindow::GetInstance();
//
//    // Show what command your subsystem is running on the SmartDashboard
//    SmartDashboard::PutData(drivetrain);
//    SmartDashboard::PutData(elevator);
//    SmartDashboard::PutData(wrist);
//    SmartDashboard::PutData(claw);
	autoChooser->AddDefault("Drive Forward", autonomousCommand);
	autoChooser->AddObject("Do Nothing", autonDoNothing);
	SmartDashboard::PutData("Autonomous Modes:", autoChooser);
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
