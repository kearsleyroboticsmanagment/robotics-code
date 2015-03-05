#include "Arm.h"
#include "../RobotMap.h"
#include "Commands/ArmVertical.h"
#include "Commands/toggleSpeed.h"

Arm::Arm() :
		Subsystem("ExampleSubsystem")
{
	isFullSpeed = false;

	FL = new CANJaguar(15);
	BL = new CANJaguar(16);
	FR = new CANJaguar(17);
	BR = new CANJaguar(18);

	FR->SetPercentMode();
	FR->EnableControl();

	BL->SetPercentMode();
	BL->EnableControl();

	FR->SetPercentMode();
	FR->EnableControl();

	BR->SetPercentMode();
	BR->EnableControl();

}

void Arm::SetVertical(double power){
	FL->Set(power);
	BL->Set(power);
	FR->Set(-power);
	BR->Set(-power);
}


//unless only full speed is pressed, it will go to half-speed
void Arm::SetVertical(Joystick* joyArm_in){
	double power = 0;
	if(isFullSpeed == true){
		power = joyArm_in->GetY();
	}
	else{
		power = (joyArm_in->GetY())/2;
	}
	if((!(FL->GetForwardLimitOK())) && power >= 0){
		power = 0;
	}
	if((!(FL->GetReverseLimitOK())) && power <= 0){
		power = 0;
	}
	FL->Set(power);
	BL->Set(power);
	FR->Set(-power);
	BR->Set(-power);
}

void Arm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
