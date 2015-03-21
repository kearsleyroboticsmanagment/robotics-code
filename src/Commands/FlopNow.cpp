#include "FlopNow.h"
#include "Robot.h"

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
	if (Robot::flopIn->IsOn() == true && Robot::flopOut->IsOn() == false)
	{
		if (direction == (-1))
		{
			fm1_copy->Set(Robot::floper->FloperGetSpeed());
		}
	}
	else if (Robot::flopIn->IsOn() == false && Robot::flopOut->IsOn() == true)
	{
		if (direction == 1)
		{
			fm1_copy->Set(Robot::floper->FloperGetSpeed());
		}
	}
	else if (Robot::flopIn->IsOn() == true && Robot::flopOut->IsOn() == true)
	{
		//impossable unless messed up
	}
	else if (Robot::flopIn->IsOn() == false && Robot::flopOut->IsOn() == false)
	{
		//imbetween movements
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
