#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	OI();
	JoystickButton* fullSpeed;
	Joystick* GetJoystickXY();
	Joystick* GetJoystickZ();
	Joystick* GetJoyArm();
	bool GetSpeedButton();
	//Joystick* GetJoyArm2();

private:
	Joystick* joyxy;
	Joystick* joyz;
	Joystick* joyArm;
	//Joystick* joyArm2;
};

#endif
