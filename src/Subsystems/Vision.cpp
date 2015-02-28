#include "Vision.h"
#include "../RobotMap.h"
#include "Commands/teleopVisionCommand.h"

Vision::Vision() : Subsystem("Vision")
{
	SmartDashboard::init();

	// create an image
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	binaryFrame = imaqCreateImage(IMAQ_IMAGE_U8, 0);
	//the camera name (ex "cam0") can be found through the roborio web interface
	imaqErrorINTERMEDIATE = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
	if(imaqErrorINTERMEDIATE != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqErrorINTERMEDIATE) + "\n");
	}
	imaqErrorINTERMEDIATE = IMAQdxConfigureGrab(session);
	if(imaqErrorINTERMEDIATE != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqErrorINTERMEDIATE) + "\n");
	}

	// pasted from retro vision file
	// create images
	//frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);

	//Put default values to SmartDashboard so fields will appear
	SmartDashboard::PutNumber("Tote hue min", RING_HUE_RANGE.minValue);
	SmartDashboard::PutNumber("Tote hue max", RING_HUE_RANGE.maxValue);
	SmartDashboard::PutNumber("Tote sat min", RING_SAT_RANGE.minValue);
	SmartDashboard::PutNumber("Tote sat max", RING_SAT_RANGE.maxValue);
	SmartDashboard::PutNumber("Tote val min", RING_VAL_RANGE.minValue);
	SmartDashboard::PutNumber("Tote val max", RING_VAL_RANGE.maxValue);
	SmartDashboard::PutNumber("Area min %", AREA_MINIMUM);
	// end paste from retro vision file
}

void Vision::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new teleopVisionCommand());
}

