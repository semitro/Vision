#include "behaviour.hpp"

Decision SociofobBehaviour::makeDecision(const list<Node> &spotlight, const SemanticWeb &knoweledges){
	Verb action("run!!");
	Decision decision(action);
	decision.setReason("The world is horrible. I see " + std::to_string(spotlight.size()) + "  humans!");
	return decision;
}
