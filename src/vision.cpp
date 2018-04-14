#include "vision.hpp"

Vision::Vision(size_t framerate, String window_name)
	:face_detector("haarcascade_frontalface_default.xml"), capture(0),
	  window_name(window_name)
{
	capture.set(CAP_PROP_FPS, framerate);
	std::thread looking(&Vision::lookLoop, this);
	looking.detach(); // threads should work independly
}

void Vision::lookLoop()
{
	while(capture.read(current_frame)){
		faces = face_detector.detectObjects(current_frame);
		sight_corrector.count(faces.size());
		#ifdef GUI_MODE // Вывод в экран для отладки. На pi нет экрана.
		if(window_name != ""){
			for ( size_t i = 0; i < faces.size(); i++ )
			{
				Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
				ellipse( current_frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
			}
			waitKey(capture.get(CAP_PROP_FPS));
			imshow(window_name, current_frame );
		}
		#endif // GUI_MODE
	}
}

size_t Vision::howManyFaces(){
	return (size_t)sight_corrector.getValue();
}
