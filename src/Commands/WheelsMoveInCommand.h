#ifndef WheelsMoveInCommand_H
#define WheelsMoveInCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class WheelsMoveInCommand: public CommandBase
{
public:
	WheelsMoveInCommand();
	WheelsMoveInCommand(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
