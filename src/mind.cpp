#include "mind.hpp"

Mind::Mind(Behaviour& behaviour)
	:decisionMaker(behaviour)
{

}

void Mind::payAttention(list<vt::Node> spotlights){
	this->spotlight = spotlights;
}

void Mind::payAttention(vt::Node spotlight){

}

Decision Mind::makeDesition(){
	return decisionMaker.makeDecision(this->spotlight, this->semanticWeb);
}
