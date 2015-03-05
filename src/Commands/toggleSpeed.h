#ifndef toggleSpeed_H
#define toggleSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class toggleSpeed: public CommandBase
{
public:
	toggleSpeed();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
