#include <iostream>

int main()
{
    int a;
    std::cin >> a;

    int* ptrA = &a;

    std::cout << "Value: " << *ptrA << " Address of variable: " << ptrA <<
        " Address of pointer: " << &ptrA << std::endl;
    std::cout << "Value of a: " << a << " Address of a: " << &a;
}