#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include <unistd.h>

#include "vision/vision.hpp"
#include "mind.hpp"
#include "decision_performer.hpp"
#include "attention_controller.hpp"

// Убрать ли в другое место?
#define FRAMERATE 2
#define WINDOW_NAME "MainWindow"

using namespace std;
// The main organella
class Robot
{
public:
	// Компонентно-ориентированное программирование
	// Mind - должен быть тот же, что и у AttentionController
	Robot(Mind &mind, AttentionController& attentionController,
		  DecisionPerformer &performer);
	void startLifeCycle() const;
private:
	Robot();
	AttentionController& attentionController;
	Mind  &mind;
	DecisionPerformer&   decisionPerformer;
};

#endif // ROBOT_HPP
