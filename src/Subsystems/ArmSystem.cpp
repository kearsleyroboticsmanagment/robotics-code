#include "ArmSystem.h"
#include "../RobotMap.h"
#include "Commands/ArmUp_down.h"
#include "Robot.h"

ArmSystem::ArmSystem():Subsystem("ArmSystem")
{
	Left_up_down_1 = new Talon(2);
	Left_up_down_2 = new Talon(3);
	Right_up_down_1 = new Talon(1);
	Right_up_down_2 = new Talon(0);
}

void ArmSystem::MoveY(float drive_speed)
{
	float y;
	Joystick *joy = Robot::oi->GetArmJoystick();
	y = joy->GetY();
	y *= drive_speed;
	//SmartDashboard::PutNumber("ATTACK 3 Y VALUE: ", y);
	Left_up_down_1->Set(-y);
	Left_up_down_2->Set(-y);
	Right_up_down_1->Set(y);
	Right_up_down_2->Set(y);
}

void ArmSystem::MoveX(float drive_speed)
{
	float x;
	Joystick *joy = Robot::oi->GetArmJoystick();
	x = joy->GetX();
	x *= drive_speed;
	Left_up_down_1->Set(x);
	Left_up_down_2->Set(x);
	Right_up_down_1->Set(x);
	Right_up_down_2->Set(x);
}

void ArmSystem::InitDefaultCommand()
{
	SetDefaultCommand(new ArmUp_Down());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
