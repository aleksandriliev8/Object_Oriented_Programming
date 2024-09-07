#include <iostream>

class B {

};

class A {
	void CopyFrom(const A& other) {
		arr = new int[other.size];
		for (size_t i = 0; i < other.size; i++)
			arr[i] = other.arr[i];
		size = other.size;
	}

	void Free() {
		delete[] arr;
	}

public:
	B nestedObject;
	int* arr; //dynamic array
	size_t size;

	A(int n) : size(n) {
		arr = new int[n];
	}

	A(const A& other) : nestedObject(other.objTest), size(other.size) {
		CopyFrom(other);
	}

	const A& operator=(const A& other) {
		if (this != &other) {
			nestedObject = other.nestedObject;
			free();
			copyFrom(other);
		}
		return *this;
	}

	~A() {
		free();
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

