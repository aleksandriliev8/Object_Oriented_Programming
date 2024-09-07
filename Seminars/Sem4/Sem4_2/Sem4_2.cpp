#include <iostream>
#include "../Sem4_2/Headers/Time.h"
#include "../Sem4_2/Headers/HelperFunctions.h"

int main()
{
    //creating objects
    Time t1;
    Time t2(4,7,8);

    //printing the two times
    std::cout << "Time 1: ";
    t1.print();
    std::cout << "Time 2: ";
    t2.print();

    newLine();

    //time 1 increased with 1 sec
    std::cout << "Time 1 after one second: ";
    t1.increaseWithOneSec();
    t1.print();

    //demonstrating the change when the hour is 1 sec before midnight
    Time t3(23, 59, 59);
    std::cout << "Time 3: ";
    t3.print();
    
    std::cout << "Time 3 after one second: ";
    t3.increaseWithOneSec();
    t3.print();

    //t1.leftTimeTillMidnight().print();
}
