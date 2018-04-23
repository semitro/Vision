#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <list>
#include "semantic/semanticweb.hpp"

#include "decision.hpp"

using std::list;

// Behaviour - компонент мозга, отвечающий за то,
// какое именно решение принимать
// в данный момент времени

class Behaviour{
public:
	virtual Decision makeDecision(const list<vt::Node> &spotlight, const
								  SemanticWeb &knoweledges)=0; // передавать ли знания?
};

class SociofobBehaviour : public Behaviour{
public:
	virtual Decision makeDecision(const list<vt::Node> &spotlight, const
								  SemanticWeb &knoweledges);
};

#endif // BEHAVIOUR_H
