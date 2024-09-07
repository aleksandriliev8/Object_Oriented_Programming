#include <iostream>
#include "../Headers/Set.h"
#include "../Headers/Constants.h"

Set::Set() {
	size = 0;
	numbers = nullptr;
}

Set::Set(size_t _size) {
	if (_size >= 1 && _size <= 1000) {

		size = _size;
		numbers = new bool[size];

		for (size_t i = 0; i < size; i++)
		{
			numbers[i] = 0;
		}
	}
	else {
		numbers = nullptr;
		size = 0;
	}
}

Set::Set(const Set& other) {
	copyFrom(other);
}

Set& Set::operator=(const Set& other) {
	if (this == &other) {
		return *this;
	}

	free();
	copyFrom(other);
}

Set::~Set() {
	free();
}

void Set::copyFrom(const Set& other) {
	if (other.numbers && other.size >= 1 && other.size <= 1000) {
		size = other.size;
		numbers = new bool[size];

		for (size_t i = 0; i < size; i++)
		{
			numbers[i] = other.numbers[i];
		}
	}
	else {
		size = 0;
		numbers = nullptr;
	}
}

void Set::free() {
	size = 0;
	delete[] numbers;
}

void Set::addNumber(const int& number) {
	if (number > 0 && number < size) {
		numbers[number] = 1;
	}
	else {
		std::cout << ERROR_MESSAGE_NUMBER << " (" << number << ")" << std::endl;
	}
}

void Set::removeNumber(const int& number) {
	if (number > 0 && number < size) {
		numbers[number] = 0;
	}
	else {
		std::cout << ERROR_MESSAGE_NUMBER << " (" << number << ")" << std::endl;
	}
}

void Set::printSetFormat() const{
	if (numbers == nullptr) {
		std::cout << EMPTY_SET_ERROR << std::endl;
		return;
	}

	std::cout << "{";
	unsigned int counter = 0;

	for (size_t i = 0; i < size; ++i)
	{
		if (numbers[i] == 1) {
			if (counter != 0) {
				std::cout << ", ";
			}

			++counter;
			std::cout << i;
		}
	}

	std::cout << "}" << std::endl;
}

bool Set::isContained(const int& number) const {
	if (number >= 0 && number < size) {
		for (size_t i = 0; i < size; i++)
		{
			if (i == number) {
				return true;
			}
		}

		return false;
	}
	else {
		std::cout << ERROR_MESSAGE_NUMBER << " (" << number << ")" << std::endl;
		return false;
	}
}

void Set::printDataFormat() const{
	if (numbers == nullptr) {
		std::cout << EMPTY_SET_ERROR << std::endl;
		return;
	}

	for (size_t i = 0; i < size; ++i)
	{
		unsigned int value = numbers[i];
		std::cout << value;
	}

	std::cout << std::endl;
}

Set Set::setUnion(const Set& other) const {
	if (!other.numbers) {
		if (!numbers) {
			Set newSet;
			return newSet;
		}
		else {
			return *this;
		}
	}
	else if(!numbers){
		return other;
	}
	else {
		size_t newSize = size > other.size ? size : other.size;
		Set newSet(newSize);

		for (size_t i = 0; i < size; i++)
		{
			newSet.numbers[i] = numbers[i] == 1 ? 1 : 0;
		}

		for (size_t i = 0; i < other.size; i++)
		{
			newSet.numbers[i] = other.numbers[i] == 1 ? 1 : 0;
		}

		return newSet;
	}
}

size_t Set::lastIndexTotalNumbers(const Set& other) const{
	size_t lastTotalIndex = -1;

	for (size_t i = 0; i < size && i < other.size; i++)
	{
		if (numbers[i] == other.numbers[i] && numbers[i] == 1) {
			lastTotalIndex = i;
		}
	}

	return lastTotalIndex;
}

Set Set::setSection(const Set& other) const {
	size_t newSize = lastIndexTotalNumbers(other) + 1;


	if (newSize == 0) {
		Set newSet;
		return newSet;
	}
	else {
		Set newSet(newSize);

		for (size_t i = 0; i < newSize; i++)
		{
			newSet.numbers[i] = numbers[i] == other.numbers[i] && numbers[i] == 1 ? 1 : 0;
		}

		return newSet;
	}
}