#include <iostream>
#include "Headers/Nvector.h"

int main()
{
    //Nvector v1(3);
    //v1.print();

    //Nvector v2;
    //v2 = v1;
    //v2.print();

    //Nvector v3(v2);
    //v3.print();

    //Nvector v4 = v1 + v2;
    //v4.print();

    //Nvector v5(3);
    //(v5 - v4).print();

    //(4 * v1).print();

    //Nvector v3;
    //(v3 * 1).print();

    Nvector v6(3);
    Nvector v7(3);
    //Nvector v7(4);

    //std::cout << std::boolalpha << (v7 || v6) << std::endl;
    std::cout << std::boolalpha << arePerpendicular(v6, v7) << std::endl;
    std::cout << v6.getSize() << std::endl;
}
