#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include <unistd.h>

#include "vision/vision.hpp"
#include "mind.hpp"
#include "decision_performer.hpp"
#include "attention_controller.hpp"

// Убрать ли в другое место?
#define FRAMERATE 24
#define WINDOW_NAME "MainWindow"

using namespace std;
// The main organella
class Robot
{
public:
	// Компонентно-ориентированное программирование
	Robot(const Vision &visio, const AttentionController& attentionController,
		  const DecisionPerformer &performer);
	void startLifeCycle();
private:
	Robot();
	Mind   mind;
	const AttentionController& attentionController;
	const DecisionPerformer&   decisionPerformer;
};

#endif // ROBOT_HPP
