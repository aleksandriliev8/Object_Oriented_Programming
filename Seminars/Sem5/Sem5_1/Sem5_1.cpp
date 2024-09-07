#include <iostream>
#include "../Sem5_1/Headers/Event.h"

int main()
{
    char* name = new char[MAX_SIZE_EVENT_NAME + 1];

    std::cout << "Enter the name of the event: ";
    std::cin.getline(name, MAX_SIZE_EVENT_NAME);

    unsigned int day, month, year;

    std::cout << "Enter the date: ";
    std::cin >> day >> month >> year;

    Date date(day, month, year);
    
    unsigned int hours, mins;

    std::cout << "Enter the hour of beginning: ";
    std::cin >> hours >> mins;

    Hour begin(hours, mins);

    std::cout << "Enter the hour of end: ";
    std::cin >> hours >> mins;

    Hour end(hours, mins);

    Event event(name, date, begin, end);

    event.print();
}
