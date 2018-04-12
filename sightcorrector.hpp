#ifndef SIGHTCORRECTOR_H
#define SIGHTCORRECTOR_H

#include <stdlib.h>

// Корректирует количество объектов на изображении: усредняет его
class SightCorrector
{
public:
	SightCorrector(int avg_duration=8);
	void count(int value); // Добавить запись о количестве объектов
	int getValue();
private:
	bool       wich_buffer; // См. паттерн 'двойная буферизация'
	size_t     buffer_1;
	size_t     buffer_2;
	size_t     cooldown;                // Сколько на сброс
	size_t     charge_1;                // Сколько сейчас кадров учтено в первом буфере
	size_t     charge_2;
};

#endif // SIGHTCORRECTOR_H
