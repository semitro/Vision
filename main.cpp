#include <iostream>
#include <unistd.h>

#include "objectdetector.hpp"
#include "sightanalyser.hpp"

#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
	int fps = 20;
	int opt = 0;
	//parsing command-line args
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

	SightAnalyser sightAnalyser(fps, "MainWindow");
	setbuf(stdout, NULL);
	while(1){
		puts("@s2@");
		switch (sightAnalyser.howManyFaces()) {
		case 0:
			puts("Everything is clear\n");
			puts("@mw@");
			cerr << 0 << endl;
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
//		cout.flush();
		usleep(620000 + random() % 8200);
	}
	return 0;
}

