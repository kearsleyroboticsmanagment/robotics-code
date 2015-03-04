#ifndef DriveForward_H
#define DriveForward_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveForward: public Command
{
public:
	bool isDone;
	DriveForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
