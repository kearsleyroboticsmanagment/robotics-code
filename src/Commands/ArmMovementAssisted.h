#ifndef ArmMovementAssisted_H
#define ArmMovementAssisted_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmMovementAssisted: public CommandBase
{
public:
	ArmMovementAssisted();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
