#pragma once

class Hour {
private:
	unsigned int hours;
	unsigned int mins;
public:
	Hour();
	Hour(const unsigned int& _hours, const unsigned int& _mins);
	Hour(const Hour& other);
	Hour& operator=(const Hour& other);
	~Hour();

	void setHours(const unsigned int& _hours);
	void setMins(const unsigned int& _mins);
	void setTime(const unsigned int& _hours, const unsigned int& _mins);

	unsigned int getHours() const;
	unsigned int getMins() const;
};