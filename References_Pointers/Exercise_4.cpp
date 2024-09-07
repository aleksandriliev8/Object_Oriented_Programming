#include <iostream>

int main()
{
    char str[] = "A string";
    char *ptr = str;
    
    std::cout << str[0] << *ptr << ptr[3] << std::endl;
    ptr += 2;

    std::cout << *ptr << ptr[2] << ptr[5];
}