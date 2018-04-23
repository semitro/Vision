#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include <unistd.h>

#include "vision/vision.hpp"
#include "mind.hpp"
#include "decision_performer.hpp"

// Убрать ли в другое место?
#define FRAMERATE 24
#define WINDOW_NAME "MainWindow"

using namespace std;
// The main organella
class Robot
{
public:
	Robot(const DecisionPerformer &performer);
	void startLifeCycle();
private:
	Vision vision; //
	Mind   mind;
	const DecisionPerformer& decisionPerformer;
};

#endif // ROBOT_HPP
