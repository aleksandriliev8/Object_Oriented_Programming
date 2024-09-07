#pragma once

class Date {
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	Date();
	Date(const unsigned int& _day, const unsigned int& _month, const unsigned int& _year);
	Date(const Date& other);
	Date& operator=(const Date& other);
	~Date();

	//setters
	void setDay(const unsigned int& _day);
	void setMonth(const unsigned int& _month);
	void setYear(const unsigned int& _year);
	void setDate(const unsigned int& _day, const unsigned int& _month, const unsigned int& _year);

	//getters
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;
};