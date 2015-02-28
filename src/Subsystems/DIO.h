#ifndef DIO_H
#define DIO_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <string>

class DIO: public Subsystem
{
private:
	DigitalInput *limit_switch_1;
	int x;
	std::string name;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DIO();
	void InitDefaultCommand();
	void SetPort(int x, std::string name);
	bool IsOn();
	bool IsOff();
};

#endif
