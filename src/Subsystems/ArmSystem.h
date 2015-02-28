#ifndef ArmSystem_H
#define ArmSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ArmSystem: public Subsystem
{
private:
	Talon *Left_up_down_1, *Left_up_down_2, *Right_up_down_1, *Right_up_down_2;
	float drive_speed;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ArmSystem();
	void MoveY(float drive_speed); //makes movement on the y-axis
	void MoveX(float drive_speed); //makes movement on the x-axis
	void InitDefaultCommand();
};

#endif
