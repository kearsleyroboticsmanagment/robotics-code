#include "DriveBackward.h"
#include "Robot.h"

DriveBackward::DriveBackward() : Command("DriveBackward")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain);
}

// Called just before this Command runs the first time
void DriveBackward::Initialize()
{
	// set timeout to 1 sec
	SetTimeout(2.25);
}

// Called repeatedly when this Command is scheduled to run
void DriveBackward::Execute()
{
	Robot::drivetrain->Drive(0,-(.5),0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveBackward::IsFinished()
{
	return (IsTimedOut());
}

// Called once after isFinished returns true
void DriveBackward::End()
{
	Robot::drivetrain->Drive(0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveBackward::Interrupted()
{
	End();
}
