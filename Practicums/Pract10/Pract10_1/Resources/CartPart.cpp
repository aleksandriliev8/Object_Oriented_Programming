#include "../Pract10_1/CarPart.h"
#include <iostream>
#include <cstring>
#pragma warning (disable : 4996)

CarPart::CarPart() : id(0), producerName(nullptr), description(nullptr) {}

CarPart::CarPart(unsigned int _id, const char* _producerName, const char* _description) {
	this->id = _id;
	
	if (_producerName) {
		this->producerName = new char[strlen(_producerName) + 1];
		strcpy(this->producerName, _producerName);
	}
	else {
		this->producerName = new char[1];
		this->producerName[0] = '\0';
	}
	
	if (_description) {
		this->description = new char[strlen(_description) + 1];
		strcpy(this->description, _description);
	}
	else {
		this->description = new char[1];
		this->description[0] = '\0';
	}
}

CarPart::CarPart(const CarPart& other) {
	copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}
CarPart::~CarPart() {
	free();
}

CarPart::CarPart(CarPart&& other) noexcept{
	this->id = other.id;
	this->producerName = other.producerName;
	this->description = other.description;

	other.id = 0;
	other.description = nullptr;
	other.producerName = nullptr;
}

CarPart& CarPart::operator=(CarPart&& other) noexcept {
	if (this != &other) {
		free();
		this->id = other.id;
		this->description = other.description;
		this->producerName = other.producerName;

		other.id = 0;
		other.description = nullptr;
		other.producerName = nullptr;
	}

	return *this;
}

void CarPart::copyFrom(const CarPart& other) {
	this->id = other.id;

	if (other.producerName) {
		this->producerName = new char[strlen(other.producerName) + 1];
		strcpy(this->producerName, other.producerName);
	}
	else {
		this->producerName = new char[1];
		this->producerName[0] = '\0';
	}

	if (other.description) {
		this->description = new char[strlen(other.description) + 1];
		strcpy(this->description, other.description);
	}
	else {
		this->description = new char[1];
		this->description[0] = '\0';
	}
}

void CarPart::free() {
	delete[] producerName;
	delete[] description;

	producerName = nullptr;
	description = nullptr;
}