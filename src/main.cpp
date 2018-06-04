
#include <iostream>
#include <unistd.h>

#include "robot.hpp"
#include "settings.hpp"

#include <stdio.h>

#include "semantic/testing.h"

using namespace std;

// Принимает как аргумент файл двигателя и устройства с датчиками
//
int main(int argc, char* argv[])
{
//	test_semantic_node();
//	return 0;
	int fps = 20; // dunno why but it doesn't change the actual fps
	int opt = 0;
	//parsing command-line args
	setbuf(stdout, NULL);

//	while ((opt = getopt(argc, argv, "hf:")) != -1) {
//		switch (opt) {
//		case '?':
//		case 'h':
//			cout << "Opecv vision";
//			break;
//		case 'f':
//			fps = atoi(optarg);
//			cout << "framerate:" << fps << endl;
//			break;
//		default: /* '?' */
//			break;
//		}
//	}
	if(argc < 2){
		puts("Don't you forget to give me the sensor device file?");
		settings.setDistance_sensor_file("-");
	}
	else
		settings.setDistance_sensor_file(argv[2]);
	// const in this case means that the pointer won't be modifyed
	SociofillBehaviour behaviour;
	HavingAttention* const attentionControlled = new Mind(behaviour);
	Mind* const mind = (Mind*)attentionControlled;
	Vision* const vision = new Vision(fps);
	AttentionController* const attentionCtrl   = new AttentionController(*attentionControlled, *vision);
	DecisionPerformer* const decisionPerformer = new DebugPerformer();
	Robot robot(*mind, *attentionCtrl, *decisionPerformer);
	robot.startLifeCycle();

	return 0;
}

