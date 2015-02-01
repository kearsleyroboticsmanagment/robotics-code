#ifndef DriveRight_H
#define DriveRight_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveRight: public CommandBase
{
public:
	DriveRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
