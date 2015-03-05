#include "ArmVertical.h"
#include "Robot.h"

ArmVertical::ArmVertical()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::arm);
}

// Called just before this Command runs the first time
void ArmVertical::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArmVertical::Execute()
{
	Robot::arm->SetVertical(Robot::oi->GetJoyArm());
}

// Make this return true when this Command no longer needs to run execute()
bool ArmVertical::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmVertical::End()
{
	Robot::arm->SetVertical(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmVertical::Interrupted()
{
	End();
}
