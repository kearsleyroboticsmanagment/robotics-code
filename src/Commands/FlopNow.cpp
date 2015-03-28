#include "FlopNow.h"
#include "Robot.h"
#include "OI.h"

FlopNow::FlopNow()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::floper);
	Robot::floper->FloperSpeed(0);
}

FlopNow::FlopNow(int direct)
{
	if (direct == (-1))
	{
		direction = direct;
		Robot::floper->FloperSpeed(-.5);
	}
	else if (direct == 1)
	{
		direction = direct;
		Robot::floper->FloperSpeed(.5);
	}
	else{}
}

// Called just before this Command runs the first time
void FlopNow::Initialize()
{
	//Robot::floper->FloperSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void FlopNow::Execute()
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
			//impossable unless messed up
		}
		else if (Robot::flopIn->GetCase() == false && Robot::flopOut->GetCase() == false)
		{
			//imbetween movements
			Robot::floper->MoveNow();
		}
		else{}
	Robot::floper->MoveNow();
}

// Make this return true when this Command no longer needs to run execute()
bool FlopNow::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FlopNow::End()
{
	Robot::floper->FloperSpeed(0);
	Robot::floper->MoveNow();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlopNow::Interrupted()
{
	End();
}
