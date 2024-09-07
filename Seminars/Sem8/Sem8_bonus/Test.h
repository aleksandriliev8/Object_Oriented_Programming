#pragma once

class Test {
private:
	struct Vector {
		int* numbers;
		size_t size;

		Vector();
		void insertVector(int _number);
		void insertIndexVector(size_t index, int number);
	};

	Vector vector;

public:
	Test();
	
	void insertNumber(int _number);
	void insertIndex(size_t index, int number);
	void print() const;
};