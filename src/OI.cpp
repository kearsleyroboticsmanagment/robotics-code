#include "OI.h"
#include "Commands/ArmUp_Down.h"

//#include "Commands/SetElevatorSetpoint.h"
//#include "Commands/OpenClaw.h"
//#include "Commands/CloseClaw.h"
//#include "Commands/PrepareToPickup.h"
//#include "Commands/Pickup.h"
//#include "Commands/Place.h"
//#include "Commands/Autonomous.h"

OI::OI() {
//	SmartDashboard::PutData("Open Claw", new OpenClaw());
//	SmartDashboard::PutData("Close Claw", new CloseClaw());

	joyxy = new Joystick(2);
	joyz = new Joystick(1);
	armjoystick = new Joystick(0);


//    // Create some buttons
    JoystickButton* half_speed = new JoystickButton(armjoystick, 2);
    JoystickButton* full_speed = new JoystickButton(armjoystick, 3);
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
//    d_right->WhSenPressed(new CloseClaw());
//    d_left->WhenPressed(new OpenClaw());
    full_speed->ToggleWhenPressed(new ArmUp_Down(1));
	half_speed->ToggleWhenPressed(new ArmUp_Down(.5));
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

Joystick *OI::GetArmJoystick()
{
	return armjoystick;
}
