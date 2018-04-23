#include "decision.hpp"

Decision::Decision(Verb action):action(action){}

Verb Decision::getAction(){
	return this->action;
}

string Decision::getReason() const
{
    return reason;
}

void Decision::setReason(const string &value)
{
    reason = value;
}
