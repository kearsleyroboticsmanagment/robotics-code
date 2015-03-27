#include "FlopNow.h"
#include "Robot.h"
#include "OI.h"

FlopNow::FlopNow()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::floper);
	fm1_copy = Robot::floper->Getfm1();
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
	bool flopuppressed;
	flopuppressed = Robot::oi->GetButtonFlopUpPressed();
	bool flopdownpressed;
	flopdownpressed = Robot::oi->GetButtonFlopUpPressed();
	if (flopuppressed == true)
	{
	if (Robot::flopIn->GetCase() == true && Robot::flopOut->GetCase() == false)
	{
		if (direction == (-1))
		{
			fm1_copy->Set(Robot::floper->FloperGetSpeed());
		}
	}
	else if (Robot::flopIn->GetCase() == false && Robot::flopOut->GetCase() == true)
	{
		if (direction == 1)
		{
			fm1_copy->Set(Robot::floper->FloperGetSpeed());
		}
	}
	else if (Robot::flopIn->GetCase() == true && Robot::flopOut->GetCase() == true)
	{
		//impossable unless messed up
	}
	else if (Robot::flopIn->GetCase() == false && Robot::flopOut->GetCase() == false)
	{
		//imbetween movements
		fm1_copy->Set(Robot::floper->FloperGetSpeed());
	}
	else{}
	}
	else{}

	if(flopdownpressed == true)
	{
		if (Robot::flopIn->GetCase() == true && Robot::flopOut->GetCase() == false)
		{
			if (direction == (-1))
			{
				fm1_copy->Set(Robot::floper->FloperGetSpeed());
			}
		}
		else if (Robot::flopIn->GetCase() == false && Robot::flopOut->GetCase() == true)
		{
			if (direction == 1)
			{
				fm1_copy->Set(Robot::floper->FloperGetSpeed());
			}
		}
		else if (Robot::flopIn->GetCase() == true && Robot::flopOut->GetCase() == true)
		{
			//impossable unless messed up
		}
		else if (Robot::flopIn->GetCase() == false && Robot::flopOut->GetCase() == false)
		{
			//imbetween movements
			fm1_copy->Set(Robot::floper->FloperGetSpeed());
		}
		else{}
	}
	else{}

}

// Make this return true when this Command no longer needs to run execute()
bool FlopNow::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FlopNow::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlopNow::Interrupted()
{

}
