#pragma once

class Set {
private:
	size_t size;
	bool* numbers;

	void copyFrom(const Set& other);
	size_t lastIndexTotalNumbers(const Set& other) const;
	void free();
public:
	Set();

	Set(size_t _size);
	Set(const Set& other);
	Set& operator=(const Set& other);
	~Set();

	void addNumber(const int& number);
	void removeNumber(const int& number);
	bool isContained(const int& number) const;

	void printSetFormat() const;
	void printDataFormat() const;

	Set setUnion(const Set& other) const;
	Set setSection(const Set& other) const;
};