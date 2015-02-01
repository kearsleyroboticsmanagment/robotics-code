#ifndef MecanumDriveWithJoystick_H
#define MecanumDriveWithJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class MecanumDriveWithJoystick: public Command
{
public:
	MecanumDriveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
