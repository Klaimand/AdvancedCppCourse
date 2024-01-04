#include "Complex.h"

Complex::Complex(double real_, double imaginary_)
{
	real = real_;
	imaginary = imaginary_;
}

Complex::Complex(const Complex& other)
{
	real = other.real;
	imaginary = other.imaginary;
}

bool Complex::operator==(const Complex& other) const
{
	return other.getImaginary() == imaginary && other.getReal() == real;
}

bool Complex::operator!=(const Complex& other) const
{
	return !(*this == other);
}

Complex Complex::operator*() const
{
	return Complex(real, -imaginary);
}



ostream& operator<<(ostream& out, const Complex& c)
{
	out << c.getImaginary() << "i+" << c.getReal();
	return out;
}

Complex operator+(const Complex& c1, const Complex& c2)
{
	return Complex(c1.getReal()+c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

Complex operator+(const Complex& c1, double d)
{
	return Complex(c1.getReal() + d, c1.getImaginary());
}

Complex operator+(double d, const Complex& c1)
{
	return Complex(c1.getReal() + d, c1.getImaginary());
}
