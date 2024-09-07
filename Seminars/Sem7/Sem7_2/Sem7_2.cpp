#include <iostream>
#include "Headers/ComplexNumber.h"

int main()
{
	ComplexNumber c;
	std::cin >> c;

	ComplexNumber c1;
	std::cin >> c1;

	c.print();
	c1.print();

	std::cout << (c + c1) << std::endl;
	std::cout << (c1 + c) << std::endl;
	std::cout << (c - c1) << std::endl;
	std::cout << (c1 - c) << std::endl;
	std::cout << (c * c1) << std::endl;
	std::cout << (c1 * c) << std::endl;
	std::cout << (c / c1) << std::endl;
	std::cout << (c1 / c) << std::endl;
}

