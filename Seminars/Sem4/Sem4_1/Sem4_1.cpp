#include <iostream>

void newLine() {
    std::cout << std::endl;
}

class Interval {
private:
    int a;
    int b;

    bool isPrime(const int& number) const{
        if (number == 2 || number == 1) {
            return true;
        }

        unsigned int numberOfDivisors = 0;

        for (size_t i = 1; i <= number; ++i)
        {
            if (number % i == 0) {
                ++numberOfDivisors;
            }
        }

        return numberOfDivisors == 2;
    }

    bool isPalindrome(const int& number) const {
        if (number < 0)
        return false;

        unsigned int digit = 0;
        int reversedNumber = 0;
        int copyNumber = number;

        while (copyNumber > 0) {
            digit = copyNumber % 10;
            reversedNumber = reversedNumber * 10 + digit;
            copyNumber /= 10;
        }

        return number == reversedNumber;
    }

    bool hasDiffDigits(const int& number) const{
        if (number < 10) {
            return true;
        }

        int digitsCountArr[10] = {0,0,0,0,0,0,0,0,0,0};
        int copyNumber = number;

        while (copyNumber > 9) {
            unsigned int digit = number % 10;

            ++digitsCountArr[digit];
            copyNumber /= 10;
        }

        ++digitsCountArr[copyNumber];

        for (size_t i = 0; i < 10; i++)
        {
            if (digitsCountArr[i] > 1)
                return false;
        }

        return true;
    }

    bool isPowOfTwo(const int& number) const{
        return number > 0 && (number & (number - 1)) == 0;
    }

public:
    Interval() {
        a = 0;
        b = 0;
    }

    Interval(const int& newA, const int& newB) {
        if (newA <= newB) {
            setA(newA);
            setB(newB);
        }
        else {
            a = 0;
            b = 0;
        }
    }

    int getA() const{
        return a;
    }

    int getB() const {
        return b;
    }

    void setA(const int& newA) {
        a = newA;
    }

    void setB(const int& newB) {
        b = newB;
    }

    int intervalLength() const{
        return a <= b ? (b - a + 1) : 0;
    }

    bool isFromInterval(const int& number) const{
        return number >= a && number <= b;
    }

    unsigned int calcPrimeNumbersInTheInterval() const{
        unsigned int counter = 0;

        for (int i = a; i <= b ; i++)
        {
            if (isPrime(i)) {
                counter++;
            }
        }

        return counter;
    }

    unsigned int numberOfPalindromes() const{
        unsigned int counter = 0;

        for (size_t i = a; i <= b; i++)
        {
            if (isPalindrome(i))
                ++counter;
        }

        return counter;
    }

    unsigned int numberOfNumbersWithDiffDigits() const {
        unsigned int counter = 0;

        for (size_t i = a; i <= b; i++)
        {
            if (hasDiffDigits(i))
                counter++;
        }

        return counter;
    }

    bool areTheLimitsPowOfTwo() const{
        return isPowOfTwo(a) && isPowOfTwo(b);
    }

    Interval intersect(const Interval& t_other) const{

        if (t_other.a > b || t_other.b < a)
            return Interval(0, 0);

        int newA = (a <= t_other.a) ? t_other.a : a;
        int newB = (b <= t_other.b) ? b : t_other.b;

        return Interval(newA, newB);
    }

    bool isSuperInterval(const Interval& other) const{
        return other.a >= a && other.b <= b;
    }

    void print() const{
        std::cout << "[" << a << ", " << b << "]" << std::endl;
    }
};

int main()
{
    //create objects
    Interval t1(3, 10); // [3, 10]
    Interval t2(4, 14); // [4, 14]
    Interval t3; // [0, 0]

    //printing
    t1.print();
    t2.print();
    t3.print();

    newLine();
    
    //number of prime numbers in the intervals
    std::cout << "Number of primes in the interval: ";
    t1.print();
    std::cout << t1.calcPrimeNumbersInTheInterval() << std::endl;

    newLine();

    std::cout << "Number of primes in the interval: ";
    t3.print();
    std::cout << t3.calcPrimeNumbersInTheInterval() << std::endl;

    newLine();

    //checking if a number is from an interval
    int checkNumber_1 = 9;
    int checkNumber_2 = 25;

    std::cout << "Is it true that " << checkNumber_1 << " is part of the interval ";
    t2.print();
    std::cout << std::boolalpha << t2.isFromInterval(checkNumber_1) << std::endl;

    newLine();

    std::cout << "Is it true that " << checkNumber_2 << " is part of the interval ";
    t2.print();
    std::cout << std::boolalpha << t2.isFromInterval(checkNumber_2) << std::endl;

    newLine();

    //finding the length of every interval
    std::cout << "The length of the interval ";
    t1.print();
    std::cout << t1.intervalLength() << std::endl;

    newLine();

    std::cout << "The length of the interval ";
    t2.print();
    std::cout << t2.intervalLength() << std::endl;

    newLine();

    std::cout << "The length of the interval ";
    t3.print();
    std::cout << t3.intervalLength() << std::endl;

    newLine();

    //number of palindromes in interval

    Interval t4(100, 122);

    std::cout << "Number of palindromes in the interval ";
    t4.print();
    std::cout << t4.numberOfPalindromes() << std::endl;

    newLine();

    //count of numbers with non-repeating digits

    Interval t5(9, 12);

    std::cout << "The number of numbers with non-repeating digits from the interval ";
    t5.print();
    std::cout << t5.numberOfNumbersWithDiffDigits() << std::endl;

    newLine();

    //check if the limits of the interval are power of two

    Interval t6(2, 16);

    std::cout << "Are the limits of the given interval powers of two? ";
    t6.print();
    std::cout << t6.areTheLimitsPowOfTwo() << std::endl;

    newLine();

    //intersecting two intervals
    std::cout << "Intersection between intervals: " << std::endl;;
    t1.print();
    t2.print();

    Interval result = t1.intersect(t2); // [4, 10]
    std::cout << "Result: ";
    result.print();

    newLine();

    //checking for subinterval

    std::cout << "Is interval: ";
    result.print();
    std::cout << "subinterval of: ";
    t2.print();
    std::cout << std::boolalpha << t2.isSuperInterval(result) << std::endl;
}

