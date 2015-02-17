#include "ArmSystem.h"
#include "../RobotMap.h"
#include "Commands/ArmUp_down.h"
#include "Robot.h"

ArmSystem::ArmSystem() :Subsystem("ArmSystem")
{
	Left_up_down_1 = new Talon(2);
	Left_up_down_2 = new Talon(3);
	Right_up_down_1 = new Talon(1);
	Right_up_down_2 = new Talon(0);
}

void ArmSystem::MoveY()
{
	float y;
	Joystick *joy = Robot::oi->GetArmJoystick();
	y = joy->GetY();
	//SmartDashboard::PutNumber("ATTACK 3 Y VALUE: ", y);
	Left_up_down_1->Set((y/2));
	Left_up_down_2->Set((y/2));
	Right_up_down_1->Set((y/2));
	Right_up_down_2->Set((y/2));
}

void ArmSystem::MoveX()
{
	float x;
	Joystick *joy = Robot::oi->GetArmJoystick();
	x = joy->GetX();
	Left_up_down_1->Set((x/2));
	Left_up_down_2->Set((x/2));
	Right_up_down_1->Set((x/2));
	Right_up_down_2->Set((x/2));
}

void ArmSystem::InitDefaultCommand()
{
	SetDefaultCommand(new ArmUp_Down());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
