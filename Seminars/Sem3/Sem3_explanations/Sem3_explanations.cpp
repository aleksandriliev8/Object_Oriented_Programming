#include <iostream>
#include <fstream>


//save variable in binary file
int main()
{
	std::ofstream f("file.dat", std::ios::binary);

	int a = 155555;

	f.write((const char*)&a, sizeof(int));

	return 0;
}

#include <iostream>
#include <fstream>

int main()
{
	std::ofstream ofs("myfile.dat", std::ios::out | std::ios::binary);

	int arr[5] = { 1,2,3,4,5 };

	ofs.write((const char*)arr, 5 * sizeof(int));

	ofs.close();

	return 0;
}

//- пример за прочитане на данна от двоичен файл
//
//```c+ +
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream f("file.dat", std::ios::binary);

	if (!f.is_open()) {
		std::cout << "Could not open file\n";
		return 1;
	}

	int a;
	f.read((char*)&a, sizeof(int));

	std::cout << a << std::endl;

	return 0;
}

//example of reading array of data from a binary file

#include <iostream>
#include <fstream>

size_t GetFileSize(std::ifstream& file)
{
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(currentPos);
	return fileSize;
}

int main()
{
	std::ifstream f("myfile.dat", std::ios::in | std::ios::binary);

	if (!f.is_open()) {
		std::cout << "Could not open file\n";
		return 1;
	}

	size_t fileSize = GetFileSize(f);
	size_t arrSize = fileSize / sizeof(int);
	int* arr = new int[arrSize];

	f.read((char*)arr, fileSize);

	for (size_t i = 0; i < arrSize; i++) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;
	f.close();

	return 0;
}

//example of reading and writing Structures from/in files

#include <iostream>
#include <fstream>

using namespace std;

struct Test
{
	bool b;
	int x;
};

int main()
{
	{
		//writing in file
		Test t = { true, 45 };
		ofstream file("testObj.bat", ios::binary);

		if (!file.is_open()) {
			return 1;
		}

		file.write((char*)&t, sizeof(t));//why isn't it const
	}

	{
		//reading from file
		Test t;
		ifstream file("testObj.bat", ios::binary);

		if (!file.is_open()) {
			return -1;
		}

		file.read((char*)&t, sizeof(t));
		std::cout << t.b << " " << t.x << std::endl;
	}
}