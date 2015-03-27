#ifndef LiftArmVerticalAuton_H
#define LiftArmVerticalAuton_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftArmVerticalAuton: public Command
{
public:
	LiftArmVerticalAuton();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
