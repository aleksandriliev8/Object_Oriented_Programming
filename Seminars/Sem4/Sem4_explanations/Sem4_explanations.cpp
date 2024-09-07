#include <iostream>

////member-functions in structs
struct Point {
	int x, y;

	bool isInFirstQuadrant() const {
		return x >= 0 && y >= 0;
	}

};

//another declaration
bool Point::isInFirstQuadrant() const{
	return x >= 0 && y >= 0;
}

//we can compare it to this
bool Point::isInFirstQuadrant(Point* const this) {
	//remember since this is a pointer (const) to Point we use the -> operator instead, which is equivalent to (*this).member;
	return this->x >= 0 && this->y >= 0;
}

struct obj {
	void inspect() const;   //This member-function promises not to change *this
	void mutate();          //This member-function might change *this
};

void Test(obj& changeable, const obj& unchangeable) {
	changeable.inspect();   // Okay: doesn't change a changeable object
	changeable.mutate();    // Okay: changes a changeable object

	unchangeable.inspect(); // Okay: doesn't change an unchangeable object
	/*unchangeable.mutate();*/  // ERROR: attempt to change unchangeable object
}

//Constructors and destructors

struct Test1 {
	Test() {
		std::cout << "Object is created" << std::endl;
	}

	~Test() {
		std::cout << "Object is destroyed" << std::endl;
	}

	int a, b;
};

int main() {
	{
		Point p1 = { 3, 4 };
		Point p2 = { -9, 8 };
		std::cout << p1.isInFirstQuadrant() << std::endl;
		std::cout << p2.isInFirstQuadrant() << std::endl;

		p1.isInFirstQuadrant();
		//can be translated as
		//Point::isInFirstQuadrant(&p1);
	}

	//Constructors and destructors

	{
		Test1 t2; // Object is created 
		{
			Test1 t2; // Object is created 
		} // Object is destroyed (t2)

	} //Object is destroyed (t)
}

//another example

struct A {
	A() {
		std::cout << "Constructor(default) of A" << std::endl;
	}

	~A() {
		std::cout << "Destructor of A" << std::endl;
	}
};

struct B {
	B() {
		std::cout << "Constructor(default) of B" << std::endl;
	}

	~B() {
		std::cout << "Destructor of B" << std::endl;
	}
};

struct C
{
	C() {
		std::cout << "Constructor(default) of C" << std::endl;
	}

	~C() {
		std::cout << "Destructor of C" << std::endl;
	}
};

struct X
{
	A first;
	B second;
	C objectsArray[3];

	X() { //calls Constructor(default) of A, Constructor(default) of B, Constructor(default) of C" (x3)
		std::cout << "Constructor of X" << std::endl;
	}

	~X() {
		std::cout << "Destructor of X" << std::endl;
	} //calls Destructor of C" (x3) , Destructor of B, Destructor of A

};

struct Student {
private:
	int grade;
	int age;
public:
	Student(int grade, int age) {
		setGrade(grade);
		setAge(age);
	}

	int getGrade() const {//won't change the member (grade)
		return grade;
	}

	int getAge() const {//won't change the member (age)
		return age;
	}

	void setGrade(int grade) {//will make changes in the member grade
		if (grade >= 2 && grade <= 6) {
			this->grade = grade;
		}
	}

	void setAge(int age) {//will make changes in the member age
		if (age >= 0) {
			this->age = age;
		}
	}
};

int main()
{
	X  obj; //Constructor of X
} // Destructor of X
