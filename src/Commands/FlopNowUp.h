#ifndef FlopNowUp_H
#define FlopNowUp_H

#include "../CommandBase.h"
#include "WPILib.h"

class FlopNowUp: public CommandBase
{
private:
	Talon *fm1_copy;
	int direction = 0;
public:
	FlopNowUp();
	FlopNowUp(int direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
