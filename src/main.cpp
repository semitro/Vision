
#include <iostream>
#include <unistd.h>

#include "robot.hpp"

#include <stdio.h>

#include "semantic/testing.h"

using namespace std;

// Принимает как аргумент файл двигателя и устройства с датчиками
//
int main(int argc, char* argv[])
{
//	test_semantic_node();
//	return 0;
	int fps = 20;
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

	const HavingAttention* mind = new Mind();
	const Vision* vision = new Vision();
	const AttentionController*  attentionCtrl = new AttentionController(*mind, *vision);
	Robot robot(*new DebugPerformer(), );
	robot.startLifeCycle();

	return 0;
}

