#include "sensor/distance.hpp"

DistanceSensor::DistanceSensor(){
	if(settings.getDistance_sensor_file() == "-"){ // if the sensor isn't needed
		this->distance_front = 0;
		return;
	}
	 sensor_file = open(settings.getDistance_sensor_file().c_str(), O_RDWR);
	 thread request_thread(&DistanceSensor::requsest_loop, this);
	 thread responce_handler_thread(&DistanceSensor::read_loop, this);

}
// sends 'g' to the nano
void DistanceSensor::requsest_loop(){
	char requset_symbol = SENSOR_REQUEST_SYMBOL;
	while(true){
		if(is_on){
			write(sensor_file, &requset_symbol, sizeof(char));
			usleep(SENSOR_REQUEST_INTERVAL);
		}
		else
		{
			usleep(SENSOR_REQUEST_INTERVAL*5);
		}
	}
}
// read things form nano and set the variable
void DistanceSensor::read_loop(){
	static char receive_buffer[128]; // do not wrte onto the stack.
	while(true){
		if(is_on){
			read(sensor_file, receive_buffer, 128); // No more than 128 bytes (relativity random number)
		}
		for(int i = 0; i < 128; i++){
			if(receive_buffer[i] < '9' && receive_buffer[i] > '0'){ // skip extra characters
				sscanf(receive_buffer + i, "%d", &distance_front);
				printf("SENSOR:: %d", distance_front);
			}
		}
		usleep(SENSOR_REQUEST_INTERVAL);
	}
}

int DistanceSensor::getDistance(Which_Sensor sensor_num){
	return this->distance_front;
}
