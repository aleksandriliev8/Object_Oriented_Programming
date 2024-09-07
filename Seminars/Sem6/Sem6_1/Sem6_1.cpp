#include <iostream>
#include "../Sem6_1/Headers/Set.h"

int main()
{
    Set s1(10);
    Set s2(5);

    s2.addNumber(2);
    s2.addNumber(4);
    s2.addNumber(3);

    s2.printSetFormat();

    //Set s3(s2);
    //s3.printSetFormat();

    s1.addNumber(7);
    s1.addNumber(4);
    s1.addNumber(5);

    s1.printSetFormat();

    Set s3 = s1.setUnion(s2);
    s3.printSetFormat();

    Set s4 = s1.setSection(s2);
    s4.printSetFormat();
}