#ifndef teleopVisionCommand_H
#define teleopVisionCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class teleopVisionCommand: public Command
{
public:
	teleopVisionCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
