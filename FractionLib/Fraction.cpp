#include "pch.h"
#include "Fraction.h"
#include<numeric>

int Fraction::getNumerator() const
{
	return numerator;
}

int Fraction::getDenominator() const
{
	return denominator;
}

void Fraction::reduce()
{
	int gcd_value = std::gcd(numerator, denominator);
	numerator /= abs(gcd_value);
	denominator /= abs(gcd_value);
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
}
Fraction& Fraction::operator+=(Fraction const& v)
{
	this->numerator = numerator * v.denominator + v.numerator*denominator;
	this->denominator = denominator * v.denominator;
	reduce();
	return *this;
}
Fraction& Fraction::operator-=(Fraction const& v)
{
	this->numerator = numerator * v.denominator - v.numerator * denominator;
	this->denominator = denominator * v.denominator;
	reduce();
	return *this;
}

Fraction& Fraction::operator*=(Fraction const& v)
{
	this->numerator = numerator * v.numerator;
	this->denominator = denominator * v.denominator;
	reduce();
	return *this;
}

Fraction& Fraction::operator/=(Fraction const& v)
{
	this->numerator = numerator * v.denominator;
	this->denominator = denominator * v.numerator;
	reduce();
	return *this;
}

Fraction Fraction::operator-() const
{
	return Fraction(-numerator, denominator);
}

Fraction& Fraction::operator+(Fraction& v)
{
	v += *this;
	return v;
}


