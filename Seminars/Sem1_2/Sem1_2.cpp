#include <iostream>

//struct Rational {
//    double value;
//
//    double sum(const Rational& number) {
//        return value + number.value;
//    }
//
//    double diff(const Rational& number) {
//        return value - number.value;
//    }
//
//    double product(const Rational& number) {
//        return value * number.value;
//    }
//
//    double division(const Rational& number) {
//        return value / number.value;
//    }
//};
//
//double sum(const Rational& number1, const Rational& number2) {
//    return number1.value + number2.value;
//}
//
//bool isInt(const Rational& number) {
//
//}
//
//bool isValid(const Rational& number) {
//
//    if (number.value > 10000 || number.value < -10000) {
//        std::cerr << "The number is too big to be verified!" << std::endl;
//        return false;
//    }
//
//    double a = 0;
//
//    for (size_t b = 1; ; b++)
//    {
//        a = number.value * b;
//    }
//
//    return true;
//}

int main()
{
    Rational num1 = {5.4};
    Rational num2 = { 6.7 };

    std::cout << "Sum: " << std::endl;
    std::cout << num1.sum(num2) << std::endl;
    std::cout << sum(num1, num2) << std::endl;

    std::cout << "Difference: " << std::endl;
    std::cout << num1.diff(num2) << std::endl;

    std::cout << "Product: " << std::endl;
    std::cout << num1.product(num2) << std::endl;

    std::cout << "Product: " << std::endl;
    std::cout << num1.division(num2) << std::endl;
}

