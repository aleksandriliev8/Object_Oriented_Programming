#pragma once
#include "../Pract9_1/MyString.h"

class Product {
private:
	MyString name;
public:
	Product() = default;
	Product(const MyString& _name);
	
	const MyString& getProductname() const;
	void print() const;
};