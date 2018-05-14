#ifndef DECISION_PERF_H
#define DECISION_PERF_H

#include "decision.hpp"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::cerr;

/*
 * Испольнитель решений:
 * двигатели нужно реально включать.
 *
 */
// let it be an interface
// it can help us to debug the programm

class DecisionPerformer{
public:
	DecisionPerformer();
	virtual void perform(Decision decision)=0;
	virtual ~DecisionPerformer()=0;
};

class RealPerformer : public DecisionPerformer{
	void perform(Decision decision);
};

class DebugPerformer: public DecisionPerformer{
	void perform(Decision Decision);
};
#endif // DECISION_PERF_H
