#include "ArmUp_Down.h"
#include "Robot.h"

ArmUp_Down::ArmUp_Down()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::armsystem);
	drive_speed = .5;
}

ArmUp_Down::ArmUp_Down(float speed)
{
	Requires(Robot::armsystem);
	drive_speed = speed;
}

// Called just before this Command runs the first time
void ArmUp_Down::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArmUp_Down::Execute()
{
	Robot::armsystem->MoveY(drive_speed);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmUp_Down::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmUp_Down::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmUp_Down::Interrupted()
{

}
