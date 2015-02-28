#ifndef AutonVisionCommand_H
#define AutonVisionCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonVisionCommand: public Command
{
public:
	AutonVisionCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
