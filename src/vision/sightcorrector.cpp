#include "vision/sightcorrector.hpp"

SightCorrector::SightCorrector(size_t avg_duration)
	: cooldown(avg_duration), wich_buffer(true),
	  buffer_1(0), buffer_2(0), charge_1(1), charge_2(1)
{
	if(cooldown < 1) cooldown = 1; //avg_duration
}

void SightCorrector::count(int value){

	if(wich_buffer){ // Выдаём пользователю старый буфер
		buffer_2 += value;
		charge_2 ++;
		if(charge_2 == cooldown){
			// Подменяем буферы: теперь возвращаться будет заполненный buffer_2
			wich_buffer = !wich_buffer;
			buffer_1 = 0;
			charge_1 = 0;
		}
	}
	else{
		buffer_1 += value;
		charge_1 ++;
		if(charge_1 == cooldown){
			wich_buffer = !wich_buffer;
			buffer_2 = 0;
			charge_2 = 0;
		}
	}
	// Дублирование кода оправдано.
	// Поддержка указателя длинне и непонятнее.
}

int SightCorrector::getValue(){
	if(wich_buffer)
		return buffer_1 / charge_1;
	else
		return buffer_2 / charge_2;
}
