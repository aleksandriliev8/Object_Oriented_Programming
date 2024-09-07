#include <iostream>

class Complex {
private:
    double real;
    double im;
public:
    friend Complex operator*(const Complex&, double);
    friend Complex operator*(double, const Complex&);
};

Complex operator*(const Complex& obj, double scalar) {
    Complex temp(obj);
    temp.real *= scalar;
    temp.im *= scalar;

    return temp;
}
//since the multiplication is commutative we can use the previous function in the definition of the next one
Complex operator*(double scalar, const Complex& obj) {
    return (obj * scalar);
}

int main()
{

}