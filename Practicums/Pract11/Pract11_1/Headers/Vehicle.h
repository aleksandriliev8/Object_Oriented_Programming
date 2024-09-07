#pragma once

class Vehicle {
private:
	class Tire {
	public:
		unsigned int width;
		unsigned int profile;
		unsigned int diameter;
	};
	Tire* tire;
	char* engineType;
	double avrgSpeed;
	unsigned int countTires;
	unsigned int countPassengers;
public:
	Vehicle(const char* engineType, double avrgSpeed, unsigned int countTires, unsigned int countPassengers);
	virtual ~Vehicle() = 0;

	void setEngine(const char* _engineType);
	double timeBetweeenPoints(double distance);
	void setTire(const Tire& other, size_t index);
};