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
	Button *GetButtonRollIn();
	Button *GetButtonRollOut();
	bool GetButtonFlopUpPressed();
	bool GetButtonFlopDownPressed();
	bool GetRollInPressed();
	bool GetRollOutPressed();

private:
	Joystick* joyxy;
	Joystick* joyz;
	Joystick* joyArm;
	Button* flop_up;
	Button* flop_down;
	Button* roll_in;
	Button* roll_out;
};

#endif
