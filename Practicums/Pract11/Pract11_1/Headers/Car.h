#pragma once
#include "../Pract11_1/Vehicle.h"
#include <iostream>

class Car : public Vehicle {
public:
	Car(const char* type, double avrgSpeed, unsigned int countTires, unsigned int countPassengers)
		: Vehicle(type, avrgSpeed, countTires, countPassengers) {
		// ������������ ������������� �� Car (��� ���)
	}
	~Car() {
		std::cout << "Car destructor" << std::endl;
	}

};