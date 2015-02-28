#include "LimitSwitches.h"
//#include "Subsystems/DIO.h"
#include "Robot.h"

LimitSwitches::LimitSwitches()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::LimitSwitch1);
}

// Called just before this Command runs the first time
void LimitSwitches::Initialize()
{
	//Robot::LimitSwitch1->SetPort();
}

// Called repeatedly when this Command is scheduled to run
void LimitSwitches::Execute()
{
	Robot::LimitSwitch1->IsOn();
}

// Make this return true when this Command no longer needs to run execute()
bool LimitSwitches::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LimitSwitches::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LimitSwitches::Interrupted()
{

}
