#include <iostream>
#include <fstream>

const char FILE_NAME[] = "Sem2_1.cpp";
const int BUFFER_SIZE = 1024;

int main()
{
    std::ifstream codeStream(FILE_NAME);

    if (!codeStream.is_open()) {
        std::cerr << "Couldn't open the file " << std::endl;
    }

    while (!codeStream.eof()) {
        char buffer[BUFFER_SIZE];

        codeStream.getline(buffer, BUFFER_SIZE);
        std::cout << buffer << std::endl;
    }

    codeStream.close();
}
