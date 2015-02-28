#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Vision: public Subsystem
{
public:
	//Pasted from intermediate vision
		IMAQdxSession session;
		Image *frame;
		IMAQdxError imaqErrorINTERMEDIATE;

		// pasted from retro vision file
		//A structure to hold measurements of a particle
			struct ParticleReport {
				double PercentAreaToImageArea;
				double Area;
				double BoundingRectLeft;
				double BoundingRectTop;
				double BoundingRectRight;
				double BoundingRectBottom;
			};

			//Structure to represent the scores for the various tests used for target identification
			struct Scores {
				double Area;
				double Aspect;
			};

			//Images
			//Image *frame;
			Image *binaryFrame;
			int imaqError;

			//Constants
			Range RING_HUE_RANGE = {101, 64};	//Default hue range for ring light
			Range RING_SAT_RANGE = {88, 255};	//Default saturation range for ring light
			Range RING_VAL_RANGE = {134, 255};	//Default value range for ring light
			double AREA_MINIMUM = 0.5; //Default Area minimum for particle as a percentage of total image area
			double LONG_RATIO = 2.22; //Tote long side = 26.9 / Tote height = 12.1 = 2.22
			double SHORT_RATIO = 1.4; //Tote short side = 16.9 / Tote height = 12.1 = 1.4
			double SCORE_MIN = 75.0;  //Minimum score to be considered a tote
			double VIEW_ANGLE = 60; //View angle fo camera, set to Axis m1011 by default, 64 for m1013, 51.7 for 206, 52 for HD3000 square, 60 for HD3000 640x480
			ParticleFilterCriteria2 criteria[1];
			ParticleFilterOptions2 filterOptions = {0,0,1,1};
			Scores scores;
		// end paste of retro vision

	Vision();
	void InitDefaultCommand();
	// Put methods for controlling this subsystem
	// here. Call these from Commands.

	// pasted from retro vision file
	//Send image to dashboard if IMAQ has not thrown an error
	void SendToDashboard(Image *image, int error)
	{
		if(error < ERR_SUCCESS) {
			DriverStation::ReportError("Send To Dashboard error: " + std::to_string((long)imaqError) + "\n");
		} else {
			CameraServer::GetInstance()->SetImage(binaryFrame);
		}
	}

	//Comparator function for sorting particles. Returns true if particle 1 is larger
	static bool CompareParticleSizes(ParticleReport particle1, ParticleReport particle2)
	{
		//we want descending sort order
		return particle1.PercentAreaToImageArea > particle2.PercentAreaToImageArea;
	}

	/**
	 * Converts a ratio with ideal value of 1 to a score. The resulting function is piecewise
	 * linear going from (0,0) to (1,100) to (2,0) and is 0 for all inputs outside the range 0-2
	 */
	double ratioToScore(double ratio)
	{
		return (fmax(0, fmin(100*(1-fabs(1-ratio)), 100)));
	}


	double AreaScore(ParticleReport report)
	{
		double boundingArea = (report.BoundingRectBottom - report.BoundingRectTop) * (report.BoundingRectRight - report.BoundingRectLeft);
		//Tape is 7" edge so 49" bounding rect. With 2" wide tape it covers 24" of the rect.
		return ratioToScore((49/24)*report.Area/boundingArea);
	}

	/**
	 * Method to score if the aspect ratio of the particle appears to match the retro-reflective target. Target is 7"x7" so aspect should be 1
	 */
	double AspectScore(ParticleReport report)
	{
		return ratioToScore(((report.BoundingRectRight-report.BoundingRectLeft)/(report.BoundingRectBottom-report.BoundingRectTop)));
	}


	/**
	 * Computes the estimated distance to a target using the width of the particle in the image. For more information and graphics
	 * showing the math behind this approach see the Vision Processing section of the ScreenStepsLive documentation.
	 *
	 * @param image The image to use for measuring the particle estimated rectangle
	 * @param report The Particle Analysis Report for the particle
	 * @return The estimated distance to the target in feet.
	 */
	double computeDistance (Image *image, ParticleReport report) {
		double normalizedWidth, targetWidth;
		int xRes, yRes;

		imaqGetImageSize(image, &xRes, &yRes);
		normalizedWidth = 2*(report.BoundingRectRight - report.BoundingRectLeft)/xRes;
		SmartDashboard::PutNumber("Width", normalizedWidth);
		targetWidth = 7;

		return  targetWidth/(normalizedWidth*12*tan(VIEW_ANGLE*M_PI/(180*2)));
	}


};

#endif
