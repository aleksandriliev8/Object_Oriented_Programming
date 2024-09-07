#include "../Pract10_1/Tires.h"
#include <iostream>

Tires::Tires() : CarPart(), width(0), profile(0), diameter(0){}

Tires::Tires(unsigned int _id, const char* _producerName, const char* _description, 
	unsigned int _width, unsigned int _profile, unsigned int _diameter) 
	: CarPart(_id, _producerName, _description) {
	this->width = _width >= TIRES_CONSTS::MIN_WIDTH && _width <= TIRES_CONSTS::MAX_WIDTH ? _width : 0;
	this->profile = _profile >= TIRES_CONSTS::MIN_PROFILE && _profile <= TIRES_CONSTS::MAX_PROFILE ? _profile : 0;
	this->diameter = _diameter >= TIRES_CONSTS::MIN_DIAMETER && _diameter <= TIRES_CONSTS::MAX_DIAMETER ? _diameter : 0;
}
Tires::Tires(const Tires& other) : CarPart(other) {
	copyFrom(other);
}
Tires& Tires::operator=(const Tires& other) {
	if (this != &other) {
		CarPart::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}
Tires::~Tires() {
	free();
}

Tires::Tires(Tires&& rhs) : CarPart(std::move(rhs)) {
	width = rhs.width;
	diameter = rhs.diameter;
	profile = rhs.profile;

	rhs.width = 0;
	rhs.diameter = 0;
	rhs.profile = 0;
}

Tires& Tires::operator=(Tires&& rhs) {
	if (this != &rhs) {
		CarPart::operator=(std::move(rhs));

		width = rhs.width;
		profile = rhs.profile;
		diameter = rhs.diameter;

		rhs.width = 0;
		rhs.diameter = 0;
		rhs.profile = 0;
	}

	return *this;
}

void Tires::copyFrom(const Tires& other) {
	this->width = other.width;
	this->profile = other.profile;
	this->diameter = other.diameter;
}

void Tires::free() {
	this->width = 0;
	this->profile = 0;
	this->diameter = 0;
}