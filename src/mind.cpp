#include "mind.hpp"

Mind::Mind()
{

}
#include <iostream>
void Mind::payAttention(list<vt::Node> spotlights){
	this->spotlight = spotlights;
}

void Mind::payAttention(vt::Node spotlight){

}

Decision Mind::makeDesition(){
	Verb action("run!!");
	Decision decision(action);
	decision.setReason("The world is horrible. I see " + std::to_string(spotlight.size()) + "  humans!");
	return decision;
}
