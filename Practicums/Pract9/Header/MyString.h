#pragma once
#include <iostream>

class MyString {
private:
	char* data;
	size_t length;

	void free();
	void copyFrom(const MyString& other);
public:
	MyString();
	MyString(size_t cpacity);
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	char* getData() const;
	size_t getLength() const;

	//move semantics on the next lecture
	//MyString(MyString&& other) = delete; 
	//MyString& operator=(MyString&& other) = delete; 
	
	void print() const;
	MyString& operator+=(const MyString& other);

	MyString substr(size_t begin, size_t howMany) const;

	char& operator[](size_t index);
	char operator[](size_t index) const;

	const char* c_str() const;

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream& is, MyString& str);
};

std::ostream& operator<<(std::ostream& os, const MyString& str);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);