
//reading from file //input

#include <iostream>
#include <fstream>

const int BUFF_SIZE = 1024;
const char FILE_NAME[] = "myFile.txt";

int main()
{
    std::ifstream file(FILE_NAME);

    if (!file.is_open()) {
        std::cout << "Error!" << std::endl;
        return -1;
    }

    while (!file.eof()) {
        char buff[BUFF_SIZE];
        file.getline(buff, BUFF_SIZE);

        //do something with the line
        std::cout << buff << std::endl;
    }

    file.close();
}

//writing in file //output

#include <iostream>
#include <fstream>

const char FILE_NAME[] = "myFile.txt";

int main()
{
    std::ofstream file(FILE_NAME);  // create output file stream associated with myFile.txt

    std::cout << file.tellp() << " ";//0

    if (!file.is_open()) {
        std::cout << "Error!" << std::endl;
        return -1;
    }

    int a = 3;
    int b = 10;

    file << a;
    std::cout << file.tellp() << " ";//1

    file << " ";
    std::cout << file.tellp() << " ";//2

    file << b;
    std::cout << file.tellp() << " ";//4

    file << " ";
    std::cout << file.tellp() << " ";//5

    file << a + b;
    std::cout << file.tellp() << " ";//7

    file << std::endl;
    std::cout << file.tellp() << " ";// write into the output file stream

    //if (!file.eof()) { //check if the file has ended
    //    std::cout << "The file contains more data after the two integers!" << std::endl;
    //}

    int number = 10;

    file << number;
    file.tellp();

    file.close();
}

