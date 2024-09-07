#include <iostream>
#include "Date.h";

int main()
{
	Date d1;

	d1.print();

	d1.increaseDate(366);
	d1.print();

	d1.increaseDate(366);
	d1.print();

	//d1.decreaseDate(366);
	//d1.print();

	//d1.decreaseDate(366);
	//d1.print();
}