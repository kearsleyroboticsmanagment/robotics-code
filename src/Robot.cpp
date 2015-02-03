#include "WPILib.h"
#include "Robot.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/Autonomous.h"
#include "Commands/UltraSonicSensor.h"

DriveTrain* Robot::drivetrain = NULL;
AnalogSensor *Robot::analogsensor = NULL;
//Elevator* Robot::elevator = NULL;
//Wrist* Robot::wrist = NULL;
//Claw* Robot::claw = NULL;
//
OI* Robot::oi = NULL;

void Robot::RobotInit() {
	drivetrain = new DriveTrain();
	analogsensor = new AnalogSensor();
//	elevator = new Elevator();
//	wrist = new Wrist();
//	claw = new Claw();
	oi = new OI();

	analogSensor = new UltraSonicSensor();
	autonomousCommand = new Autonomous();
//	lw = LiveWindow::GetInstance();
//
//    // Show what command your subsystem is running on the SmartDashboard
//    SmartDashboard::PutData(drivetrain);
//    SmartDashboard::PutData(elevator);
//    SmartDashboard::PutData(wrist);
//    SmartDashboard::PutData(claw);
}

void Robot::AutonomousInit() {
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
