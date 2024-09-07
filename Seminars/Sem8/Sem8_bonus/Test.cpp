#include <iostream>
#include "Test.h"

Test::Vector::Vector() {
	numbers = nullptr;
	size = 0;
}

void Test::Vector::insertVector(int _number) {

	int* newArr = new int[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = numbers[i];
	}

	newArr[size] = _number;
	size++;

	delete[] numbers;

	numbers = newArr;
}

void Test::Vector::insertIndexVector(size_t index, int number) {
	if (index >= 0 && index < size) {
		int* newArray = new int[size + 1];

		int indexOld = 0;

		for (size_t i = 0; i < size + 1; i++)
		{
			if (i != index) {
				newArray[i] = numbers[indexOld];
				indexOld++;
			}
			else {
				newArray[i] = number;
			}
			
		}

		delete[] numbers;
		numbers = newArray;
	}
	else {
		std::cout << "Invalid index! No changes are made!" << std::endl;
	}
}

Test::Test() : vector() {};

void Test::insertNumber(int _number) {
	vector.insertVector(_number);
}

void Test::print() const {
	std::cout << "[";

	for (size_t i = 0; i < vector.size; i++)
	{
		std::cout << vector.numbers[i];

		if (i != vector.size - 1) {
			std::cout << ",";
		}
	}

	std::cout << "]" << std::endl;
}

void Test::insertIndex(size_t index, int number) {
	vector.insertIndexVector(index, number);
}