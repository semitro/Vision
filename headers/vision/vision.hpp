#ifndef SIGHTANALYSER_H
#define SIGHTANALYSER_H

#include <thread>
#include <unistd.h> // for usleep

#include "objectdetector.hpp"
#include "opencv2/videoio/videoio.hpp"

#include "sightcorrector.hpp"

#define GUI_MODE
//#undef  GUI_MODE

#ifdef GUI_MODE
#include "opencv2/highgui.hpp"
#endif

// microseconds
#define SLEEPING_IN_DETECTING_LOOP 5000

using std::thread;

// The vision
class Vision
{
public:
	//window - the name of the window where to show what's going on
	//"" - don't show pictures, just analyse
	Vision(size_t framerate=24, String window_name="s");
	size_t howManyFaces();

private:
	void lookLoop();  // Sight fetch an image form the camera circle
	void detectLoop(); // Sight detecting objects circle
	ObjectDetector face_detector;
	SightCorrector sight_corrector;
	VideoCapture capture;
	Mat current_frame;
	String window_name; // Выводить ли на экран, что происходит
	std::vector<Rect> faces;

	bool it_s_time_to_detect = false; // Используется в потоке смотрения и детектирования.
									  // Смотритель говорит, что уже считал следующий кадр
};

#endif // SIGHTANALYSER_H
