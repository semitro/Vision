#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include <unistd.h>

#include "vision.hpp"

// Убрать ли в другое место?
#define FRAMERATE 24
#define WINDOW_NAME "MainWindow"

using namespace std;
// The main organella
class Robot
{
public:
	Robot();
	void startLifeCycle();
private:
	Vision vision;
};

#endif // ROBOT_HPP
