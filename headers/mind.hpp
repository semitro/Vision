#ifndef MIND_HPP
#define MIND_HPP

#include <list>

#include "semantic/semanticweb.hpp"
#include "decision.hpp"

#include "attention_controller.hpp"

/*
 * Класс-обёртка над семантической сетью и компонента робота.
 * Делает выводы насчёт семантической сети,
 * задаёт вопросы,
 * Мозг обдумывает то, что имеет сейчас во внимании.
 * Внимание диктуется внешними раздражителями
 */

using vt::SemanticWeb;
using vt::Node;
using std::list;


// HavingAttention - интерфейс штуки, имеющей внимание
class Mind : public HavingAttention{
public:
	Mind();
	// Node - узел семантической сети: трактор, красный, быстро
	// Дубликаты не вставляются, потому что сеть хранится
	// с помощью set-а
	void addObject(vt::Node object);
	// Как и в нашем сознании, внммание может устанавливаться внешними раздражителями,
	// а не только нами
	virtual void payAttention(list<vt::Node> spotlights); // == setSpotlight
	virtual void payAttention(vt::Node spotlight);
	Decision makeDesition();

private:
	SemanticWeb     semanticWeb;
	list<vt::Node>  spotlight; // Объекты в данный момент времени, думать о них
};

#endif // MIND_HPP
