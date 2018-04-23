#include "mind.hpp"

Mind::Mind()
{

}

void Mind::payAttention(list<vt::Node> spotlights){

}

void Mind::payAttention(vt::Node spotlight){

}

Decision Mind::makeDesition(){
	Verb result("run!!");
	Decision decision(result);
	decision.setReason("the worl is horrible");
	return result;
}
