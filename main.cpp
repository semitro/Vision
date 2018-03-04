#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>

#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

#include "objectdetector.hpp"
#include "sightanalyser.hpp"

using namespace std;
using namespace cv;

//CascadeClassifier eyes_cascade;
void detectFace(Mat frame);

int main(int argc, char** argv)
{
	SightAnalyser sightAnalyser(24, "MainWindow");

	while(1){
		cout << "hello\n";

	}
	return 0;
}

