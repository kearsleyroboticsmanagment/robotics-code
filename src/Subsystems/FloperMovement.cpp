#include "FloperMovement.h"
#include "../RobotMap.h"

FloperMovement::FloperMovement() :
		Subsystem("FloperMovement")
{
	fm1 = new Talon(4);
}

void FloperMovement::FloperSpeed(float speed_in)
{
	speed = speed_in;
}

float FloperMovement::FloperGetSpeed()
{
	return speed;
}

Talon *FloperMovement::Getfm1()
{
	return fm1;
}

void FloperMovement::SetDirection(int direction_in)
{
	direction = direction_in;
}

void FloperMovement::InitDefaultCommand()
{
	SetDefaultCommand(new FlopNow());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
