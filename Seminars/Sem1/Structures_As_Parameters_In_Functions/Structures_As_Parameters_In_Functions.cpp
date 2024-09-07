#include <iostream>

struct Box
{
    double height;
    double width;
    double length;
    // double height, width, length; is also possible
};

//��� ���� �� ��������� ������ �� �������� �� CONSTANT REFERENCE.
double calculcateVolume(const Box& b)
{
    return b.height * b.width * b.length;
}

//���� � ���� �� ����������, �� ������ ���� �� �� ������ ������� ����� ��������� ��������.
void readBox(Box& b)
{
    std::cin >> b.height >> b.width >> b.length;
}

//���� � �� �� �������� �� �����.
Box revertBox(Box b)
{
    int temp = b.height;
    b.height = b.width;
    b.width = temp;

    return b;
}

int main()
{
    //Box b; // default values to height and width and length

    //Box b2 = { 3, 4, 3.4 }; // height = 3, width = 3, length = 3.4;

    //Box b3;
    //b3.height = 13;
    //b3.width = 14;
    //b3.length = 20;

    //��������� �� ��������� ������

    Box* boxPtr = new Box();

    // different types of assigning a value to a property when you have a pointer
    (*boxPtr).height = 3;
    (*boxPtr).width = 1;
    boxPtr->length = 4;

    std::cout << calculcateVolume(*boxPtr) << std::endl;

    delete boxPtr;
}
