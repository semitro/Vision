#ifndef SIGHTANALYSER_H
#define SIGHTANALYSER_H

#include <thread>

#include "objectdetector.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/highgui.hpp"

class SightAnalyser
{
public:
	//window - the name of the window where to show what's going on
	//"" - don't show pictures, just analyse
	SightAnalyser(size_t framerate=24, String window_name="");
	virtual ~SightAnalyser();

private:
	void lookLoop(); // Sight circle

	ObjectDetector face_detector;
	VideoCapture capture;
	Mat current_frame;
	String window_name; // Выводить ли на экран, что происходит
	std::vector<Rect> faces;
};

#endif // SIGHTANALYSER_H
