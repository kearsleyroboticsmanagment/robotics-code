#ifndef DriveClear_H
#define DriveClear_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveClear: public Command
{
public:
	DriveClear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
