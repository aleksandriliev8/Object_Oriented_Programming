#pragma once

class CarPart {
private:
	unsigned int id;
	char* producerName;
	char* description;
public:
	CarPart();
	CarPart(unsigned int _id, const char* producerName, const char* description);
	CarPart(const CarPart& other);
	CarPart& operator=(const CarPart& other);
	~CarPart();

	CarPart(CarPart&& other) noexcept;
	CarPart& operator=(CarPart&& other) noexcept;
private:
	void copyFrom(const CarPart& other);
	void free();
};