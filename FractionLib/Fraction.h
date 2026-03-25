#pragma once
#include<numeric>
#include<stdexcept>
class Fraction
{
	int numerator;
	int denominator;
public:
	int getNumerator() const;
	int getDenominator() const;
	Fraction(int num = 0, int den = 1) :numerator(num), denominator(den) {
		if (den == 0)throw std::invalid_argument("Denominator can't be 0");
		else reduce();
	};
	void reduce();
	Fraction& operator +=(Fraction  const& v);
	Fraction& operator -=(Fraction  const& v);
	Fraction& operator *=(Fraction  const& v);
	Fraction& operator /=(Fraction  const& v);
	Fraction operator -() const;
	Fraction& operator +(Fraction & v);
	Fraction& operator -(Fraction& v);
	Fraction& operator *(Fraction  const& v);
	Fraction& operator /(Fraction  const& v);
};

