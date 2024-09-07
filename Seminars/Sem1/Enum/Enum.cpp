#include <iostream>

//Examples
enum IceCream1
{
	vanilla, //0
	chocolate, //1
	strawberry, //2
	mango, //3
	oreo //4
};

enum IceCream2 : char
{
	vanilla, //0
	chocolate, //1
	strawberry, //2
	mango, //3
	oreo //4
};

//енумераторите са локални за enuma и техните стойности не се 
//преобразуват имплицитно към други типове (another enum or int)
enum class Color1 { red, green, blue }; // enum class

//енумераторите са в същия scope като enuma и 
//техните стойности се преобразуват имплицитно към integers и други типове
enum Animal1 { dog, cat, bird, human }; // plain enum 

enum Color2 { red, green, blue };                    // plain enum 
enum Card { red_card, green_card, yellow_card };    // another plain enum 
enum class Animal2 { dog, deer, cat, bird, human };  // enum class
enum class Mammal { kangaroo, deer, human };        // another enum class

void fun() {
    // examples of bad use of plain enums:
    Color2 color = Color2::red;
    Card card = Card::green_card;

    int num = color;    // no problem

    if (color == Card::red_card) // no problem (bad)
        std::cout << "bad" << std::endl;

    if (card == Color2::green)   // no problem (bad)
        std::cout << "bad" << std::endl;

    // examples of good use of enum classes (safe)
    Animal2 a = Animal2::deer;
    Mammal m = Mammal::deer;

    /*int num2 = a;*/   // error
    //if (m == a)     // error (good)
    //    cout << "bad" << endl;

    //if (a == Mammal::deer) // error (good)
    //    cout << "bad" << endl;
}


int main()
{
    std::cout << "Hello World!\n";
}
