#pragma once

#include <iostream>
using namespace std;

class Complex
{
private:
	double real;
	double imaginary;

public:
	Complex() = default;

	Complex(double real_, double imaginary_);

	Complex(const Complex& other);

	Complex& operator= (const Complex& complex);

	double getReal() const { return real; }
	double getImaginary() const { return imaginary; }

	bool operator==(const Complex& other) const;
	bool operator!=(const Complex& other) const;

	Complex operator*() const;
};


ostream& operator<< (ostream& out, const Complex& complex);
Complex operator+ (const Complex& c1, const Complex& c2);
Complex operator+ (const Complex& c1, double d);
Complex operator+ (double d, const Complex& c1);