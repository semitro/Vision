#include "decision_performer.hpp"


DecisionPerformer::DecisionPerformer(){

}
void RealPerformer::perform(Decision decision){
//	decision.getAction();
}

// it's funny, but a virtual destructor must have a body in C++
DecisionPerformer::~DecisionPerformer(){}

void DebugPerformer::perform(Decision decision){
	cerr << "Выполняю действие '" << decision.getAction().getName() <<
			"'. Причина: " + decision.getReason() << endl;
	if(decision.getAction().getName() == "change direction"){
		puts("@ma@");
	}
	else
		if(decision.getAction().getName() == "move forward"){
			puts("@mw@");
		}

}
