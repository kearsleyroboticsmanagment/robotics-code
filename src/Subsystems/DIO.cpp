#include "DIO.h"
#include "Commands/LimitSwitches.h"
#include "../RobotMap.h"
#include <string>

DIO::DIO():Subsystem("ExampleSubsystem")
{
	x = 10;
	limit_switch_1 = new DigitalInput(10);
}

void DIO::InitDefaultCommand()
{
	SetDefaultCommand(new LimitSwitches());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void DIO::SetPort(int y, std::string nameIn)
{
	limit_switch_1 = new DigitalInput(y);
	x = y;
	name = nameIn;
}

bool DIO::IsOn()
{
	if (limit_switch_1->Get() == 1)
	{
		SmartDashboard::PutBoolean(name, false);
		return true;
	}
	else
	{
		SmartDashboard::PutBoolean(name, true);
		return false;
	}
}

bool DIO::IsOff()
{
	if (limit_switch_1->Get() == 1)
	{
		SmartDashboard::PutBoolean(name, true);
		return false;
	}
	else
	{
		SmartDashboard::PutBoolean(name, false);
		return true;
	}
}
