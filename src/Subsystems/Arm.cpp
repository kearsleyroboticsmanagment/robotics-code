#include "Arm.h"
#include "../RobotMap.h"
#include "Robot.h"
#include "Commands/ArmVertical.h"
#include "CANJaguar.h"

Arm::Arm() :
		Subsystem("Arm")
{
	isFullSpeed = false;

//	FL = new CANJaguar(12);
//	BL = new CANJaguar( );
//	FR = new CANJaguar( );
//	BR = new CANJaguar( );

	FL = new Jaguar(0);
	BL = new Jaguar(1);
	FR = new Jaguar(2);
	BR = new Jaguar(3);

//	FR->SetPercentMode();
//	FR->EnableControl();
//
//	BL->SetPercentMode();
//	BL->EnableControl();
//
//	FR->SetPercentMode();
//	FR->EnableControl();
//
//	BR->SetPercentMode();
//	BR->EnableControl();

//	FL = new Talon(2);
//	BL = new Talon(3);
//	FR = new Talon(0);
//	BR = new Talon(1);

}

void Arm::SetVertical(double power){
	FL->Set(-power);
	BL->Set(-power);
	FR->Set(power);
	BR->Set(power);
}


//unless only full speed is pressed, it will go to half-speed
void Arm::SetVertical(Joystick* joyArm_in){
	double power = 0;
	double powerL = 0;
	double powerR = 0;
	if(isFullSpeed == true){
		//power = joyArm_in->GetY();
		power = powerL = powerR = -(joyArm_in->GetY());
	}
	else{
		//power = (joyArm_in->GetY())/2;
		powerL = powerR = -(joyArm_in->GetY());
	}
//	if((!(FL->GetForwardLimitOK())) && power <= 0){
//		//power = 0;
//		powerL = 0;
//	}
//	if((!(FL->GetReverseLimitOK())) && power >= 0){
//		//power = 0;
//		powerL = 0;
//	}
//	if((!(FR->GetForwardLimitOK())) && power >= 0){
//		//power = 0;
//		powerR = 0;
//	}
//	if((!(FR->GetReverseLimitOK())) && power <= 0){
//		//power = 0;
//		powerR = 0;
//	}
//	double power = (joyArm_in->GetY())/2;
	FL->Set(-powerL);
	BL->Set(-powerL);
	FR->Set(powerR);
	BR->Set(powerR);
}
void Arm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ArmVertical);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
