#ifndef DISTANCE_HPP
#define DISTANCE_HPP

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <thread>
#include "settings.hpp"

using std::thread;

class DistanceSensor{
public:
	enum Which_Sensor{
		FRONT
	};
	DistanceSensor();
	int getDistance(Which_Sensor sensor_num);
	void turn_on();
	void turn_off(); // to economy the enegry
private:
	int distance_front;
	bool is_on;
	void requsest_loop();
	void read_loop();
	int sensor_file;
};
#endif
