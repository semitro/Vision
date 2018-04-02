#include "sightanalyser.hpp"

SightAnalyser::SightAnalyser(size_t framerate, String window_name)
	:face_detector("haarcascade_frontalface_default.xml"), capture(0),
	  window_name(window_name)
{
	capture.set(CAP_PROP_FPS, framerate);
	std::thread looking(&SightAnalyser::lookLoop, this);
	looking.detach(); // threads should work independly
}

void SightAnalyser::lookLoop()
{
	while(capture.read(current_frame)){
		faces = face_detector.detectObjects(current_frame);
		for(size_t i = 0; i < faces.size(); i++){
			cout << "I see a leather bastard #" << i << endl;
		}
		if(faces.size() == 0)
			cout << "I'm not seeing any human" << endl;
/*		if(window_name != ""){
			for ( size_t i = 0; i < faces.size(); i++ )
			{
//				Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
//				ellipse( current_frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360,
						 Scalar( 255, 0, 255 ), 4, 8, 0 );
			}
			waitKey(capture.get(CAP_PROP_FPS));
			imshow(window_name, current_frame );
		}*/
	}
}
