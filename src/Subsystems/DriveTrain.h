#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem
{
private:
	CANJaguar *front_left_motor,  *back_left_motor,
					*front_right_motor, *back_right_motor;
	RobotDrive* drive;
//	Encoder *left_encoder, *right_encoder;
//	AnalogInput* rangefinder;
//	Gyro* gyro;

public:
	DriveTrain();

	/**
	 * When no other command is running let the operator drive around
	 * using the PS3 joystick.
	 */
	void InitDefaultCommand();

	/**
	 * The log method puts interesting information to the SmartDashboard.
	 */
//	void Log();
//
//	/**
//	 * Tank style driving for the DriveTrain.
//	 * @param left Speed in range [-1,1]
//	 * @param right Speed in range [-1,1]
//	 */
void Drive(double x_in, double y_in, double z_in);
//
//	/**
//	 * @param joy The ps3 style joystick to use to drive tank style.
//	 */
	void Drive(Joystick* joyxy, Joystick* joyz);
//
//	/**
//	 * @return The robots heading in degrees.
//	 */
//	double GetHeading();
//
//	/**
//	 * Reset the robots sensors to the zero states.
//	 */
//	void Reset();
//
//	/**
//	 * @return The distance driven (average of left and right encoders).
//	 */
//	double GetDistance();
//
//	/**
//	 * @return The distance to the obstacle detected by the rangefinder.
//	 */
//	double GetDistanceToObstacle();
//};
};

#endif
