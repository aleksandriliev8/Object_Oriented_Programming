#pragma once

class Date {
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;

	unsigned int getMaxMonthDays() const;
	bool equalToMax() const;
public:
	Date();
	Date(unsigned int, const unsigned int, unsigned int);
	//Date(const Date& other);
	//~Date();
	
	void setDay(unsigned int);
	void setMonth(unsigned int);
	void setYear(unsigned int);

	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;

	bool isLeapYear() const;
	void increaseDate(unsigned int);
	void decreaseDate(unsigned int);
	void print() const;
};