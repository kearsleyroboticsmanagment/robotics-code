#include "WPILib.h"
#include "Robot.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/Autonomous.h"
#include "Commands/ArmVertical.h"
#include "Commands/LimitSwitches.h"
#include "Commands/FlopNow.h"
#include "Commands/FlopNowUp.h"
#include "Commands/FlopNowDown.h"
#include "Commands/WheelsMoveCommand.h"
#include "Commands/WheelsMoveInCommand.h"
#include "Commands/WheelsMoveOutCommand.h"

#include "Commands/Autonomous.h"
#include "Commands/AutonLift.h"
#include "Commands/AutonLiftAndDrive.h"
#include "Commands/AutonLiftAndDriveStep.h"
#include "Commands/AutonLiftAndDriveBackwardStep.h"

DriveTrain* Robot::drivetrain = NULL;
//Elevator* Robot::elevator = NULL;
//Wrist* Robot::wrist = NULL;
//Claw* Robot::claw = NULL;
//
OI* Robot::oi = NULL;
Vision* Robot::vision = NULL;
Arm* Robot::arm = NULL;
FloperMovement *Robot::floper = NULL;
DIO *Robot::flopIn = NULL;
DIO *Robot::flopOut = NULL;
RollerWheels *Robot::rollers = NULL;


void Robot::RobotInit() {
	drivetrain = new DriveTrain();
//	elevator = new Elevator();
//	wrist = new Wrist();
//	claw = new Claw();
//
	vision = new Vision();
	arm = new Arm();

	floper = new FloperMovement();
	flopIn = new DIO(0);
	flopOut = new DIO(1);
	rollers = new RollerWheels();

	autonomousCommand = new Autonomous();
	flopCommand = new FlopNow();
	wheelsmovecommand = new WheelsMoveCommand();

	oi = new OI();

	chooser = new SendableChooser();
	chooser->AddDefault("Lift Only", new AutonLift());
	chooser->AddObject("Lift and Drive", new AutonLiftAndDrive());
	chooser->AddObject("Lift and Drive Over Step", new AutonLiftAndDriveStep());
	chooser->AddObject("Lift and Drive Backward Over Step", new AutonLiftAndDriveBackwardStep());
	chooser->AddObject("Drive Only", new Autonomous());
	SmartDashboard::PutData("Auton Modes:", chooser);
//	lw = LiveWindow::GetInstance();
//
//    // Show what command your subsystem is running on the SmartDashboard
//    SmartDashboard::PutData(drivetrain);
//    SmartDashboard::PutData(elevator);
//    SmartDashboard::PutData(wrist);
//    SmartDashboard::PutData(claw);
}

void Robot::AutonomousInit() {
	autonomousCommand = (Command *) chooser->GetSelected();
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
