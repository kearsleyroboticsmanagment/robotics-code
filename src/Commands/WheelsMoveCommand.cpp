#include "WheelsMoveCommand.h"
#include "Robot.h"

WheelsMoveCommand::WheelsMoveCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

WheelsMoveCommand::WheelsMoveCommand(float speed)
{
	Robot::rollers->SetSpeed(speed);
}

// Called just before this Command runs the first time
void WheelsMoveCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WheelsMoveCommand::Execute()
{
	Robot::rollers->MoveNow();
}

// Make this return true when this Command no longer needs to run execute()
bool WheelsMoveCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WheelsMoveCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WheelsMoveCommand::Interrupted()
{

}
