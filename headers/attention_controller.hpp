#ifndef ATTENTION_CONTROLLER_HPP
#define ATTENTION_CONTROLLER_HPP

#include <iostream>
#include <unistd.h>

#include "vision/vision.hpp"


using namespace std;

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
	AttentionController(const HavingAttention& controlled);
private:
	HavingAttention& attention; // Если здесь указать ссылку, будет ли тот же объект, что в конструкторе?
	Vision vision;
};

#endif // ATTENTION_CONTROLLER
