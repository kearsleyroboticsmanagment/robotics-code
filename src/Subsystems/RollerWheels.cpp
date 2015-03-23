#include "RollerWheels.h"
#include "Commands/WheelsMoveCommand.h"
#include "../RobotMap.h"

RollerWheels::RollerWheels() :
		Subsystem("wheel movement")
{
	rollerMotor = new Talon(6);
}

void RollerWheels::SetSpeed(float speed_in)
{
	speed = speed_in;
}

void RollerWheels::MoveNow()
{
	rollerMotor->Set(speed);
}

void RollerWheels::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new WheelsMoveCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
