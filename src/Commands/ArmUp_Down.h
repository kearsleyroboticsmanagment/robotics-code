#ifndef ArmUp_Down_H
#define ArmUp_Down_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmUp_Down: public CommandBase
{
private:
	float drive_speed;
public:
	ArmUp_Down();
	ArmUp_Down(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
