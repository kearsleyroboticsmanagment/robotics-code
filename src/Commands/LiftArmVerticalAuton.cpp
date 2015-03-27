#include "LiftArmVerticalAuton.h"
#include "Robot.h"

LiftArmVerticalAuton::LiftArmVerticalAuton() : Command("LiftArmVerticalAuton")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::arm);
}

// Called just before this Command runs the first time
void LiftArmVerticalAuton::Initialize()
{
	SetTimeout(2.5);
}

// Called repeatedly when this Command is scheduled to run
void LiftArmVerticalAuton::Execute()
{
	Robot::arm->SetVertical(-.5);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftArmVerticalAuton::IsFinished()
{
	return (IsTimedOut());
}

// Called once after isFinished returns true
void LiftArmVerticalAuton::End()
{
	Robot::arm->SetVertical(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftArmVerticalAuton::Interrupted()
{
	End();
}
