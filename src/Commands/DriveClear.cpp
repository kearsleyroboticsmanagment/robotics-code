#include "DriveClear.h"
#include "Robot.h"

DriveClear::DriveClear()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain);
}

// Called just before this Command runs the first time
void DriveClear::Initialize()
{
	SetTimeout(2.0);
}

// Called repeatedly when this Command is scheduled to run
void DriveClear::Execute()
{
	Robot::drivetrain->Drive(0,.5,0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveClear::IsFinished()
{
	return (IsTimedOut());
}

// Called once after isFinished returns true
void DriveClear::End()
{
	Robot::drivetrain->Drive(0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveClear::Interrupted()
{
	End();
}
