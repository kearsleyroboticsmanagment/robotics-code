#ifndef FloperMovement_H
#define FloperMovement_H

#include "Commands/Subsystem.h"
#include "Commands/FlopNow.h"
#include "WPILib.h"

class FloperMovement: public Subsystem
{
private:
	Talon *fm1;
	int direction;
	float speed;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	FloperMovement();
	void InitDefaultCommand();
	void FloperSpeed(float speed);
	float FloperGetSpeed();
	void SetDirection(int direction_in);
	Talon *Getfm1();
};

#endif
