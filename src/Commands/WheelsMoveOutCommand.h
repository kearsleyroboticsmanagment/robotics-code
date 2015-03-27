#ifndef WheelsMoveOutCommand_H
#define WheelsMoveOutCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class WheelsMoveOutCommand: public CommandBase
{
public:
	WheelsMoveOutCommand();
	WheelsMoveOutCommand(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
