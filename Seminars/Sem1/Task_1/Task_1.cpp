// Task_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Point {
    double x;
    double y;
};

struct Triangle {
    Point p1;
    Point p2;
    Point p3;
};



int main()
{
    int N;

    Triangle* triangles = new Triangle();

    for (size_t i = 0; i < N; i++)
    {
        std::cout << "Enter point 1: ";
        std::cin >> triangles[i].p1.x >> triangles[i].p1.y;

        std::cout << "Enter point 2: ";
        std::cin >> triangles[i].p2.x >> triangles[i].p2.y;

        std::cout << "Enter point 3: ";
        std::cin >> triangles[i].p3.x >> triangles[i].p3.y;
    }

    delete[] triangles;
}
