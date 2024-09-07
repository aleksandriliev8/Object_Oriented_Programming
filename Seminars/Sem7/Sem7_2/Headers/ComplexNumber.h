#pragma once

class ComplexNumber {
private:
	double real;
	double imaginary;

	void copyFrom(const ComplexNumber& other);
	void free();
public:
	ComplexNumber();
	ComplexNumber(double, double);
	ComplexNumber(const ComplexNumber& other);
	ComplexNumber& operator=(const ComplexNumber& other);
	~ComplexNumber();

	double getReal() const;
	double getImaginary() const;

	void setReal(double _real);
	void setImaginary(double _imaginary);

	void print() const;

	friend std::istream& operator>>(std::istream& input, ComplexNumber& other);
	friend std::ostream& operator<<(std::ostream& output, const ComplexNumber& other);
};

ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs);