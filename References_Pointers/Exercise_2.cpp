#include <iostream>

int main()
{
    int n; int max = 0;
    std::cout << "Enter number of values:";
    std::cin >> n;

    std::cout << "Enter values in array:\n";
    int* arr = new int[n];

    for (int i = 0;i < n;i++) {
        std::cin >> arr[i];
    }
    
    for (int k = 0;k < n;k++) {
        if (arr[k] > max) {
            max = arr[k];
        }   
    }

    int* pointer = &max;


    std::cout << "Largest integer value in the array is " << *pointer;
}