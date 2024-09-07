#include <iostream>
#include <fstream>
#include "../Headers/ComplexNumber.h"

ComplexNumber::ComplexNumber() {
	real = 0;
	imaginary = 0;
}

ComplexNumber::ComplexNumber(double _real, double _imaginary) {
	setReal(_real);
	setImaginary(_imaginary);
}

ComplexNumber::ComplexNumber(const ComplexNumber& other) {
	copyFrom(other);
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

ComplexNumber::~ComplexNumber() {
	free();
}

double ComplexNumber::getReal() const {
	return real;
}

double ComplexNumber::getImaginary() const {
	return imaginary;
}

void ComplexNumber::setReal(double _real) {
	real = _real;
}

void ComplexNumber::setImaginary(double _imaginary) {
	imaginary = _imaginary;
}

void ComplexNumber::copyFrom(const ComplexNumber& other) {
	setReal(other.getReal());
	setImaginary(other.getImaginary());
}

void ComplexNumber::free() {
	real = 0;
	imaginary = 0;
}

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	ComplexNumber result;

	result.setReal(lhs.getReal() + rhs.getReal());
	result.setImaginary(lhs.getImaginary() + rhs.getImaginary());

	return result;
}

ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	ComplexNumber result;

	result.setReal(lhs.getReal() - rhs.getReal());
	result.setImaginary(lhs.getImaginary() - rhs.getImaginary());

	return result;
}

ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	ComplexNumber result;

	result.setReal(lhs.getReal() * rhs.getReal());
	result.setImaginary(lhs.getImaginary() * rhs.getImaginary());

	return result;
}

ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	ComplexNumber result;

	result.setReal(lhs.getReal() / rhs.getReal());
	result.setImaginary(lhs.getImaginary() / rhs.getImaginary());

	return result;
}

void ComplexNumber::print() const {
	std::cout << real << " + " << imaginary << "i" << std::endl;
}

std::istream& operator>>(std::istream& input, ComplexNumber& other) {
	double _real, _imaginary;
	input >> _real >> _imaginary;

	other.setReal(_real);
	other.setImaginary(_imaginary);

	return input;
}

std::ostream& operator<<(std::ostream& output, const ComplexNumber& other) {
	output << other.getReal() << " + " << other.getImaginary() << "i";
	return output;
}