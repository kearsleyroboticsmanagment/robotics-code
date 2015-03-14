#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arm: public Subsystem
{
private:
	//CANJaguar *FL, *BL, *FR, *BR;
	Jaguar *FL, *BL, *FR, *BR;
//	Talon *FL, *BL, *FR, *BR;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Arm();
	bool isFullSpeed;
	void InitDefaultCommand();
	void SetVertical(double scale);
	void SetVertical(Joystick* joyArm_in);
	//void setVertical2(double power);
	bool GetDriveSpeed();
};

#endif
