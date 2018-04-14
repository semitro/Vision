
#include <iostream>
#include <unistd.h>

#include "robot.hpp"

#include <stdio.h>

#include "semantic/testing.h"

using namespace std;

int main(int argc, char* argv[])
{
	test_semantic_node();
	return 0;
	int fps = 20;
	int opt = 0;
	//parsing command-line args
	setbuf(stdout, NULL);

	while ((opt = getopt(argc, argv, "hf:")) != -1) {
		switch (opt) {
		case '?':
		case 'h':
			cout << "Opecv vision";
			break;
		case 'f':
			fps = atoi(optarg);
			cout << "framerate:" << fps << endl;
			break;
		default: /* '?' */
			break;
		}
	}

	Robot robot;
	robot.startLifeCycle();

	return 0;
}

