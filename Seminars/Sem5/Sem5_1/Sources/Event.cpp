#include "../Headers/Event.h"
#include "../Headers/Date.h"
#include "../Headers/HelperFunctions.h"
#include <iostream>
#include <cstring>

Event::Event() {
	name = nullptr;
	date.setDate(1, 1, 200);
	beginHour.setTime(0, 0);
	endHour.setTime(0, 0);
}

Event::Event(const char* _name, const Date& _date, const Hour& _beginHour, const Hour& _endHour) {
	setName(_name);
	setDateEvent(_date);
	setBeginHourEvent(_beginHour);
	setEndHourEvent(_endHour);
}

Event::Event(const Event& other) {
	setName(other.name);
	setDateEvent(other.date);
	setBeginHourEvent(other.beginHour);
	setEndHourEvent(other.endHour);
}

Event& Event::operator=(const Event& other) {
	if (this == &other) {
		return *this;
	}

	setName(other.name);
	setDateEvent(other.date);
	setBeginHourEvent(other.beginHour);
	setEndHourEvent(other.endHour);

	return *this;
}

Event::~Event() {
	delete[] name;
	//other destructors are called automatically
}

void Event::setName(const char* _name) {
	customStrCpy(name, _name);
}


void Event::setDateEvent(const Date& _date) {
	if (_date.getDay() >= 1 && _date.getDay() <= 31
		&& _date.getMonth() >= 1 && _date.getMonth() <= 12
		&& _date.getYear() >= 2000 && _date.getYear() <= 2024) {
		date = _date;
	}
	else {
		date.setDate(1, 1, 200);
	}

	//another way to do it
	/*date = _date.getDay() >= 1 && _date.getDay() <= 31
		&& _date.getMonth() >= 1 && _date.getMonth() <= 12
		&& _date.getYear() >= 2000 && _date.getYear() <= 2024 ? _date : date.setDate(1, 1, 200);*/
}

void Event::setBeginHourEvent(const Hour& _hours) {
	if (_hours.getHours() >= 0 && _hours.getHours() <= 23
		&& _hours.getMins() >= 0 && _hours.getMins() <= 59) {
		beginHour = _hours;
	}
	else {
		beginHour.setTime(0,0);
	}
}

void Event::setEndHourEvent(const Hour& _hours) {
	if (_hours.getHours() >= 0 && _hours.getHours() <= 23
		&& _hours.getMins() >= 0 && _hours.getMins() <= 59) {
		endHour = _hours;
	}
	else {
		endHour.setTime(0, 0);
	}
}

void Event::print() const{
	std::cout << "Event:" << std::endl;
	std::cout << name << std::endl;
	std::cout << "on " << date.getDay() << "." << date.getMonth() << "." << date.getYear() << std::endl;
	std::cout << "from: " << beginHour.getHours() << ":" << beginHour.getMins() << std::endl;
	std::cout << "to: " << endHour.getHours() << ":" << endHour.getMins() << std::endl;
}

