#include "DriveStep.h"
#include "Robot.h"

DriveStep::DriveStep()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain);
}

// Called just before this Command runs the first time
void DriveStep::Initialize()
{
	SetTimeout(2.25);
}

// Called repeatedly when this Command is scheduled to run
void DriveStep::Execute()
{
	Robot::drivetrain->Drive(0,.7,0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStep::IsFinished()
{
	return (IsTimedOut());
}

// Called once after isFinished returns true
void DriveStep::End()
{
	Robot::drivetrain->Drive(0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStep::Interrupted()
{
	End();
}
