#pragma once

class Time {
private:
	unsigned int hours;
	unsigned int mins;
	unsigned int secs;

	Time(unsigned int seconds);
public:
	Time();
	Time(const unsigned int& _hours, const unsigned int& _mins, const unsigned int& _secs);

	unsigned int getHours() const;
	unsigned int getMins() const;
	unsigned int getSecs() const;

	void setHours(const unsigned int& _hours);
	void setMins(const unsigned int& _mins);
	void setSecs(const unsigned int& _secs);

	Time leftTimeTillMidnight() const;
	void increaseWithOneSec();
	//bool isTimeForDinner() const;
	Time differenceInTimes(const Time& _other) const;
	void print() const;
};