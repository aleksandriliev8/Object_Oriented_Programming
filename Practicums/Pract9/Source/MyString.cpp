#include <iostream>
#pragma warning (disable : 4996)
#include "../Pract9_1/MyString.h"

MyString::MyString(size_t capacity){
	length = capacity - 1;
	data = new char[capacity];
}

MyString::MyString() : MyString(1) {
	data[0] = '\0';
}

MyString::MyString(const char* str) : MyString(strlen(str) + 1){
	strcpy(data, str);
}

MyString::MyString(const MyString& other){
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

MyString::~MyString() {
	free();
}

void MyString::free() {
	delete[] data;
	data = nullptr;
	length = 0;
}

void MyString::copyFrom(const MyString& other) {
	length = other.length;
	data = new char[length + 1];
	strcpy(data, other.data);
}

char* MyString::getData() const{
	return data;
}
size_t MyString::getLength() const{
	return length;
}

void MyString::print() const {
	std::cout << data << std::endl;
}

MyString& MyString::operator+=(const MyString& other) {
	char* result = new char[length += other.length + 1];
	result[0] = '\0';
	strcat(result, data);
	strcat(result, other.data);

	delete[] data;
	data = result;

	return *this;
}

MyString MyString::substr(size_t begin, size_t howMany) const {
	if (begin + howMany > length) {
		throw std::length_error("Error! substr out of range");
	}

	MyString result(howMany + 1);
	for (size_t i = 0; i < howMany; i++)
	{
		result.data[i] = data[begin + i];
	}
	result.data[howMany] = '\0';

	return result;
}

const char* MyString::c_str() const {
	return data;
}

char& MyString::operator[](size_t index) {
	return data[index];
}

char MyString::operator[](size_t index) const {
	return data[index];
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
	MyString result(lhs.length + rhs.length + 1);

	result.data[0] = '\0';
	strcat(result.data, lhs.data);
	strcat(result.data, rhs.data);

	return result;
}

std::istream& operator>>(std::istream& is, MyString& str) {
	char buff[1024];
	is >> buff;

	str.free();
	str.length = strlen(buff);
	str.data = new char[str.length + 1];
	strcpy(str.data, buff);
	return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
	os << str.c_str();
	return os;
}

bool operator<(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator>(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator==(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}