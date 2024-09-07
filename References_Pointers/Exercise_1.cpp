#include <iostream>

int main() {
	int a, b;

	std::cin >> a >> b;

	int* ptrA = &a;
	int* ptrB = &b;

	std::cout << "Values of a and b" << (*ptrA) << " " << (*ptrB) << std::endl;
	std::cout << "Addresses of a and b: " << ptrA << " " << ptrB << std::endl;
	std::cout << "Addresses of ptrA and ptrB: " << &ptrA << " " << &ptrB << std::endl;
}