#include <iostream>
#include <fstream>

//for output file
size_t getOutFileSize(std::ofstream& file) {
    file.seekp(0, std::ios::end);
    size_t size = file.tellp();
    file.seekp(0, std::ios::beg);

    return size;
}

//for input file
size_t getInFileSize(std::ifstream& file) {
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    return size;
}

int main()
{
    std::cout << "Hello World!\n";
}
