#include <iostream>
#include "Test.h"

int main()
{
    Test v1;
    v1.insertNumber(10);
    v1.insertNumber(20);
    v1.insertNumber(40);
    v1.print();

    v1.insertIndex(2, 30);
}
