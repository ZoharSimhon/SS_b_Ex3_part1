#include "Fraction.hpp"
#include <cmath>

using namespace ariel;

Fraction::Fraction()
{
    this->numerator_ = 0;
    this->denominator_ = 1;
    reduce();
}

Fraction::Fraction(int numerator, int denominator)
{
    this->numerator_ = numerator;
    this->denominator_ = denominator;
    reduce();
}

// Fraction::Fraction(const Fraction &otherFraction)
// {
//     this->numerator_ = otherFraction.numerator_;
//     this->denominator_ = otherFraction.denominator_;
// }
// Fraction::~Fraction()
// {
// }
// Fraction& Fraction::operator=(const Fraction &otherFraction){

// }

// helper functions
int Fraction::gcd(const Fraction &otherFraction)
{
    int minDenominator = min(this->denominator_, otherFraction.denominator_);
    for (int i = minDenominator; i >= 1; i--)
    {
        if ((this->denominator_ % i == 0) && (otherFraction.denominator_ % i == 0))
            return i;
    }
}

void Fraction::reduce()
{
    int minNum = min(this->denominator_, this->numerator_);
    for (int i = minNum; i >= 1; i--)
    {
        if ((this->denominator_ % i == 0) && (this->numerator_ % i == 0))
        {
            this->numerator_ /= i;
            this->denominator_ /= i;
            return;
        }
    }
}

// overload plus operator
Fraction &Fraction::operator+(const Fraction &otherFraction)
{
    // first, find the common divider:
    int lcm = abs(this->denominator_ * otherFraction.denominator_) / gcd(otherFraction);
    // then, multiply both fructions by the commonDivider
    int numerator1 = this->numerator_ * (lcm / this->denominator_);
    int numerator2 = otherFraction.numerator_ * (lcm / otherFraction.denominator_);
    // sum the numerators
    int sumNumerator = numerator1 + numerator2;
    // build a new fraction
    Fraction sumFraction(sumNumerator, lcm);
}
friend Fraction &Fraction::operator+(const Fraction &otherFraction, double number)
{
}
friend Fraction &Fraction::operator+(double number, const Fraction &otherFraction)
{
}

// overload minus operator
Fraction &Fraction::operator-(const Fraction &otherFraction)
{
    // first, find the common divider:
    int lcm = abs(this->denominator_ * otherFraction.denominator_) / gcd(otherFraction);
    // then, multiply both fructions by the commonDivider
    int numerator1 = this->numerator_ * (lcm / this->denominator_);
    int numerator2 = otherFraction.numerator_ * (lcm / otherFraction.denominator_);
    // sub the numerators
    int subNumerator = numerator1 + numerator2;
    // build a new fraction
    Fraction subFraction(subNumerator, lcm);
}
friend Fraction &Fraction::operator+(const Fraction &otherFraction, double number)
{
}
friend Fraction &Fraction::operator+(double number, const Fraction &otherFraction)
{
}

// overload multiplication operator


Fraction &Fraction::operator++()
{
Fraction &Fraction::operator*(const Fraction &otherFraction)
{
}
    this->numerator_ += this->denominator_;
    return *this;
}

Fraction &Fraction::operator--()
{
    this->numerator_ -= this->denominator_;
    return *this;
}
Fraction &Fraction::operator/(const Fraction &otherFraction)
{
}
bool Fraction::operator==(const Fraction &otherFraction)
{
}
bool Fraction::operator>(const Fraction &otherFraction)
{
}
bool Fraction::operator<(const Fraction &otherFraction)
{
}
bool Fraction::operator<=(const Fraction &otherFraction)
{
}
bool Fraction::operator>=(const Fraction &otherFraction)
{
}
istream &Fraction::operator>>(istream &input, Fraction &otherFraction)
{
}
ostream &Fraction::operator<<(ostream &output, Fraction &otherFraction)
{
}