#ifndef LimitSwitches_H
#define LimitSwitches_H

#include "../CommandBase.h"
#include "WPILib.h"

class LimitSwitches: public CommandBase
{
public:
	LimitSwitches();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
