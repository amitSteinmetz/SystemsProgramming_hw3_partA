#include "Fraction.hpp"
//using namespace ariel;

namespace ariel {

Fraction::Fraction(int numer, int denom)
{
	if (denom != 0)
	{
		nom = numer;
		den = denom;
	}
	
}

Fraction::Fraction(float value) {
	int numerator = int(value * 1000);
	int denominator = 1000;
	reduceFraction(numerator, denominator);
	nom = numerator;
	den = denominator;
}

void Fraction::reduceFraction(int& numerator, int& denominator) {
	int gcd = findGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}
    
int Fraction::findGCD(int a, int b) {
	if (b == 0) { 
		return a;
	}
	return findGCD(b, a % b);
}

Fraction Fraction::operator++(int postfix_sign)
{
	return Fraction(nom+den,den);
};

Fraction Fraction::operator--(int postfix_sign)
{
	return Fraction(nom-den, den);
};

Fraction& Fraction::operator--()
{
    Fraction& rfrac = *this;
    return rfrac;
};

Fraction& Fraction::operator++()
{
	Fraction& rfrac = *this;
    return rfrac;
}

ostream& operator<<(ostream& os, const Fraction& frac)
{
	return os << frac.nom << "/" << frac.den;
};
void operator>>(istream& os, Fraction& frac){};

Fraction operator+(const Fraction& frac1, const Fraction& frac2) {return Fraction(0,0);};
Fraction operator-(const Fraction& frac1, const Fraction& frac2) {return Fraction(0,0);};
Fraction operator/(const Fraction& frac1, const Fraction& frac2) {return Fraction(0,0);};
Fraction operator*(const Fraction& frac1, const Fraction& frac2) {return Fraction(frac1.nom*frac2.nom,frac1.den*frac2.den);};
//Fraction operator*(const float& fl, const Fraction& frac) {return Fraction(0,0);};

int operator>=(const Fraction& frac1, const Fraction& frac2) {return 1;}; // return 1 if true, else 0
int operator>(const Fraction& frac1, const Fraction& frac2) {return 1;}; // return 1 if true, else 0
int operator<=(const Fraction& frac1, const Fraction& frac2) {return 1;}; // return 1 if true, else 0
int operator<(const Fraction& frac1, const Fraction& frac2) {return 1;}; // return 1 if true, else 0
int operator==(const Fraction& frac1, const Fraction& frac2) {return 1;}; // return 1 if true, else 0

}