#include <iostream>


void fcopy(int a)
{
    a++; // a++ will increment the value of the copy
}


void freference(int& a)
{
    a++; // a++ will increment the actual value of the passed variable
}

void fpointer(int* a)
{
    (*a)++; // a++ will increment the value at the address where the pointer points at
}

int main()
{
    int a = 10;
    fcopy(a);
    std::cout << a << std::endl; //10

    freference(a);
    std::cout << a << std::endl;//11

    fpointer(&a);
    std::cout << a << std::endl;//12

}