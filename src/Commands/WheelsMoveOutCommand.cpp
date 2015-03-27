#include "WheelsMoveOutCommand.h"
#include "Robot.h"

WheelsMoveOutCommand::WheelsMoveOutCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

WheelsMoveOutCommand::WheelsMoveOutCommand(float speed)
{
	Robot::rollers->SetSpeed(speed);
}

// Called just before this Command runs the first time
void WheelsMoveOutCommand::Initialize()
{
	Robot::rollers->SetSpeed(.25);
}

// Called repeatedly when this Command is scheduled to run
void WheelsMoveOutCommand::Execute()
{
	Robot::rollers->MoveNow();
}

// Make this return true when this Command no longer needs to run execute()
bool WheelsMoveOutCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WheelsMoveOutCommand::End()
{
	Robot::rollers->SetSpeed(0);
	Robot::rollers->MoveNow();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WheelsMoveOutCommand::Interrupted()
{
	End();
}
