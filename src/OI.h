#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	OI();
	Joystick* GetJoystickXY();
	Joystick* GetJoystickZ();
	Joystick* GetJoystickArm();

private:
	Joystick* joyxy;
	Joystick* joyz;
	Joystick* joyArm;
};

#endif
