#include <iostream>
#include <fstream>

const char FILE_NAME[] = "Pract2_6.cpp";
const int MAX_BUFF_SIZE = 1024;

int main()
{
    std::ifstream input(FILE_NAME);

    if (!input.is_open()) {
        std::cout << "Couldn't open the file!" << std::endl;
        return -1;
    }

    while (!input.eof())
    {
        char buff[MAX_BUFF_SIZE];
        input.getline(buff, MAX_BUFF_SIZE);

        std::cout << buff << std::endl;
    }

    input.close();

    return 0;
}
