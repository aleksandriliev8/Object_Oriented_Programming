#pragma once
#include "../Headers/Date.h"
#include "../Headers/Hour.h"
#include "../Headers/Constants.h"

class Event {
private:
	char* name;
	Date date;
	Hour beginHour;
	Hour endHour;
public:
	Event();
	Event(const char* _name, const Date& _date, const Hour& _beginHour, const Hour& _endHour);
	Event(const Event& other);
	~Event();

	Event& operator=(const Event& other);

	//setters
	void setName(const char* _name);
	void setDateEvent(const Date& _date);
	void setBeginHourEvent(const Hour& _hours);
	void setEndHourEvent(const Hour& _hours);

	void print() const;
};