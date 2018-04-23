#ifndef DECISION_H
#define DECISION_H

#include <string>
#include "semantic/node.hpp"

using std::string;
using vt::Node;

/*
 * Решения, принимаемые роботом: бежать, ехать вперёд.
 * Почему не enum, а Node?
 * Ноды бывают глаголами.
 * Будем же разумом возвращать
 * действия реального мира,
 * которые в дальнейшем научимся обрабатывать
 *
 */

// А может, положить сюда Action, унаследованный от ноды?
// Что вообще значить решить 'собака?'

class Decision{
public:
	Decision(Verb action);
	Verb getAction();

	string getReason() const;
	void setReason(const string &value);
private:
	Verb   action; // Стоит бы добавить, куда и как, или вообще несколько решений
	string reason;
};
#endif // DECISION_H
