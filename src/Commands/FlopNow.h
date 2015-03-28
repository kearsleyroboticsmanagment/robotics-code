#ifndef FlopNow_H
#define FlopNow_H

#include "../CommandBase.h"
#include "WPILib.h"

class FlopNow: public CommandBase
{
private:
	int direction = 0;
public:
	FlopNow();
	FlopNow(int direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
