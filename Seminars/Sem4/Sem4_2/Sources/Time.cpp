#include "../Headers/Time.h"
#include <iostream>

Time::Time() {
	hours = 0;
	mins = 0;
	secs = 0;
}

Time::Time(unsigned int _allSecs) {
	secs = _allSecs % 60;
	_allSecs /= 60;

	mins = _allSecs % 60;
	_allSecs /= 60;

	hours = _allSecs % 60;
	_allSecs /= 60;
}

Time::Time(const unsigned int& _hours, const unsigned int& _mins, const unsigned int& _secs) {
	setHours(_hours);
	setMins(_mins);
	setSecs(_secs);
}

unsigned int Time::getHours() const {
	return hours;
}

unsigned int Time::getMins() const {
	return mins;
}

unsigned int Time::getSecs() const {
	return secs;
}

void Time::setHours(const unsigned int& _hours) {
	hours = (_hours >= 0 && _hours <= 23) ? _hours : 0;
}

void Time::setMins(const unsigned int& _mins) {
	mins = (_mins >= 0 && _mins <= 59) ? _mins : 0;
}

void Time::setSecs(const unsigned int& _secs) {
	secs = (_secs >= 0 && _secs <= 59) ? _secs : 0;
}

Time Time::leftTimeTillMidnight() const{
	unsigned int leftSecs = 60 - secs;
	unsigned int leftMins = 59 - mins;

	if (leftSecs == 60) {
		leftSecs = 0;
		++leftMins;
	}

	unsigned int leftHours = 23 - hours;

	if (leftMins == 60) {
		leftMins = 0;
		++leftHours;
	}

	return Time(leftHours, leftMins, leftSecs);
}

void Time::increaseWithOneSec() {
	++secs;

	if (secs == 60) {
		secs = 0;
		++mins;
	}

	if (mins == 60) {
		mins = 0;
		hours++;
	}

	if (hours == 24) {
		hours = 0;
	}
}

void printFormatMeasurement(const unsigned int& measurement) {
	if (measurement < 10) {
		std::cout << "0";
	}
	
	std::cout << measurement;
}

void Time::print() const{

	printFormatMeasurement(hours);
	std::cout << ":";
	printFormatMeasurement(mins);
	std::cout << ":";
	printFormatMeasurement(secs);
	std::cout << std::endl;
}

unsigned int diffTimeMeasurements (const unsigned int& _thisMeasurement, const unsigned int& _otherMeasurement){
	return _thisMeasurement == _otherMeasurement ? 0 : (unsigned int)abs((int)_thisMeasurement - (int)_otherMeasurement);
}

Time Time::differenceInTimes(const Time& _other) const{
	return Time()
}