#include <iostream>
#include <fstream>

struct Student {
    char name[30];
    int age;
    int fn;
};

size_t getFileSize(std::ofstream& file) {

    file.seekp(0, std::ios::end);
    size_t size = file.tellp();
    file.seekp(0, std::iostream::beg);

    return size;
}

void initializeStudents(Student*& ptr) {
    for (size_t i = 0; i < 4; i++)
    {
        std::cout << "Enter student's name: ";
        std::cin >> ptr[i].name;

        std::cout << "Enter student's age: ";
        std::cin >> ptr[i].age;

        std::cout << "Enter student's fn: ";
        std::cin >> ptr[i].fn;
    }
}

void writeToFile(std::ofstream& file, const Student* ptr, const size_t& count) {

    file.write((const char*)ptr, count * sizeof(Student));
}

int main()
{
    Student* students = new Student[4];

    initializeStudents(students);

    std::ofstream file("students.dat", std::ios::binary);

    if (!file.is_open()) {
        std::cout << "Couldn't open the file!" << std::endl;
        delete[] students;
        return -1;
    }

    writeToFile(file, students, 4);

    file.close();
}
