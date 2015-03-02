#include "LimitSwitches.h"
//#include "Subsystems/DIO.h"
#include "Robot.h"

LimitSwitches::LimitSwitches()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::LeftSide_Top);
	Requires(Robot::LeftSide_Bottom);
	Requires(Robot::RightSide_Top);
	Requires(Robot::RightSide_Bottom);
	Requires(Robot::LeftSide_In);
	Requires(Robot::LeftSide_Out);
	Requires(Robot::RightSide_In);
	Requires(Robot::RightSide_Out);
}


// Called just before this Command runs the first time
void LimitSwitches::Initialize()
{
	//Robot::LimitSwitch1->SetPort();
}

// Called repeatedly when this Command is scheduled to run
void LimitSwitches::Execute()
{
	Robot::LeftSide_Top->IsOn();
	Robot::LeftSide_Bottom->IsOn();
	Robot::RightSide_Top->IsOn();
	Robot::RightSide_Bottom->IsOn();
	Robot::LeftSide_In->IsOn();
	Robot::LeftSide_Out->IsOn();
	Robot::RightSide_In->IsOn();
	Robot::RightSide_Out->IsOn();
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
