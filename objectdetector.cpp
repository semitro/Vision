#include "objectdetector.hpp"
#include <iostream>

ObjectDetector::ObjectDetector(const String neural_network_file)
{
	if(!face_cascade.load(neural_network_file))
		throw std::ios_base::failure("Cannot load File" + neural_network_file);
}



std::vector<Rect> ObjectDetector::detectFaces(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray; // dunno why, it's just from an example
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);
	//-- Detect faces
	face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(60, 60) );
	return faces;
}
