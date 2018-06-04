#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <string>

using std::string;

#define SENSOR_REQUEST_SYMBOL 'g'
#define SENSOR_REQUEST_INTERVAL 2000
class Settings{
public:

	string getDistance_sensor_file() const;
	void setDistance_sensor_file(const string &value);

private:
	string distance_sensor_file;
};
static Settings settings;

#endif // SETTINGS_H

