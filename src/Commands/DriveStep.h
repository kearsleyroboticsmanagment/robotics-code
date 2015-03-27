#ifndef DriveStep_H
#define DriveStep_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveStep: public CommandBase
{
public:
	DriveStep();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
