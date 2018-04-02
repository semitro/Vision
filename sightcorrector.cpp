#include "sightcorrector.hpp"

SightCorrector::SightCorrector(int avg_duration) : cooldown(avg_duration)
{
	current_charge = 1; // must not be zero!
	if(cooldown < 4)
		cooldown = 4;
}

void SightCorrector::count(int value){
	value_get_set_mutex.lock();
	current_charge++;
	if(current_charge == cooldown){
		current_charge = 1;
		current_value  = 0;
	}
	current_value += value;
	value_get_set_mutex.unlock();
}
int SightCorrector::getValue(){
	while(current_charge < 4){

	}
	value_get_set_mutex.lock();
	value_get_set_mutex.unlock();
	return current_value/current_charge;
}
