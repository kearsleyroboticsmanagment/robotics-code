#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	OI();
	Joystick* GetJoystickXY();
	Joystick* GetJoystickZ();

private:
	Joystick* joyxy;
	Joystick* joyz;
};

#endif
