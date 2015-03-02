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
	Left_in_out = new Jaguar(4);
	Right_in_out = new Jaguar(5);
}

ArmSystem::ArmSystem(int bypass):Subsystem("ArmSystem")
{

}

float ArmSystem::MoveY(float drive_speed)
{
	float y;
	Joystick *joy = Robot::oi->GetArmJoystick();
	y = joy->GetY();
	y *= drive_speed;
	//SmartDashboard::PutNumber("ATTACK 3 Y VALUE: ", y);
	/*Left_up_down_1->Set(-y);
	Left_up_down_2->Set(-y);
	Right_up_down_1->Set(y);
	Right_up_down_2->Set(y);
	*/
	return y;
}

float ArmSystem::MoveX(float drive_speed)
{
	float x;
	Joystick *joy = Robot::oi->GetArmJoystick();
	x = joy->GetX();
	x *= drive_speed;
	/*Left_up_down_1->Set(x);
	Left_up_down_2->Set(x);
	Right_up_down_1->Set(x);
	Right_up_down_2->Set(x);
	*/
	return x;
}

float ArmSystem::MoveYSecondary(float drive_speed)
{
	float y;
	Joystick *joy = Robot::oi->GetArmJoystick2();
	y = joy->GetY();
	y *= drive_speed;
	//SmartDashboard::PutNumber("ATTACK 3 Y VALUE: ", y);
	/*Left_up_down_1->Set(-y);
	Left_up_down_2->Set(-y);
	Right_up_down_1->Set(y);
	Right_up_down_2->Set(y);
	*/
	return y;
}

float ArmSystem::MoveXSecondary(float drive_speed)
{
	float x;
	Joystick *joy = Robot::oi->GetArmJoystick2();
	x = joy->GetX();
	x *= drive_speed;
	/*Left_up_down_1->Set(x);
	Left_up_down_2->Set(x);
	Right_up_down_1->Set(x);
	Right_up_down_2->Set(x);
	*/
	return x;
}

Talon *ArmSystem::GetLeft_up_down1()
{
	return Left_up_down_1;
}

Talon *ArmSystem::GetLeft_up_down2()
{
	return Left_up_down_2;
}

Talon *ArmSystem::GetRight_up_down1()
{
	return Right_up_down_1;
}

Talon *ArmSystem::GetRight_up_down2()
{
	return Right_up_down_2;
}

Jaguar *ArmSystem::GetLeft_in_out()
{
	return Left_in_out;
}

Jaguar *ArmSystem::GetRight_in_out()
{
	return Right_in_out;
}

float ArmSystem::GetDriveSpeed()
{
	return drive_speed;
}

void ArmSystem::InitDefaultCommand()
{
	SetDefaultCommand(new ArmUp_Down());
	//SetDefaultCommand(new ArmMovementAssisted());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
