#ifndef FlopNowDown_H
#define FlopNowDown_H

#include "../CommandBase.h"
#include "WPILib.h"

class FlopNowDown: public CommandBase
{
private:
	Talon *fm1_copy;
	int direction = 0;
public:
	FlopNowDown();
	FlopNowDown(int direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
