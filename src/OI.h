#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	OI();
	Joystick* GetJoystickXY();
	Joystick* GetJoystickZ();
	Joystick* GetJoystickArm();
	Button *GetButtonFlopUp();
	Button *GetButtonFlopDown();
	bool GetButtonFlopUpPressed();
	bool GetButtonFlopDownPressed();

private:
	Joystick* joyxy;
	Joystick* joyz;
	Joystick* joyArm;
	Button* flop_up;
	Button* flop_down;
};

#endif
