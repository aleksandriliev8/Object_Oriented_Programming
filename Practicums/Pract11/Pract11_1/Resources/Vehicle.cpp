#include "../Pract11_1/Vehicle.h"
#include <iostream>
#pragma warning (disable : 4996)

Vehicle::Vehicle(const char* _engineType, double _avrgSpeed,
	unsigned int _countTires, unsigned int _countPassengers) {

	setEngine(_engineType);
	avrgSpeed = _avrgSpeed > 0 ? _avrgSpeed : 0;
	countTires = _countTires > 0 ? _countTires : 0;
	countPassengers = _countPassengers > 0 ? _countPassengers : 0;

	tire = new Tire[countTires];
	for (size_t i = 0; i < countTires; i++)
	{
		tire[i].width = 0;
		tire[i].profile = 0;
		tire[i].diameter = 0;
	}
}

void Vehicle::setEngine(const char* _engineType) {
	delete[] engineType;

	if (_engineType) {
		engineType = new char[strlen(_engineType) + 1];
		strcpy(engineType, _engineType);
	}
	else {
		engineType = new char[1];
		engineType[0] = '\0';
	}
}

double Vehicle::timeBetweeenPoints(double distance) {
	return distance / avrgSpeed;
}

void Vehicle::setTire(const Tire& other, size_t index) {
	if (index < countTires && index >= 0) {
		tire[index].width = other.width;
		tire[index].profile = other.profile;
		tire[index].diameter = other.diameter;
	}
	else {
		tire[index].width = 0;
		tire[index].profile = 0;
		tire[index].diameter = 0;
	}
}

Vehicle::~Vehicle() {
	delete[] tire;
	delete[] engineType;
	tire = nullptr;
	engineType = nullptr;

	avrgSpeed = 0;
	countTires = 0;
	countPassengers = 0;

	std::cout << "Vehicle destructor" << std::endl;
}