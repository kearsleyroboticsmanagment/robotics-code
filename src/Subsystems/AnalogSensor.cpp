#include "AnalogSensor.h"
#include "Commands/UltraSonicSensor.h"
#include "../RobotMap.h"
#define ANALOG_RANGE_FINDER_DEFAULT_INCHES_PER_MV  0.1024F

AnalogSensor::AnalogSensor():Subsystem("ExampleSubsystem")
{
	MaxSonar_EZ1 = new AnalogInput(3);
	AnalogInput::SetSampleRate(2);
}

void AnalogSensor::InitDefaultCommand()
{
	SetDefaultCommand(new UltraSonicSensor());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void AnalogSensor::ReadDistance()
{
	//voltage pushed / 512 = scale factor
	//to find distance, range = measured volt / scale
	//double voltage;
	double voltage_ret;
	double distance;
	double inch_per_milivolt;
	//scale = (MaxSonar_EZ1->GetVoltage() / 512);
	inch_per_milivolt = ANALOG_RANGE_FINDER_DEFAULT_INCHES_PER_MV;
	voltage_ret = MaxSonar_EZ1->GetVoltage();
	//voltage = MaxSonar_EZ1->GetAverageVoltage();
	distance = (voltage_ret * inch_per_milivolt) * 1000;
	SmartDashboard::PutNumber("Distance Value", distance);
}
