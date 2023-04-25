/* Need to understand:
1. How to convert float to fraction, so the oprators work also with floats
2. Which methods need to be const
*/
#pragma once

#include <iostream>
#include <cmath>
using namespace std;
namespace ariel{ 

class Fraction
{
// Attributes:
int nom; // instead of "numerator"
int den; // instead of "denominator"

// Ctors:
public:
Fraction(int numer, int denom); // basic Ctor
Fraction(float value); // Ctor that get a float and convert it to a fraction - neccesary, or it happens automaticly?

/* Operator loading methods: */

friend ostream& operator<<(ostream& os, const Fraction& frac);

friend void operator>>(istream& os, Fraction& frac);

friend Fraction operator+(const Fraction& frac1, const Fraction& frac2);
friend Fraction operator-(const Fraction& frac1, const Fraction& frac2);
friend Fraction operator/(const Fraction& frac1, const Fraction& frac2);
friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
//friend Fraction operator*(const float& fl, const Fraction& frac);

friend int operator>=(const Fraction& frac1, const Fraction& frac2); // return 1 if true, else 0
friend int operator>(const Fraction& frac1, const Fraction& frac2); // return 1 if true, else 0
friend int operator<=(const Fraction& frac1, const Fraction& frac2); // return 1 if true, else 0
friend int operator<(const Fraction& frac1, const Fraction& frac2); // return 1 if true, else 0
friend int operator==(const Fraction& frac1, const Fraction& frac2); // return 1 if true, else 0

Fraction operator++(int postfix_sign);
Fraction operator--(int postfix_sign);
Fraction& operator--();
Fraction& operator++();

void reduceFraction(int& numerator, int& denominator);
int findGCD(int a, int b);

};  

}



