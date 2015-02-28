#include "AutonVisionCommand.h"
#include "Robot.h"
#include "Subsystems/Vision.h"
#include <vector>
#include <cmath>

AutonVisionCommand::AutonVisionCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::vision);
}

// Called just before this Command runs the first time
void AutonVisionCommand::Initialize()
{
	IMAQdxStartAcquisition(Robot::vision->session);
}

// Called repeatedly when this Command is scheduled to run
void AutonVisionCommand::Execute()
{
	//read file in from disk. For this example to run you need to copy image.jpg from the SampleImages folder to the
	//directory shown below using FTP or SFTP: http://wpilib.screenstepslive.com/s/4485/m/24166/l/282299-roborio-ftp
	//Robot::vision->imaqError = imaqReadFile(Robot::vision->frame, "//home//lvuser//SampleImages//image.jpg", NULL, NULL);

	//Update threshold values from SmartDashboard. For performance reasons it is recommended to remove this after calibration is finished.
	Robot::vision->RING_HUE_RANGE.minValue = SmartDashboard::GetNumber("Tote hue min", Robot::vision->RING_HUE_RANGE.minValue);
	Robot::vision->RING_HUE_RANGE.maxValue = SmartDashboard::GetNumber("Tote hue max", Robot::vision->RING_HUE_RANGE.maxValue);
	Robot::vision->RING_SAT_RANGE.minValue = SmartDashboard::GetNumber("Tote sat min", Robot::vision->RING_SAT_RANGE.minValue);
	Robot::vision->RING_SAT_RANGE.maxValue = SmartDashboard::GetNumber("Tote sat max", Robot::vision->RING_SAT_RANGE.maxValue);
	Robot::vision->RING_VAL_RANGE.minValue = SmartDashboard::GetNumber("Tote val min", Robot::vision->RING_VAL_RANGE.minValue);
	Robot::vision->RING_VAL_RANGE.maxValue = SmartDashboard::GetNumber("Tote val max", Robot::vision->RING_VAL_RANGE.maxValue);

	//Threshold the image looking for ring light color
	Robot::vision->imaqError = imaqColorThreshold(Robot::vision->binaryFrame, Robot::vision->frame, 255, IMAQ_HSV, &(Robot::vision->RING_HUE_RANGE), &(Robot::vision->RING_SAT_RANGE), &(Robot::vision->RING_VAL_RANGE));

	//Send particle count to dashboard
	int numParticles = 0;
	Robot::vision->imaqError = imaqCountParticles(Robot::vision->binaryFrame, 1, &numParticles);
	SmartDashboard::PutNumber("Masked particles", numParticles);

	//Send masked image to dashboard to assist in tweaking mask.
	//IMAQdxGrab(Robot::vision->session, Robot::vision->binaryFrame, true, NULL);
	Robot::vision->SendToDashboard(Robot::vision->binaryFrame, Robot::vision->imaqError);
	//Robot::vision->SendToDashboard(Robot::vision->frame, Robot::vision->imaqError);

//	if(Robot::vision->imaqErrorINTERMEDIATE != IMAQdxErrorSuccess) {
//		DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)Robot::vision->imaqErrorINTERMEDIATE) + "\n");
//	} else {
//		CameraServer::GetInstance()->SetImage(Robot::vision->binaryFrame);
//	}

	//filter out small particles
	float areaMin = SmartDashboard::GetNumber("Area min %", Robot::vision->AREA_MINIMUM);
	Robot::vision->criteria[0] = {IMAQ_MT_AREA_BY_IMAGE_AREA, areaMin, 100, false, false};
	Robot::vision->imaqError = imaqParticleFilter4(Robot::vision->binaryFrame, Robot::vision->binaryFrame, Robot::vision->criteria, 1, &Robot::vision->filterOptions, NULL, NULL);

	//Send particle count after filtering to dashboard
	Robot::vision->imaqError = imaqCountParticles(Robot::vision->binaryFrame, 1, &numParticles);
	SmartDashboard::PutNumber("Filtered particles", numParticles);

	if(numParticles > 0) {
		//Measure particles and sort by particle size
		std::vector<Vision::ParticleReport> particles;
		for(int particleIndex = 0; particleIndex < numParticles; particleIndex++)
		{
			Vision::ParticleReport par;
			imaqMeasureParticle(Robot::vision->binaryFrame, particleIndex, 0, IMAQ_MT_AREA_BY_IMAGE_AREA, &(par.PercentAreaToImageArea));
			imaqMeasureParticle(Robot::vision->binaryFrame, particleIndex, 0, IMAQ_MT_AREA, &(par.Area));
			imaqMeasureParticle(Robot::vision->binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_TOP, &(par.BoundingRectTop));
			imaqMeasureParticle(Robot::vision->binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_LEFT, &(par.BoundingRectLeft));
			imaqMeasureParticle(Robot::vision->binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_BOTTOM, &(par.BoundingRectBottom));
			imaqMeasureParticle(Robot::vision->binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_RIGHT, &(par.BoundingRectRight));
			particles.push_back(par);
		}
		sort(particles.begin(), particles.end(), Robot::vision->CompareParticleSizes);

		//This example only scores the largest particle. Extending to score all particles and choosing the desired one is left as an exercise
		//for the reader. Note that this scores and reports information about a single particle (single L shaped target). To get accurate information
		//about the location of the tote (not just the distance) you will need to correlate two adjacent targets in order to find the true center of the tote.
		Robot::vision->scores.Aspect = Robot::vision->AspectScore(particles.at(0));
		SmartDashboard::PutNumber("Aspect", Robot::vision->scores.Aspect);
		Robot::vision->scores.Area = Robot::vision->AreaScore(particles.at(0));
		SmartDashboard::PutNumber("Area", Robot::vision->scores.Area);
		bool isTarget = Robot::vision->scores.Area > Robot::vision->SCORE_MIN && Robot::vision->scores.Aspect > Robot::vision->SCORE_MIN;

		//Send distance and tote status to dashboard. The bounding rect, particularly the horizontal center (left - right) may be useful for rotating/driving towards a tote
		SmartDashboard::PutBoolean("IsTarget", isTarget);
		SmartDashboard::PutNumber("Distance", Robot::vision->computeDistance(Robot::vision->binaryFrame, particles.at(0)));
	} else {
		SmartDashboard::PutBoolean("IsTarget", false);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool AutonVisionCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonVisionCommand::End()
{
	IMAQdxStopAcquisition(Robot::vision->session);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonVisionCommand::Interrupted()
{
	End();
}
