#ifndef RollerWheels_H
#define RollerWheels_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class RollerWheels: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon *rollerMotor;
	float speed;
public:
	RollerWheels();
	void InitDefaultCommand();
	void SetSpeed(float speed_in);
	void MoveNow();
};

#endif
