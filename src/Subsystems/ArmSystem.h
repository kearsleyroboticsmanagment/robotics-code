#ifndef ArmSystem_H
#define ArmSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ArmSystem: public Subsystem
{
private:
	Talon *Left_up_down_1, *Left_up_down_2, *Right_up_down_1, *Right_up_down_2, *Left_in_out, *Right_in_out;
	float drive_speed;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ArmSystem();
	ArmSystem(int bypass);
	float MoveY(float drive_speed); //makes movement on the y-axis --- returns the adjusted y value
	float MoveX(float drive_speed); //makes movement on the x-axis --- returns the adjusted x value
	float MoveYSecondary(float drive_speed);//for second joystick
	float MoveXSecondary(float drive_speed);//for second joystick
	float GetDriveSpeed();
	Talon *GetLeft_up_down1();
	Talon *GetLeft_up_down2();
	Talon *GetRight_up_down1();
	Talon *GetRight_up_down2();
	Talon *GetLeft_in_out();
	Talon *GetRight_in_out();
	void InitDefaultCommand();
};

#endif
