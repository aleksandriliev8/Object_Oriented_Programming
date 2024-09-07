#include <iostream>

int main()
{
    int a = 10; // int in the STACK
    int* ptr = new int(30); // int in the DYNAMIC memory
    // we use a pointer on the stack to point to the int

// print the value of the int in the stack and the one in the heap
    std::cout << "First number: " << a << " " << " second number: " << (*ptr) << std::endl;

    // ptr holds an address in the dynamic memory where the int is placed
    std::cout << "Address of second number" << ptr << std::endl;

    delete ptr; // delete the int in the stack to prevent memory leak

    ptr = &a;   // redirect the pointer to int in the stack
    std::cout << "Address of first number" << ptr << std::endl; // now ptr holds the address that is in the stack

    int& b = a; // creates int which data is on the address of a => they share the same memory
    //b = 30;

    //std::cout << "First number" << a << std::endl; // 30
}