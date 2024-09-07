#include "../Pract9_1/Product.h"
#include <iostream>

Product::Product(const MyString& _name) {
	name = MyString(_name);
}

const MyString& Product::getProductname() const {
	return name;
}

void Product::print() const {
	std::cout << name.getData() << std::endl;
}