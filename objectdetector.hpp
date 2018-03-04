#ifndef OBJECTDETECTOR_HPP
#define OBJECTDETECTOR_HPP

#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;

// detect object on a frame
class ObjectDetector
{

public:
	ObjectDetector(const String neural_network_file);
	std::vector<Rect> detectObjects(Mat frame);
private:
	CascadeClassifier classifier;
};

#endif // OBJECTDETECTOR_HPP
