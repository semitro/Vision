#ifndef OBJECTDETECTOR_HPP
#define OBJECTDETECTOR_HPP

#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;

class ObjectDetector
{

public:
	ObjectDetector(const String neural_network_file);
	std::vector<Rect> detectFaces(Mat frame);
private:
	CascadeClassifier face_cascade;
};

#endif // OBJECTDETECTOR_HPP
