#ifndef ArmUp_Down_H
#define ArmUp_Down_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmUp_Down: public CommandBase
{
public:
	ArmUp_Down();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
