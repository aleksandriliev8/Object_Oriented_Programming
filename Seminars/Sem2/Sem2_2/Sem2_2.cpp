#include <iostream>
#include <fstream>

const int MAX_CONTENT_SIZE = 1024;

int main()
{
    //firstly we create a new file with content
    //{
    //    std::ofstream sourceFile("SourceFile.txt");

    //    if (!sourceFile.is_open()) {
    //        std::cerr << "Couldn't open the file" << std::endl;
    //    }

    //    int number = 10;
    //    char message[] = "Hello, what's up!";

    //    sourceFile << 10 << " " << message;

    //    sourceFile.close();
    //}
    

    //then we copy the content from the source file

    {
        std::ifstream sourceFile("SourceFile.txt");
        std::ofstream copyFile("DublicateFile.txt");

        if (!sourceFile.is_open() || !copyFile.is_open()) {
            std::cerr << "Couldn't open the file" << std::endl;
        }

        while (!sourceFile.eof()) {
            char content[MAX_CONTENT_SIZE];
            sourceFile.getline(content, MAX_CONTENT_SIZE);
            copyFile << content << std::endl;
        }

        copyFile.close();
        sourceFile.close();
    }
}

