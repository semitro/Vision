#ifndef SIGHTCORRECTOR_H
#define SIGHTCORRECTOR_H

#include <stdlib.h>
#include <mutex>
// Корректирует количество объектов на изображении: усредняет его
class SightCorrector
{
public:
	SightCorrector(int avg_duration=8);
	void count(int value); // Добавить запись о количестве объектов
	int getValue();
private:
	volatile size_t current_value;  // Сколько сейчас объектов
	size_t cooldown;       // Сколько на сброс
	volatile size_t current_charge; // Сколько сейчас кадров учтено
	std::mutex value_get_set_mutex;
};

#endif // SIGHTCORRECTOR_H
