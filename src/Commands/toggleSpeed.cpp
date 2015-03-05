#include "toggleSpeed.h"
#include "Robot.h"

toggleSpeed::toggleSpeed()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void toggleSpeed::Initialize()
{
	Robot::arm->isFullSpeed=false;
}

// Called repeatedly when this Command is scheduled to run
void toggleSpeed::Execute()
{
	Robot::arm->isFullSpeed=true;
}

// Make this return true when this Command no longer needs to run execute()
bool toggleSpeed::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void toggleSpeed::End()
{
	Robot::arm->isFullSpeed=false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void toggleSpeed::Interrupted()
{
	End();
}
