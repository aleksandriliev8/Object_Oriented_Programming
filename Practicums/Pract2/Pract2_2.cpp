#include <iostream>
#include <fstream>

//const int MAX_BUFF_SIZE = 1024;

//function for counting the number of lines in a file
//unsigned lengthOfFile(const char* fileName) {
//    unsigned counter = 0;
//
//    std::ifstream myFile(fileName);
//
//    if (!myFile.is_open()) {
//        std::cout << "Couldn't open the file" << std::endl;
//        return 0;
//    }
//
//    while (!myFile.eof()) {
//        char buff[MAX_BUFF_SIZE];
//        myFile.getline(buff, MAX_BUFF_SIZE);
//
//        counter++;
//    }
//
//    myFile.close();
//
//    return counter;
//}

//function for counting the number of characters in the file

size_t lengthOfFile(const char* fileName) {
    std::ifstream myFile(fileName);
    
    if (!myFile.is_open()) {
        std::cout << "Couldn't open the file" << std::endl;
        return 0;
    }

    myFile.seekg(0, std::ios::end);
    size_t currPos = myFile.tellg();

    myFile.close();
    return currPos;
}

int main()
{
    std::cout << lengthOfFile("Pract2_2.cpp") << std::endl;
}