#include "behaviour.hpp"

Decision SociofobBehaviour::makeDecision(const list<Node> &spotlight,
										 const SemanticWeb &knoweledges)
{
	Verb action("move forward");

	if(spotlight.size() > 0){
		action.setName("change direction");
	}

	Decision decision(action);
	decision.setReason("The world is horrible. I see " + std::to_string(spotlight.size()) + "  humans!");
	return decision;
}

Decision SociofillBehaviour::makeDecision(const list<Node> &spotlight,
										  const SemanticWeb &knoweledges)
{
	Verb action("move forward");
	Decision decision(action);
	decision.setReason("looking for something interesting..");
	if(spotlight.size() == 0 ){
		decision.setReason("What a lovely thing! (" + std::to_string(spotlight.size()) + " in total");
		action.setName("change direction");
	}

	return decision;
}
