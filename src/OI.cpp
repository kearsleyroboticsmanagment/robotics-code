#include "OI.h"
#include "Commands/FlopNow.h"
#include "Commands/WheelsMoveCommand.h"
#include "Robot.h"

//#include "Commands/OpenClaw.h"
//#include "Commands/CloseClaw.h"
//#include "Commands/PrepareToPickup.h"
//#include "Commands/Pickup.h"
//#include "Commands/Place.h"
//#include "Commands/Autonomous.h"

OI::OI() {
//	SmartDashboard::PutData("Open Claw", new OpenClaw());
//	SmartDashboard::PutData("Close Claw", new CloseClaw());

	joyxy= new Joystick(0);
	joyz= new Joystick(1);
	joyArm = new Joystick(2);

	//JoystickButton* flop_up = new JoystickButton(joyArm,6);
	//JoystickButton* flop_down = new JoystickButton(joyArm, 7);
	flop_up = new JoystickButton(joyxy, 4);
	flop_down = new JoystickButton(joyxy, 3);
	roll_in = new JoystickButton(joyArm, 7);
	roll_out = new JoystickButton(joyArm, 6);

	roll_in->WhenPressed(new WheelsMoveCommand());
	roll_out->WhenPressed(new WheelsMoveCommand());

	//flop_up->WhenPressed(new FlopNow(1));
	//flop_down->WhenPressed(new FlopNow(-1));
	SmartDashboard::PutBoolean("JOY BUTT 6",joyArm->GetRawButton(6));
	if (joyArm->GetRawButton(7) == true)
	{
		Robot::floper->SetDirection(1);
	}
	else{}

	if (joyArm->GetRawButton(6) == true)
	{
		Robot::floper->SetDirection(-1);
	}
	else{}
//    // Create some buttons
//    JoystickButton* d_up = new JoystickButton(joy, 5);
//    JoystickButton* d_right= new JoystickButton(joy, 6);
//    JoystickButton* d_down= new JoystickButton(joy, 7);
//    JoystickButton* d_left = new JoystickButton(joy, 8);
//    JoystickButton* l2 = new JoystickButton(joy, 9);
//    JoystickButton* r2 = new JoystickButton(joy, 10);
//    JoystickButton* l1 = new JoystickButton(joy, 11);
//    JoystickButton* r1 = new JoystickButton(joy, 12);
//
//    // Connect the buttons to commands
//    d_up->WhenPressed(new SetElevatorSetpoint(0.2));
//    d_down->WhenPressed(new SetElevatorSetpoint(-0.2));
//    d_right->WhenPressed(new CloseClaw());
//    d_left->WhenPressed(new OpenClaw());
//
//    r1->WhenPressed(new PrepareToPickup());
//    r2->WhenPressed(new Pickup());
//    l1->WhenPressed(new Place());
//    l2->WhenPressed(new Autonomous());
}


Joystick* OI::GetJoystickXY() {
	return joyxy;
}

Joystick* OI::GetJoystickZ() {
	return joyz;
}

Joystick* OI::GetJoystickArm(){
	return joyArm;
}

Button *OI::GetButtonFlopDown()
{
	return flop_down;
}

Button *OI::GetButtonFlopUp()
{
	return flop_up;
}

Button *OI::GetButtonRollIn()
{
	return roll_in;
}

Button *OI::GetButtonRollOut()
{
	return roll_out;
}

bool OI::GetButtonFlopUpPressed()
{
	return (flop_up->Get());
}

bool OI::GetButtonFlopDownPressed()
{
	return (flop_down->Get());
}

bool OI::GetRollInPressed()
{
	return roll_in->Get();
}

bool OI::GetRollOutPressed()
{
	return roll_out->Get();
}
