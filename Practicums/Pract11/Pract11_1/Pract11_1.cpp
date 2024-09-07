#include <iostream>
#include "../Pract11_1/Vehicle.h"
#include "../Pract11_1/Car.h"

int main()
{
    //const char* type = "benzin";
    Vehicle* p = new Car("benzin", 100, 4, 5);
    delete p;
}

