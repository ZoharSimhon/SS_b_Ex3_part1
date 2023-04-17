#include "Fraction.hpp"
using namespace ariel;

Fraction::Fraction()
{
    this->numerator_ = 0;
    this->denominator_ = 1;
}

Fraction::Fraction(int numerator, int denominator)
{
    this->numerator_ = numerator;
    this->denominator_ = denominator;
}

// Fraction::Fraction(const Fraction &otherFraction)
// {
//     this->numerator_ = otherFraction.numerator_;
//     this->denominator_ = otherFraction.denominator_;
// }

// Fraction::~Fraction()
// {
// }

Fraction& Fraction::operator+(const Fraction &otherFraction){

}
Fraction& Fraction::operator++(){
    this->numerator_ += this->denominator_;
    return *this;
}
Fraction& Fraction::operator-(const Fraction &otherFraction){
}
Fraction& Fraction::operator--(){
    this->numerator_ -= this->denominator_;
    return *this;
}
Fraction& Fraction::operator*(const Fraction &otherFraction){

}
Fraction& Fraction::operator/(const Fraction &otherFraction){

}
// Fraction& Fraction::operator=(const Fraction &otherFraction){

// }
bool Fraction::operator==(const Fraction &otherFraction){

}
bool Fraction::operator>(const Fraction &otherFraction){

}
bool Fraction::operator<(const Fraction &otherFraction){

}
bool Fraction::operator<=(const Fraction &otherFraction){

}
bool Fraction::operator>=(const Fraction &otherFraction){

}
bool Fraction::operator<<(const Fraction &otherFraction){

}
bool Fraction::operator>>(const Fraction &otherFraction){

}