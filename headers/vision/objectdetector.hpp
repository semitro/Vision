#ifndef OBJECTDETECTOR_HPP
#define OBJECTDETECTOR_HPP

#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

#include <vector>

using namespace cv;
using std::vector;

// detect object on a frame
class ObjectDetector
{

public:
	ObjectDetector(const String neural_network_file);
	vector<Rect> detectObjects(const Mat &frame);
private:
	CascadeClassifier classifier;
};

#endif // OBJECTDETECTOR_HPP
