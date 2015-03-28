#ifndef DriveBackward_H
#define DriveBackward_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveBackward: public Command
{
public:
	DriveBackward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
