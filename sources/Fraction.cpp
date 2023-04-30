#include "Fraction.hpp"
#include <cmath>

using namespace ariel;

// constructors
Fraction::Fraction()
{
    this->numerator_ = 0;
    this->denominator_ = 1;
}
Fraction::Fraction(int numerator, int denominator)
{
    this->numerator_ = numerator;
    this->denominator_ = denominator;
    reduce();
}
Fraction::Fraction(float number)
{
    int numerator = number * 1000;
    int denominator = 1000;
    Fraction(numerator, denominator);
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
int Fraction::gcd(int number1, int number2)
{
    int absNum1 = abs(number1);
    int absNum2 = abs(number2);
    int minNum = min(absNum1, absNum2);
    for (int i = minNum; i > 0; i++)
    {
        if ((absNum1 % i == 0) && (absNum2 % i == 0))
        {
            return i;
        }
    }
}
void Fraction::reduce()
{
    int gcdNum = gcd(this->denominator_, this->numerator_);
    this->numerator_ /= gcdNum;
    this->denominator_ /= gcdNum;
}
int Fraction::abs(int number)
{
    if (number < 0)
    {
        return (-1) * number;
    }
    return number;
}

// overload plus operator
Fraction &Fraction::operator+(const Fraction &otherFraction)
{
    // first, find the common divider:
    int gcdNum = gcd(this->denominator_, otherFraction.denominator_);
    int mult = abs(this->denominator_ * otherFraction.denominator_);
    int lcm = mult / gcdNum;
    // then, multiply both fructions by the commonDivider
    int numerator1 = this->numerator_ * (lcm / this->denominator_);
    int numerator2 = otherFraction.numerator_ * (lcm / otherFraction.denominator_);
    // sum the numerators
    int sumNumerator = numerator1 + numerator2;
    // build a new fraction
    Fraction sumFraction(sumNumerator, lcm);
    return sumFraction;
}
Fraction &Fraction::operator+(float number) const
{
    Fraction floatNum(number);
    return floatNum + *this;
}
Fraction &ariel::operator+(float number, const Fraction &otherFraction)
{
    return otherFraction + number;
}

// overload minus operator
Fraction &Fraction::operator-(const Fraction &otherFraction)
{
    // first, find the common divider:
    int gcdNum = gcd(this->denominator_, otherFraction.denominator_);
    int mult = abs(this->denominator_ * otherFraction.denominator_);
    int lcm = mult / gcdNum;
    // then, multiply both fructions by the commonDivider
    int numerator1 = this->numerator_ * (lcm / this->denominator_);
    int numerator2 = otherFraction.numerator_ * (lcm / otherFraction.denominator_);
    // sub the numerators
    int subNumerator = numerator1 - numerator2;
    // build a new fraction
    Fraction subFraction(subNumerator, lcm);
    return subFraction;
}
Fraction &Fraction::operator-(float number) const
{
    Fraction floatNum(number);
    return floatNum - *this;
}
Fraction &ariel::operator-(float number, const Fraction &otherFraction)
{
    return otherFraction - number;
}

// overload multiplication operator
Fraction &Fraction::operator*(const Fraction &otherFraction)
{
    int numerator = this->numerator_ * otherFraction.numerator_;
    int denominator = this->denominator_ * otherFraction.denominator_;
    Fraction multFraction(numerator, denominator);
    return multFraction;
}
Fraction &Fraction::operator*(float number) const
{
    Fraction floatNum(number);
    return floatNum * (*this);
}
Fraction &ariel::operator*(float number, const Fraction &otherFraction)
{
    return otherFraction * number;
}

// overload division operator
Fraction &Fraction::operator/(const Fraction &otherFraction)
{
    Fraction inverseFraction(otherFraction.denominator_, otherFraction.numerator_);
    return (*this) * inverseFraction;
}
Fraction &Fraction::operator/(float number) const
{
    Fraction floatNum(number);
    return floatNum * (*this);
}
Fraction &ariel::operator/(float number, const Fraction &otherFraction)
{
    return otherFraction * number;
}

// overload increase by one opertor
Fraction &Fraction::operator++()
{
    this->numerator_ += this->denominator_;
    return *this;
}
Fraction &Fraction::operator++(int num)
{
    Fraction temp(this->numerator_, this->denominator_);
    this->numerator_ += this->denominator_;
    return temp;
}

// overload decrease by one opertor
Fraction &Fraction::operator--()
{
    this->numerator_ -= this->denominator_;
    return *this;
}
Fraction &Fraction::operator--(int num)
{
    Fraction temp(this->numerator_, this->denominator_);
    this->numerator_ -= this->denominator_;
    return temp;
}

bool Fraction::operator==(const Fraction &otherFraction)
{
    return true;
}
bool Fraction::operator>(const Fraction &otherFraction)
{
    return true;
}
bool Fraction::operator<(const Fraction &otherFraction)
{
    return true;
}
bool Fraction::operator<=(const Fraction &otherFraction)
{
    return true;
}
bool Fraction::operator>=(const Fraction &otherFraction)
{
    return true;
}

istream &ariel::operator>>(istream &input, Fraction &otherFraction)
{
    cout << "Enter Numerator ";
    input >> otherFraction.numerator_;
    cout << "Enter Denominator ";
    input >> otherFraction.denominator_;

    // first, check if the fraction is valid
    if (otherFraction.denominator_ == 0)
    {
        throw invalid_argument("0 can't be in the denominator");
    }

    // then, reduce the fruction
    reduce();

    return input;
}
ostream &ariel::operator<<(ostream &output, Fraction &otherFraction)
{
    output << otherFraction.numerator_ << '/' << otherFraction.denominator_;
    return output;
}
