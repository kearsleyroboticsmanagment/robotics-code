#include "DriveForward.h"
#include "Robot.h"

DriveForward::DriveForward() : Command("DriveForward")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain);
}

// Called just before this Command runs the first time
void DriveForward::Initialize()
{
	Robot::drivetrain->SetToPosition(); //front_left_motor->SetControlMode
	Robot::drivetrain->Reset();
	isDone = false;
	// set timeout to 1 sec
	//SetTimeout(1);
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute()
{
	Robot::drivetrain->SetDistance(3,3,3,3);
	isDone = true;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished()
{
	//return (IsTimedOut());
	return (isDone);
}

// Called once after isFinished returns true
void DriveForward::End()
{
	//Robot::drivetrain->Drive(0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted()
{
	End();
}
