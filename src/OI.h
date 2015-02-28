#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	OI();
	Joystick* GetJoystickXY();
	Joystick* GetJoystickZ();
	Joystick *GetArmJoystick();

private:
	Joystick* joyxy;
	Joystick* joyz;
	Joystick *armjoystick;
};

#endif
