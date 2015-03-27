#include "WheelsMoveInCommand.h"
#include "Robot.h"

WheelsMoveInCommand::WheelsMoveInCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

WheelsMoveInCommand::WheelsMoveInCommand(float speed)
{
	Robot::rollers->SetSpeed(speed);
}

// Called just before this Command runs the first time
void WheelsMoveInCommand::Initialize()
{
	Robot::rollers->SetSpeed(-.5);
}

// Called repeatedly when this Command is scheduled to run
void WheelsMoveInCommand::Execute()
{
	Robot::rollers->MoveNow();
}

// Make this return true when this Command no longer needs to run execute()
bool WheelsMoveInCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WheelsMoveInCommand::End()
{
	Robot::rollers->SetSpeed(0);
	Robot::rollers->MoveNow();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WheelsMoveInCommand::Interrupted()
{
	End();
}
