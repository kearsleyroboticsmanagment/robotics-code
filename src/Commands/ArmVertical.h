#ifndef ArmVertical_H
#define ArmVertical_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmVertical: public CommandBase
{
public:
	ArmVertical();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
