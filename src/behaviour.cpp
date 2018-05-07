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
