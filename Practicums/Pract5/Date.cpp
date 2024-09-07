#include "Date.h"
#include <iostream>

const int MONTH_DAYS_LEAP[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31 };
const int MONTH_DAYS_NOLEAP[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31 };

Date::Date() {
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(unsigned int _day, unsigned int _month, unsigned int _year) {
	setDay(_day);
	setDay(_month);
	setDay(_year);
}

void Date::setDay(unsigned int _day) {
	day = _day;
}

void Date::setMonth(unsigned int _month) {
	month = _month;
}

void Date::setYear(unsigned int _year) {
	year = _year;
}

unsigned int Date::getDay() const{
	return day;
}

unsigned int Date::getMonth() const {
	return month;
}

unsigned int Date::getYear() const {
	return year;
}

bool Date::isLeapYear() const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;
}

void Date::increaseDate(unsigned int n) {
	unsigned int leftDays = n;

	while (leftDays > 0) {
		unsigned int maxDays = getMaxMonthDays();

		if (equalToMax()) {
			day = 1;
			--leftDays;
			++month;

			if (month == 13) {
				month = 1;
				++year;
			}
		}
		else if (day + leftDays > maxDays) {
			leftDays -= (maxDays - day + 1);
			day = 1;
			++month;

			if (month == 13) {
				month = 1;
				++year;
			}
		}
		else {
			day += leftDays;
			leftDays = 0;
		}
	}
}

void Date::decreaseDate(unsigned int n) {
	unsigned int leftDays = n;

	while (leftDays > 0) {
		// If the current day is less than or equal to the number of days to decrease
		if (day <= leftDays) {
			leftDays -= day;  // Subtract the current day from leftDays

			// Move to the previous month
			if (month == 1) {  // If it's January, move to December of the previous year
				month = 12;
				--year;
			}
			else {
				--month;
			}

			// Set day to the last day of the previous month
			day = getMaxMonthDays();
		}
		else {
			// Just decrease the day by leftDays and exit the loop
			day -= leftDays;
			leftDays = 0;
		}
	}
}

unsigned int Date::getMaxMonthDays() const {

	if (month > 0) {
		return isLeapYear() ? (unsigned int)MONTH_DAYS_LEAP[month - 1] : (unsigned int)MONTH_DAYS_NOLEAP[month - 1];
	}
	else {
		std::cout << "Month is 0!" << std::endl;
		return 0;
	}
}

bool Date::equalToMax() const{
	return (isLeapYear() && MONTH_DAYS_LEAP[month - 1] == day)
		|| (!isLeapYear() && MONTH_DAYS_NOLEAP[month - 1] == day) ? true : false;
}

void Date::print() const {
	if (day < 10) {
		std::cout << "0";
	}

	std::cout << day << ".";

	if (month < 10) {
		std::cout << "0";
	}

	std::cout << month << "." << year << std::endl;
}

//void decreaseDate(unsigned int);

