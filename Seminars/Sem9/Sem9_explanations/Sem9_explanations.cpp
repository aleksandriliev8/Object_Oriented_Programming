#include <iostream>

int x;//Ivalue

int& getRef() {
    return x;
}

int getRef2() {
    return x;
}

std::string getName() {
    return "Pesho"; //rvalue
}

//lvalue
void print(const std::string& str) {
    std::cout << str;
}

//rvalue
void print(std::string&& str) {
    std::cout << str;
}

int main()
{
    int a;
    a = 4;    // = requires a (modifiable) lvalue as it's lhs, which is a

    getRef() = 4;  //Okay, getRef() is an lvalue - returns a reference to the global variable x
    return 0;

    int var;

    //not Ivaliue
    //4 = var;        //Error
    //(var + 1) = 4;  //Error



    const std::string& name = getName(); //ok //object from getName() exists while name exists

    /*std::string& name = getName();*/       //not ok //& name expects the name to be changed
                                        //but getName() obj doesn't exist

    int i = 42;
    int& r = i; // ok: r refers to i
    /*int&& rr = i;*/ // error: cannot bind an rvalue reference to an lvalue

    /*int& r2 = i * 42;*/ // error: i * 42 is an rvalue
    const int& r3 = i * 42; // ok: we can bind a reference to const to an rvalue
    int&& rr2 = i * 42; // ok: bind rr2 to the result of the multiplication

    int x = 5;
    /*int&& xRRef = x;*/   //Error: rvalue reference cannot be bound to an lvalue

    int&& xRRef = std::move(x);  //Ok move converts from xvalue to the other

    std::string lString = "Pesho";

    print(lString);  //Takes an lvalue, first function
    print("Ivan");   //Takes an rvalue as a parameter, hence the second function will be instantiated
}