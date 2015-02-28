#include "teleopVisionCommand.h"
#include "Robot.h"

teleopVisionCommand::teleopVisionCommand() : Command("teleopVisionCommand")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::vision);
}

// Called just before this Command runs the first time
void teleopVisionCommand::Initialize()
{
	IMAQdxStartAcquisition(Robot::vision->session);
}

// Called repeatedly when this Command is scheduled to run
void teleopVisionCommand::Execute()
{
	// grab an image, draw the circle, and provide it for the camera server which will
	// in turn send it to the dashboard.
	IMAQdxGrab(Robot::vision->session, Robot::vision->frame, true, NULL);
	if(Robot::vision->imaqErrorINTERMEDIATE != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)Robot::vision->imaqErrorINTERMEDIATE) + "\n");
	} else {
		imaqDrawShapeOnImage(Robot::vision->frame, Robot::vision->frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
		CameraServer::GetInstance()->SetImage(Robot::vision->frame);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool teleopVisionCommand::IsFinished()
{
	return (false);
}

// Called once after isFinished returns true
void teleopVisionCommand::End()
{
	IMAQdxStopAcquisition(Robot::vision->session);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void teleopVisionCommand::Interrupted()
{
	End();
}
