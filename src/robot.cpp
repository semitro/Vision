#include "robot.hpp"


Robot::Robot(const DecisionPerformer &performer):
	vision(FRAMERATE, WINDOW_NAME),
	decisionPerformer(performer)

{

}

void Robot::startLifeCycle(){
//	mind.makeDesition();
	mind.makeDesition();
//	mind.payAttention();
	vision.howManyFaces()
	while(1){
		puts("@s2@");
		switch (vision.howManyFaces()) {
		case 0:
			puts("Everything is clear\n");
			puts("@mw@");
			break;
		case 1:
//			puts("I see a leather bastard\n");
			cerr << "I see a leather bastard" << endl;
			puts("@mx@");
			break;
		case 2:
//			puts("I see two fucking humans\n");
			puts("@s3md@");

			cerr << "Two stupid people I see" << endl;
			break;
		default:
			cerr << "Too many people around" << endl;
			puts("@mx@");
			break;
		}

		usleep(620000 + random() % 8200);
	}
}
