#ifndef AnalogSensor_H
#define AnalogSensor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class AnalogSensor: public Subsystem
{
private:
	AnalogInput *MaxSonar_EZ1;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	AnalogSensor();
	void InitDefaultCommand();
	void ReadDistance();
};

#endif
