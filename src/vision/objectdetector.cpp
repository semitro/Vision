#include "vision/objectdetector.hpp"

ObjectDetector::ObjectDetector(const String neural_network_file)
{
	if(!classifier.load(neural_network_file))
		throw std::ios_base::failure("Cannot load File" + neural_network_file);
}


vector<Rect> ObjectDetector::detectObjects(const Mat& frame)
{
	vector<Rect> objects;
	Mat frame_gray; // dunno why, it's just from an example
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);
	//-- Detecting
	classifier.detectMultiScale( frame_gray, objects, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(60, 60) );
	return objects;
}
