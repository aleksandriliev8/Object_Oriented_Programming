#include "../Headers/Hour.h"

Hour::Hour() {
	hours = 0;
	mins = 0;
}

Hour::Hour(const unsigned int& _hours, const unsigned int& _mins) {
	setTime(_hours, _mins);
}

Hour::Hour(const Hour& other) {
	hours = other.hours;
	mins = other.mins;
}

Hour& Hour::operator=(const Hour& other) {
	if (this == &other) {
		return *this;
	}

	hours = other.hours;
	mins = other.mins;

	return *this;
}

Hour::~Hour() {
	hours = 0;
	mins = 0;
}

void Hour::setHours(const unsigned int& _hours) {
	hours = _hours >= 0 && _hours <= 23 ? _hours : 0;
}
void Hour::setMins(const unsigned int& _mins) {
	mins = _mins >= 0 && _mins <= 59 ? _mins : 0;
}

void Hour::setTime(const unsigned int& _hours, const unsigned int& _mins) {
	setHours(_hours);
	setMins(_mins);
}

unsigned int Hour::getHours() const {
	return hours;
}
unsigned int Hour::getMins() const {
	return mins;
}