#ifndef UltraSonicSensor_H
#define UltraSonicSensor_H

#include "../CommandBase.h"
#include "WPILib.h"

class UltraSonicSensor: public CommandBase
{
public:
	UltraSonicSensor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
