#ifndef DIO_H
#define DIO_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <string>

class DIO: public Subsystem
{
private:
	DigitalInput *limit_switch_1;
	int port_num;
	std::string name;
	bool port_set;
	bool on;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DIO();
	DIO(int y);
	void InitDefaultCommand();
	void SetPort(int x, std::string name);
	void IsOn();
	void IsOff();
	bool GetCase();
};

#endif
