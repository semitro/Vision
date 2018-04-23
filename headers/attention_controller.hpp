#ifndef ATTENTION_CONTROLLER_HPP
#define ATTENTION_CONTROLLER_HPP

#include "vision/vision.hpp"
#include "semantic/node.hpp"
#include <list>

using std::list;

// Интерфейс. Реализуется классом, имеющим внимание
class HavingAttention{
public:
	virtual void payAttention(list<vt::Node> node)=0;
	virtual void payAttention(vt::Node spotlight)=0;
};
// Таламус?
// Управление вниманием на основе зрения
class AttentionController
{
public:
	// Управляем зависимостями через конструктор
	AttentionController(const HavingAttention& controlled, const Vision& vision);
private:
	AttentionController();
	HavingAttention& attention; // Если здесь указать ссылку, будет ли тот же объект, что в конструкторе?
	Vision& vision;
};

#endif // ATTENTION_CONTROLLER
