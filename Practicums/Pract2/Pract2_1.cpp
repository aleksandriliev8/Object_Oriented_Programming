#include <iostream>
#include <fstream>

const char FILE_NAME[] = "result.txt";

int diffSumAndProduct(const char fileName[]) {
    std::ifstream in(fileName);

    if (!in.is_open()) {
        std::cout << "Couldn't open the file!" << std::endl;
        return -1;
    }

    int sum;
    int product;

    in >> sum >> product;

    in.close();

    return (sum - product);
}

int main()
{
    int number1, number2, number3;
    std::cout << "Enter the numbers: ";
    std::cin >> number1 >> number2 >> number3;

    std::ofstream out(FILE_NAME);

    if (!out.is_open()) {
        std::cout << "Couldn't open the file!" << std::endl;
        return -1;
    }
    int sum = number1 + number2 + number3;
    int product = number1 * number2 * number3;

    out << sum << " " << product << std::endl;

    out.close();

    std::cout << diffSumAndProduct(FILE_NAME) << std::endl;
}
