#ifndef WheelsMoveCommand_H
#define WheelsMoveCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class WheelsMoveCommand: public CommandBase
{
public:
	WheelsMoveCommand();
	WheelsMoveCommand(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
