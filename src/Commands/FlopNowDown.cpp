#include "FlopNowDown.h"
#include "Robot.h"
#include "OI.h"

FlopNowDown::FlopNowDown()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::floper);
	Robot::floper->FloperSpeed(-.25);
	direction = -1;
}

FlopNowDown::FlopNowDown(int direct)
{
	if (direct == (-1))
	{
		direction = direct;
		Robot::floper->FloperSpeed(-.25);
	}
	else if (direct == 1)
	{
		direction = direct;
		Robot::floper->FloperSpeed(.25);
	}
	else{}
}

// Called just before this Command runs the first time
void FlopNowDown::Initialize()
{
	//Robot::floper->FloperSpeed(0);
	Robot::floper->FloperSpeed(-.25);
	direction = -1;
}

// Called repeatedly when this Command is scheduled to run
void FlopNowDown::Execute()
{
	if (Robot::flopIn->GetCase() == true && Robot::flopOut->GetCase() == false)
	{
		if (direction == (-1))
		{
		Robot::floper->MoveNow();
		}
	}
	else if (Robot::flopIn->GetCase() == false && Robot::flopOut->GetCase() == true)
	{
		if (direction == 1)
		{
			Robot::floper->MoveNow();
		}
	}
	else if (Robot::flopIn->GetCase() == true && Robot::flopOut->GetCase() == true)
	{
		//imbetween movements
		Robot::floper->MoveNow();
	}
	else if (Robot::flopIn->GetCase() == false && Robot::flopOut->GetCase() == false)
	{
		//impossable unless messed up
	}
	else{}
	//Robot::floper->MoveNow();
}

// Make this return true when this Command no longer needs to run execute()
bool FlopNowDown::IsFinished()
{
	return !(Robot::flopIn->GetCase());
}

// Called once after isFinished returns true
void FlopNowDown::End()
{
	Robot::floper->FloperSpeed(0);
	Robot::floper->MoveNow();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlopNowDown::Interrupted()
{
	End();
}
