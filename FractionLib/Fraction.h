#pragma once
#include<numeric>
#include<stdexcept>
#include<string>
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
	Fraction(const std::string& str) {
		int slash_pos = str.find("/");
		numerator = stoi(str.substr(0, slash_pos));
		denominator = stoi(str.substr(slash_pos+1));
		if (denominator == 0)throw std::invalid_argument("Denominator can't be 0");
		reduce();
	};
	void reduce();
	Fraction& operator +=(Fraction  const& v);
	Fraction& operator -=(Fraction  const& v);
	Fraction& operator *=(Fraction  const& v);
	Fraction& operator /=(Fraction  const& v);
	Fraction operator -() const;
	Fraction operator +(Fraction const& v) const;
	Fraction operator -(Fraction const& v) const;
	Fraction operator *(Fraction  const& v) const;
	Fraction operator /(Fraction  const& v) const;
	bool operator ==(Fraction const& v) const;
	bool operator !=(Fraction const& v) const;
	bool operator <(Fraction const& v) const;
	bool operator >(Fraction const& v) const;
	bool operator <=(Fraction const& v) const;
	bool operator >=(Fraction const& v) const;
	friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
	friend std::istream& operator>>(std::istream& is, Fraction& f);
};

