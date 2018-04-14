#ifndef SIGHTANALYSER_H
#define SIGHTANALYSER_H

#include <thread>

#include "objectdetector.hpp"
#include "opencv2/videoio/videoio.hpp"

#include "sightcorrector.hpp"

#define GUI_MODE
#undef  GUI_MODE

#ifdef GUI_MODE
#include "opencv2/highgui.hpp"
#endif

// The vision
class Vision
{
public:
	//window - the name of the window where to show what's going on
	//"" - don't show pictures, just analyse
	Vision(size_t framerate=24, String window_name="");
	size_t howManyFaces();

private:
	void lookLoop(); // Sight circle

	ObjectDetector face_detector;
	SightCorrector sight_corrector;
	VideoCapture capture;
	Mat current_frame;
	String window_name; // Выводить ли на экран, что происходит
	std::vector<Rect> faces;
};

#endif // SIGHTANALYSER_H
