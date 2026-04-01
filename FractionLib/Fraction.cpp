#include "pch.h"
#include<iostream>
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
	numerator /= gcd_value;
	denominator /= gcd_value;
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
}
Fraction& Fraction::operator+=(Fraction const& v)
{
	numerator = numerator * v.denominator + v.numerator*denominator;
	denominator = denominator * v.denominator;
	reduce();
	return *this;
}
Fraction& Fraction::operator-=(Fraction const& v)
{
	numerator = numerator * v.denominator - v.numerator * denominator;
	denominator = denominator * v.denominator;
	reduce();
	return *this;
}

Fraction& Fraction::operator*=(Fraction const& v)
{
	numerator = numerator * v.numerator;
	denominator = denominator * v.denominator;
	reduce();
	return *this;
}

Fraction& Fraction::operator/=(Fraction const& v)
{
	if (v.numerator == 0)throw std::invalid_argument("Denominator can't be 0");
	numerator = numerator * v.denominator;
	denominator = denominator * v.numerator;
	reduce();
	return *this;
}

Fraction Fraction::operator-() const
{
	return Fraction(-numerator, denominator);
}

Fraction Fraction::operator+(Fraction const& v)const
{
	Fraction result(*this);
	result += v;
	return result;
}

Fraction Fraction::operator-(Fraction const& v) const
{
	Fraction result(*this);
	result -= v;
	return result;
}

Fraction Fraction::operator*(Fraction const& v) const
{
	Fraction result(*this);
	result *= v;
	return result;
}

Fraction Fraction::operator/(Fraction const& v)const
{
	if (v.numerator == 0 )throw std::invalid_argument("Denominator can't be 0");
	Fraction result(*this);
	result /= v;
	return result;
}

bool Fraction::operator==(Fraction const& v) const
{
	return numerator * v.denominator == denominator * v.numerator;
}

bool Fraction::operator!=(Fraction const& v) const
{
	return !(*this == v);
}

bool Fraction::operator<(Fraction const& v) const
{
	return numerator * v.denominator < denominator * v.numerator;
}

bool Fraction::operator>(Fraction const& v) const
{
	return v < *this;
}

bool Fraction::operator<=(Fraction const& v) const
{
	return (*this < v) || (*this == v);
}

bool Fraction::operator>=(Fraction const& v) const
{
	return !(*this < v);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
	os << f.getNumerator() << "/" << f.getDenominator();
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& f)
{
	int numerator, denominator;
	is >> numerator>>denominator;
	f = Fraction(numerator, denominator);
	return is;
}
