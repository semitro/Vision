#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>

#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

#include "objectdetector.hpp"

using namespace std;
using namespace cv;

//CascadeClassifier eyes_cascade;
void detectFace(Mat frame);

int main(int argc, char** argv)
{
	Mat frame;
	ObjectDetector *detector;

	try{
		detector = new ObjectDetector("haarcascade_frontalface_default.xml");
	}catch(std::ios_base::failure &exception){
		cerr << "Can't load haarcascade_frontalface_default.xml" << endl;
		return 1;
	}


	namedWindow("Hello cv", WINDOW_NORMAL);
	VideoCapture capture(0); // from standart camera
	while(capture.read(frame)){
		capture.read(frame);
		imshow("Hello cv", frame);
		std::vector<Rect> faces = detector->detectFaces(frame);
		for ( size_t i = 0; i < faces.size(); i++ )
		{
			Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
			ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
		}

		imshow( "Hello cv", frame );
		waitKey(0);
	}

	return 0;
}

