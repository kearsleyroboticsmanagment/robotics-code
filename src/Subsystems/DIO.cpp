#include "DIO.h"
#include "Commands/LimitSwitches.h"
#include "../RobotMap.h"
#include <string>

DIO::DIO():Subsystem("DIO")
{
	port_num = 10;
	//limit_switch_1 = new DigitalInput(10);
	port_set = false;
}

DIO::DIO(int y):Subsystem("DIO")
{
	port_num = y;
	limit_switch_1 = new DigitalInput(port_num);
	port_set = true;
}

void DIO::InitDefaultCommand()
{
	SetDefaultCommand(new LimitSwitches());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void DIO::SetPort(int y, std::string nameIn)
{
	if (port_set == false)
	{
		limit_switch_1 = new DigitalInput(y);
		port_num = y;
	}
	else{}
	name = nameIn;

}

void DIO::IsOn()
{
	if (limit_switch_1->Get() == 1)
	{
		SmartDashboard::PutBoolean(name, false);
		on = true;
	}
	else
	{
		SmartDashboard::PutBoolean(name, true);
		on = false;
	}
}

void DIO::IsOff()
{
	if (limit_switch_1->Get() == 1)
	{
		SmartDashboard::PutBoolean(name, true);
		on = true;
	}
	else
	{
		SmartDashboard::PutBoolean(name, false);
		on = true;
	}
}

bool DIO::GetCase()
{
	return on;
}
