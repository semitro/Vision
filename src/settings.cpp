#include "settings.hpp"

string Settings::getDistance_sensor_file() const
{
	return distance_sensor_file;
}

void Settings::setDistance_sensor_file(const string &value)
{
	distance_sensor_file = value;
}
