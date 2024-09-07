#pragma once
#include "../Pract10_1/CarPart.h"

namespace TIRES_CONSTS {
	const int MAX_WIDTH = 365;
	const int MIN_WIDTH = 155;
	const int MAX_PROFILE = 30;
	const int MIN_PROFILE = 80;
	const int MAX_DIAMETER = 13;
	const int MIN_DIAMETER = 21;
}

class Tires : public CarPart {
private:
	unsigned int width;
	unsigned int profile;
	unsigned int diameter;
public:
	Tires();
	Tires(unsigned int _id, const char* producerName, const char* description, unsigned int width, unsigned int profile, unsigned int diameter);
	Tires(const Tires& other);
	Tires& operator=(const Tires& other);
	~Tires();

	Tires(Tires&& other);
	Tires& operator=(Tires&& other);
private:
	void copyFrom(const Tires& other);
	void free();
};