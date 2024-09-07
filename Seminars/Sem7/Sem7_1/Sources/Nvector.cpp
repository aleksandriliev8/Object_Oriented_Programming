#include <iostream>
#include "../Headers/Nvector.h"
#include "../Headers/Constants.h"

Nvector::Nvector() {
	values = nullptr;
	size = 0;
}

Nvector::Nvector(size_t _size) {
	if (_size > 0) {
		size = _size;
		values = new int[size];

		std::cout << "Enter the values of the vector with size " << size << ": " << std::endl;

		for (size_t i = 0; i < size; i++)
		{
			std::cin >> values[i];
		}
	}
	else{
		std::cout << ERROR_IMPUT_MESSAGE << std::endl;
		values = nullptr;
		size = 0;
	}
}

Nvector::Nvector(const Nvector& other) {
	copyFrom(other);
}

Nvector& Nvector::operator=(const Nvector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Nvector::~Nvector() {
	free();
}

void Nvector::copyFrom(const Nvector& other) {
	if (other.values && other.size > 0) {
		size = other.size;

		values = new int[size];

		for (size_t i = 0; i < size; i++)
		{
			values[i] = other[i];
		}
	}
	else {
		std::cout << ERROR_IMPUT_MESSAGE << std::endl;
		values = nullptr;
		size = 0;
	}
}

void Nvector::free() {
	size = 0;
	delete[] values;
}

void Nvector::print() const {

	std::cout << "[";

	for (size_t i = 0; i < size; i++)
	{
		if (i > 0) {
			std::cout << ",";
		}

		std::cout << values[i];
	}

	std::cout << "]" << std::endl;
}

Nvector operator+(const Nvector& lhs, const Nvector& rhs) {
	if (lhs.getSize() == rhs.getSize()) {
		size_t size = lhs.getSize();
		Nvector result;

		result.setSize(size);
		result.setValues(new int[size]);

		for (size_t i = 0; i < size; i++)
		{
			result.getValues()[i] = lhs[i] + rhs[i];
		}

		return result;
	}
	else{
		Nvector result(0);
		std::cout << ERROR_SIZE_DIFFERENCE << std::endl;
		return result;
	}
}

Nvector operator-(const Nvector& lhs, const Nvector& rhs) {
	if (lhs.getSize() == rhs.getSize()) {
		size_t size = lhs.getSize();
		Nvector result;

		result.setSize(size);
		result.setValues(new int[size]);

		for (size_t i = 0; i < result.getSize(); i++)
		{
			result.getValues()[i] = lhs.getValues()[i] - rhs.getValues()[i];
		}

		return result;
	}
	else {
		Nvector result(0);
		std::cout << ERROR_SIZE_DIFFERENCE << std::endl;
		return result;
	}
}

Nvector operator*(const Nvector& obj, int scalar) {

	if (obj.getValues() && obj.getValues() > 0) {
		Nvector result(obj);

		for (size_t i = 0; i < result.getSize(); i++)
		{
			result.getValues()[i] *= scalar;
		}

		return result;
	}
	else{
		Nvector result(0);
		std::cout << ERROR_EMPTY_OBJECT << std::endl;
		return result;
	}
}

Nvector operator*(int scalar, const Nvector& obj) {
	return (obj * scalar);
}

bool operator||(const Nvector& lhs, const Nvector& rhs) {
	if (lhs.getSize() == rhs.getSize() && lhs.getSize() > 0) {

		int scalar = 0;

		if (lhs[0] > rhs[0] && lhs[0] % rhs[0] == 0) {
			scalar = lhs[0] / rhs[0];

			for (size_t i = 0; i < rhs.getSize(); i++)
			{
				if (rhs[i] * scalar != lhs[i]) {
					return false;
				}
			}
		}
		else if (lhs[0] <= rhs[0] && rhs[0] % lhs[0] == 0) {
			scalar = rhs[0] / lhs[0];

			for (size_t i = 0; i < rhs.getSize(); i++)
			{
				if (lhs[i] * scalar != rhs[i]) {
					return false;
				}
			}
		}
		else {
			return false;
		}

		return true;
	}
	else {
		return false;
	}
}

int Nvector::operator[](size_t index) const {
	if (index < 0 || index > size - 1) {
		std::cout << ERROR_IMPUT_MESSAGE << std::endl;
		return -1;
	}
	else if (!values) {
		std::cout << ERROR_EMPTY_OBJECT << std::endl;
		return -1;
	}
	else {
		for (size_t i = 0; i < size; i++)
		{
			if (i == index) {
				return values[i];
			}
		}
	}
}

bool arePerpendicular(const Nvector& lhs, const Nvector& rhs){
	if (lhs.size != rhs.size || lhs.size == 0) {
		std::cout << ERROR_SIZE_DIFFERENCE << std::endl;
		return false;
	}

	int sum = 0;

	for (size_t i = 0; i < lhs.size; i++)
	{
		sum += lhs[i] * rhs[i];
	}

	return sum == 0 ? true : false;
}

size_t Nvector::getSize() const {
	return size;
}

void Nvector::setSize(size_t _size) {
	size = _size > 0 ? _size : 0;
}

void Nvector::setValues(int* _values) {
	if (_values) {
		for (size_t i = 0; i < size; i++)
		{
			values[i] = _values[i];
		}
	}
	else {
		values = nullptr;
	}
}

int* Nvector::getValues() const {
	return values;
}