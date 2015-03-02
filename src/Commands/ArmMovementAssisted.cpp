#include "ArmMovementAssisted.h"
#include "Robot.h"

ArmMovementAssisted::ArmMovementAssisted()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	//Requires(Robot::armsystem);

	/*Requires(Robot::ArmUpDown_LeftSide_Top);
	Requires(Robot::ArmUpDown_LeftSide_Bottom);
	Requires(Robot::ArmUpDown_RightSide_Top);
	Requires(Robot::ArmUpDown_RightSide_Bottom);
	Requires(Robot::ArmInOut_LeftSide_In);
	Requires(Robot::ArmInOut_LeftSide_Out);
	Requires(Robot::ArmInOut_RightSide_In);
	Requires(Robot::ArmInOut_RightSide_Out);*/
}

// Called just before this Command runs the first time
void ArmMovementAssisted::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArmMovementAssisted::Execute()
{
	Talon *rightup1 = Robot::armsystem->GetRight_up_down1();
	Talon *rightup2 = Robot::armsystem->GetRight_up_down2();
	Talon *leftup1 = Robot::armsystem->GetLeft_up_down1();
	Talon *leftup2 = Robot::armsystem->GetLeft_up_down1();

	Jaguar *rightin = Robot::armsystem->GetRight_in_out();
	Jaguar *leftin = Robot::armsystem->GetLeft_in_out();


	//top
	 if((Robot::LeftSide_Top->IsOn() == true) && (Robot::RightSide_Top->IsOn() == true))
	 {
		 leftup1->Set(0);
		 leftup2->Set(0);
		 rightup1->Set(0);
		 rightup2->Set(0);

	 }
	 else if((Robot::LeftSide_Top->IsOn() == true) && (Robot::RightSide_Top->IsOn() == false))
	 {
		 leftup1->Set(0);
		 leftup2->Set(0);
		 rightup1->Set(Robot::armsystem->GetDriveSpeed());
		 rightup2->Set(Robot::armsystem->GetDriveSpeed());
	 }
	 else if((Robot::LeftSide_Top->IsOn() == false) && (Robot::RightSide_Top->IsOn() == true))
	 {
		 leftup1->Set(Robot::armsystem->GetDriveSpeed());
		 leftup2->Set(Robot::armsystem->GetDriveSpeed());
		 rightup1->Set(0);
		 rightup2->Set(0);
	 }
	 else if((Robot::LeftSide_Top->IsOn() == false) && (Robot::RightSide_Top->IsOn() == false))
	 {
		 leftup1->Set(Robot::armsystem->GetDriveSpeed());
		 leftup2->Set(Robot::armsystem->GetDriveSpeed());
		 rightup1->Set(Robot::armsystem->GetDriveSpeed());
		 rightup2->Set(Robot::armsystem->GetDriveSpeed());
	 }
	 else{}

	 //bottom
	 if((Robot::LeftSide_Bottom->IsOn() == true) && (Robot::RightSide_Bottom->IsOn() == true))
	 {
		 leftup1->Set(0);
		 leftup2->Set(0);
		 rightup1->Set(0);
		 rightup2->Set(0);
	 }
	 else if((Robot::LeftSide_Bottom->IsOn() == true) && (Robot::RightSide_Bottom->IsOn() == false))
	 {
		 leftup1->Set(0);
		 leftup2->Set(0);
		 rightup1->Set(Robot::armsystem->GetDriveSpeed());
		 rightup2->Set(Robot::armsystem->GetDriveSpeed());
	 }
	 else if((Robot::LeftSide_Bottom->IsOn() == false) && (Robot::RightSide_Bottom->IsOn() == true))
	 {
		 leftup1->Set(Robot::armsystem->GetDriveSpeed());
		 leftup2->Set(Robot::armsystem->GetDriveSpeed());
		 rightup1->Set(0);
		 rightup2->Set(0);
	 }
	 else if((Robot::LeftSide_Bottom->IsOn() == false) && (Robot::RightSide_Bottom->IsOn() == false))
	 {
		 leftup1->Set(Robot::armsystem->GetDriveSpeed());
		 leftup2->Set(Robot::armsystem->GetDriveSpeed());
		 rightup1->Set(Robot::armsystem->GetDriveSpeed());
		 rightup2->Set(Robot::armsystem->GetDriveSpeed());
	 }
	 else{}

	 //in
	 if((Robot::LeftSide_Out->IsOn() == true) && (Robot::RightSide_Out->IsOn() == true))
	 {
		 leftin->Set(0);
		 rightin->Set(0);
	 }
	 else if((Robot::LeftSide_Out->IsOn() == true) && (Robot::RightSide_Out->IsOn() == false))
	 {
		 leftin->Set(0);
		 rightin->Set(Robot::armsystem->GetDriveSpeed());
	 }
	 else if((Robot::LeftSide_Out->IsOn() == false) && (Robot::RightSide_Out->IsOn() == true))
	 {
		 leftin->Set(Robot::armsystem->GetDriveSpeed());
		 rightin->Set(0);
	 }
	 else if((Robot::LeftSide_Out->IsOn() == false) && (Robot::RightSide_Out->IsOn() == false))
	 {
		 leftin->Set(Robot::armsystem->GetDriveSpeed());
		 rightin->Set(Robot::armsystem->GetDriveSpeed());
	 }
	 else{}

	 //out
	 if((Robot::LeftSide_In->IsOn() == true) && (Robot::RightSide_In->IsOn() == true))
	 {
		 leftin->Set(0);
		 rightin->Set(0);
	 }
	 else if((Robot::LeftSide_In->IsOn() == true) && (Robot::RightSide_In->IsOn() == false))
	 {
		 leftin->Set(0);
		 rightin->Set(Robot::armsystem->GetDriveSpeed());
	 }
	 else if((Robot::LeftSide_In->IsOn() == false) && (Robot::RightSide_In->IsOn() == true))
	 {
		 leftin->Set(Robot::armsystem->GetDriveSpeed());
		 rightin->Set(0);
	 }
	 else if((Robot::LeftSide_In->IsOn() == false) && (Robot::RightSide_In->IsOn() == false))
	 {
		 leftin->Set(Robot::armsystem->GetDriveSpeed());
		 rightin->Set(Robot::armsystem->GetDriveSpeed());
	 }
	 else{}
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMovementAssisted::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmMovementAssisted::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMovementAssisted::Interrupted()
{

}
