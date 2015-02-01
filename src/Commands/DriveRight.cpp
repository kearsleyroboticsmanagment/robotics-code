#include "DriveRight.h"
#include "Robot.h"

DriveRight::DriveRight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain);
}

// Called just before this Command runs the first time
void DriveRight::Initialize()
{
	SetTimeout(1);
}

// Called repeatedly when this Command is scheduled to run
void DriveRight::Execute()
{
	Robot::drivetrain->Drive(.75,0,0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveRight::IsFinished()
{
	return (IsTimedOut());
}

// Called once after isFinished returns true
void DriveRight::End()
{
	Robot::drivetrain->Drive(0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveRight::Interrupted()
{
	End();
}
