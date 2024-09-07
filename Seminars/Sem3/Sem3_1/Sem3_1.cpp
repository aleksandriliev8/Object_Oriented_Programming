#include <iostream>
#include <fstream>

const char FILE_NAME[] = "outFile.txt";

struct Student {
	char name[30];
	int age;
	int fn;
};

size_t getFileSize(std::ifstream& file) {
	file.seekg(0, std::ios::end);
	size_t size = file.tellg();
	file.seekg(0, std::ios::beg);

	return size;
}

void readFromFile(std::ifstream& file, Student*& ptr, size_t& countStudents) {
	size_t sizeOfFile = getFileSize(file);
	countStudents = sizeOfFile / sizeof(Student);
	ptr = new Student[countStudents];
	file.read((char*)ptr, sizeOfFile);
}


int main()
{
	Student* arr;
	std::ifstream file("students.dat");

	if (!file.is_open()) {
		std::cout << "Couldn't open the file!" << std::endl;
	}

	size_t countStudents = 0;
	readFromFile(file, arr, countStudents);

	for (size_t i = 0; i < countStudents; i++)
	{
		std::cout << "Name: " << arr[i].name << " Age: " << arr[i].age << " FN: " << arr[i].fn << std::endl;
	}

	file.close();
}