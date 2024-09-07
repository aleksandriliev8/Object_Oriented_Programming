#include "../Headers/Date.h"

Date::Date() {
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(const unsigned int& _day, const unsigned int& _month, const unsigned int& _year) {
	setDate(_day, _month, _year);
}

Date::Date(const Date& other) {
	day = other.day;
	month = other.month;
	year = other.year;
}

Date& Date::operator=(const Date& other) {
	if (this == &other) {
		return *this;
	}

	day = other.day;
	month = other.month;
	year = other.year;

	return *this;
}

Date::~Date() {
	day = 0;
	month = 0;
	year = 0;
}

void Date::setDay(const unsigned int& _day) {
	day = _day >= 1 && _day <= 31 ? _day : 1;
}

void Date::setMonth(const unsigned int& _month) {
	month = _month >= 1 && _month <= 12 ? _month : 1;
}

void Date::setYear(const unsigned int& _year) {
	year = _year >= 2000 && _year <= 2024 ? _year : 1;
}

void Date::setDate(const unsigned int& _day, const unsigned int& _month, const unsigned int& _year) {
	setDay(_day);
	setMonth(_month);
	setYear(_year);
}

unsigned int Date::getDay() const {
	return day;
}

unsigned int Date::getMonth() const {
	return month;
}

unsigned int Date::getYear() const {
	return year;
}