#include "decision_performer.hpp"


void SillyPerformer::perform(Decision decision){

	decision.getAction();
}

// it's funny, but a virtual destructor must have a body in C++
DecisionPerformer::~DecisionPerformer(){}

void DebugPerformer::perform(Decision decision){
	cout << "Выполняю действие '" << decision.getAction().getName() <<
			"'. Причина: " + decision.getReason() << endl;
}
