#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Commands/MecanumDriveWithJoystick.h"
#include "CANJaguar.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	front_left_motor = new CANJaguar(11);
	back_left_motor = new CANJaguar(12);
	front_right_motor = new CANJaguar(13);
	back_right_motor = new CANJaguar(14);

	front_left_motor->SetPercentMode(CANJaguar::QuadEncoder, 360);
	front_left_motor->EnableControl();
	front_left_motor->Set(0.0f);

	back_left_motor->SetPercentMode(CANJaguar::QuadEncoder, 360);
	back_left_motor->EnableControl();
	back_left_motor->Set(0.0f);

	front_right_motor->SetPercentMode(CANJaguar::QuadEncoder, 360);
	front_right_motor->EnableControl();
	front_right_motor->Set(0.0f);

	back_right_motor->SetPercentMode(CANJaguar::QuadEncoder, 360);
	back_right_motor->EnableControl();
	back_right_motor->Set(0.0f);

	/* auton?
	front_left_motor->SetPositionMode(CANJaguar::QuadEncoder, 360, 10.0f, 0.4f, 0.2f);
	front_left_motor->EnableControl();
	double setpoint;
	setpoint = front_left_motor->GetPosition() + 2.0f;
	front_left_motor->Set(setpoint);
	//*setpoint = NULL;
	//delete setpoint;

	back_left_motor->SetPositionMode(CANJaguar::QuadEncoder, 360, 10.0f, 0.4f, 0.2f);
	back_left_motor->EnableControl();
	//double *setpoint;
	setpoint = back_left_motor->GetPosition() + 2.0f;
	back_left_motor->Set(setpoint);
	//*setpoint = NULL;
	//delete setpoint;

	front_right_motor->SetPositionMode(CANJaguar::QuadEncoder, 360, 10.0f, 0.4f, 0.2f);
	front_right_motor->EnableControl();
	//double *setpoint;
	setpoint = front_left_motor->GetPosition() + 2.0f;
	front_right_motor->Set(setpoint);
	//*setpoint = NULL;
	//delete setpoint;

	back_right_motor->SetPositionMode(CANJaguar::QuadEncoder, 360, 10.0f, 0.4f, 0.2f);
	back_right_motor->EnableControl();
	//double *setpoint;
	setpoint = back_right_motor->GetPosition() + 2.0f;
	back_right_motor->Set(setpoint);
	//*setpoint = NULL;
	//delete setpoint;
	*/

	drive = new RobotDrive(front_left_motor, back_left_motor,
						   front_right_motor, back_right_motor);

	drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);	// invert the left side motors
	drive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);	// you may need to change or remove this to match your robot

	drive->SetSafetyEnabled(false);

//	left_encoder = new Encoder(1, 2);
//	right_encoder = new Encoder(3, 4);

	// Encoders may measure differently in the real world and in
	// simulation. In this example the robot moves 0.042 barleycorns
	// per tick in the real world, but the simulated encoders
	// simulate 360 tick encoders. This if statement allows for the
	// real robot to handle this difference in devices.
//	#ifdef REAL
//		left_encoder->SetDistancePerPulse(0.042);
//		right_encoder->SetDistancePerPulse(0.042);
//	#else
//		// Circumference in ft = 4in/12(in/ft)*PI
//		left_encoder->SetDistancePerPulse((double) (4.0/12.0*M_PI) / 360.0);
//		right_encoder->SetDistancePerPulse((double) (4.0/12.0*M_PI) / 360.0);
//	#endif
//
//	rangefinder = new AnalogInput(6);
//	gyro = new Gyro(1);

	// Let's show everything on the LiveWindow
	// TODO: LiveWindow::GetInstance()->AddActuator("Drive Train", "Front_Left Motor", (Talon) front_left_motor);
	// TODO: LiveWindow::GetInstance()->AddActuator("Drive Train", "Back Left Motor", (Talon) back_left_motor);
	// TODO: LiveWindow::GetInstance()->AddActuator("Drive Train", "Front Right Motor", (Talon) front_right_motor);
	// TODO: LiveWindow::GetInstance()->AddActuator("Drive Train", "Back Right Motor", (Talon) back_right_motor);
//	LiveWindow::GetInstance()->AddSensor("Drive Train", "Left Encoder", left_encoder);
//	LiveWindow::GetInstance()->AddSensor("Drive Train", "Right Encoder", right_encoder);
//	LiveWindow::GetInstance()->AddSensor("Drive Train", "Rangefinder", rangefinder);
//	LiveWindow::GetInstance()->AddSensor("Drive Train", "Gyro", gyro);
}

/**
 * When no other command is running let the operator drive around
 * using the PS3 joystick.
 */
void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new MecanumDriveWithJoystick());
}

/**
 * The log method puts interesting information to the SmartDashboard.
 */
//void DriveTrain::Log() {
//	SmartDashboard::PutNumber("Left Distance", left_encoder->GetDistance());
//	SmartDashboard::PutNumber("Right Distance", right_encoder->GetDistance());
//	SmartDashboard::PutNumber("Left Speed", left_encoder->GetRate());
//	SmartDashboard::PutNumber("Right Speed", right_encoder->GetRate());
//	SmartDashboard::PutNumber("Gyro", gyro->GetAngle());
//}

void DriveTrain::Drive(double x_in, double y_in, double z_in) {
	drive->MecanumDrive_Cartesian(x_in, y_in, z_in);
}

void DriveTrain::Drive(Joystick* joyxy, Joystick* joyz) {
	Drive(-(joyxy->GetX()),joyxy->GetY(), -(joyz->GetZ()));
}

void DriveTrain::GetStatus()
{
	SmartDashboard::PutNumber("Bus Voltage front left =",front_left_motor->GetBusVoltage());
	SmartDashboard::PutNumber("Bus Voltage front right =",back_right_motor->GetBusVoltage());
	SmartDashboard::PutNumber("Bus Voltage back left =",back_left_motor->GetBusVoltage());
	SmartDashboard::PutNumber("Bus Voltage back right =",back_right_motor->GetBusVoltage());

	SmartDashboard::PutNumber("Output Voltage front left =",front_left_motor->GetOutputVoltage());
	SmartDashboard::PutNumber("Output Voltage front right =",back_right_motor->GetOutputVoltage());
	SmartDashboard::PutNumber("Output Voltage back left =",back_left_motor->GetOutputVoltage());
	SmartDashboard::PutNumber("Output Voltage back right =",back_right_motor->GetOutputVoltage());

	SmartDashboard::PutNumber("Output Current front left =",front_left_motor->GetOutputCurrent());
	SmartDashboard::PutNumber("Output Current front right =",back_right_motor->GetOutputCurrent());
	SmartDashboard::PutNumber("Output Current back left =",back_left_motor->GetOutputCurrent());
	SmartDashboard::PutNumber("Output Current back right =",back_right_motor->GetOutputCurrent());

	SmartDashboard::PutNumber("Temp front left =",front_left_motor->GetTemperature());
	SmartDashboard::PutNumber("Temp front right =",back_right_motor->GetTemperature());
	SmartDashboard::PutNumber("Temp back left =",back_left_motor->GetTemperature());
	SmartDashboard::PutNumber("Temp back right =",back_right_motor->GetTemperature());
}
//
//double DriveTrain::GetHeading() {
//	return gyro->GetAngle();
//}
//
//void DriveTrain::Reset() {
//	gyro->Reset();
//	left_encoder->Reset();
//	right_encoder->Reset();
//}
//
//double DriveTrain::GetDistance() {
//	return (left_encoder->GetDistance() + right_encoder->GetDistance())/2;
//}
//
//double DriveTrain::GetDistanceToObstacle() {
//	// Really meters in simulation since it's a rangefinder...
//	return rangefinder->GetAverageVoltage();
//}
