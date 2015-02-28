#include "UltraSonicSensor.h"
//#include "Subsystems/AnalogSensor.h"
#include "Robot.h"

UltraSonicSensor::UltraSonicSensor()
{
	Requires(Robot::analogsensor);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void UltraSonicSensor::Initialize()
{
	//AnalogSensor *UltraSonicSensor;
}

// Called repeatedly when this Command is scheduled to run
void UltraSonicSensor::Execute()
{
	Robot::analogsensor->ReadDistance();
}

// Make this return true when this Command no longer needs to run execute()
bool UltraSonicSensor::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void UltraSonicSensor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UltraSonicSensor::Interrupted()
{

}
