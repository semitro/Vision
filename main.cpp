#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat frame;
	namedWindow("Hello cv", WINDOW_NORMAL);
	VideoCapture capture(0); // from standart camera
	while(true){
		capture.read(frame);
		imshow("Hello cv", frame);
		waitKey(0);
	}
	waitKey(0);

	return 0;
}
