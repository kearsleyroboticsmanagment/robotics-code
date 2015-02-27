#include "LimitSwitches.h"
//#include "Subsystems/DIO.h"
#include "Robot.h"

LimitSwitches::LimitSwitches()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::ArmUpDown_LeftSide_Top);
	Requires(Robot::ArmUpDown_LeftSide_Bottom);
	Requires(Robot::ArmUpDown_RightSide_Top);
	Requires(Robot::ArmUpDown_RightSide_Bottom);
	Requires(Robot::ArmInOut_LeftSide_In);
	Requires(Robot::ArmInOut_LeftSide_Out);
	Requires(Robot::ArmInOut_RightSide_In);
	Requires(Robot::ArmInOut_RightSide_Out);
}


// Called just before this Command runs the first time
void LimitSwitches::Initialize()
{
	//Robot::LimitSwitch1->SetPort();
}

// Called repeatedly when this Command is scheduled to run
void LimitSwitches::Execute()
{
	Robot::ArmUpDown_LeftSide_Top->IsOn();
	Robot::ArmUpDown_LeftSide_Bottom->IsOn();
	Robot::ArmUpDown_RightSide_Top->IsOn();
	Robot::ArmUpDown_RightSide_Bottom->IsOn();
	Robot::ArmInOut_LeftSide_In->IsOn();
	Robot::ArmInOut_LeftSide_Out->IsOn();
	Robot::ArmInOut_RightSide_In->IsOn();
	Robot::ArmInOut_RightSide_Out->IsOn();
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
