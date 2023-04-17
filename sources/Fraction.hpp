#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{

    class Fraction
    {
    private:
        int numerator_;
        int denominator_;

    public:
        // constructors
        Fraction();
        Fraction(int, int);

        // Fraction(const Fraction&);
        // Fraction &operator= (const Fraction&);
        //~Fraction();

        // overload plus operator
        Fraction &operator+(const Fraction &);
        friend Fraction &operator+ (const Fraction&, double);
        friend Fraction &operator+ (double, const Fraction&);

        // overload minus operator
        Fraction &operator-(const Fraction &);
        friend Fraction &operator- (const Fraction&, double);
        friend Fraction &operator- (double, const Fraction&);

        // overload multiplication operator
        Fraction &operator*(const Fraction &);
        friend Fraction &operator* (const Fraction&, double);
        friend Fraction &operator* (double, const Fraction&);

        // overload division operator
        Fraction &operator/(const Fraction &);
        friend Fraction &operator/ (const Fraction&, double);
        friend Fraction &operator/ (double, const Fraction&);

        // overload increase by one opertor 
        Fraction &operator++();    // prefix
        Fraction &operator++(int); // postfix

        // overload decrease by one opertor 
        Fraction &operator--();    // prefix
        Fraction &operator--(int); // postfix

        bool operator==(const Fraction &);
        friend bool operator==(const Fraction &, double);
        friend bool operator==(double, const Fraction &);
        
        bool operator>(const Fraction &);
        friend bool operator>(const Fraction &, double);
        friend bool operator>(double, const Fraction &);
        
        bool operator<(const Fraction &);
        friend bool operator<(const Fraction &, double);
        friend bool operator<(double, const Fraction &);
        
        bool operator>=(const Fraction &);
        friend bool operator>=(const Fraction &, double);
        friend bool operator>=(double, const Fraction &);
        
        bool operator<=(const Fraction &);
        friend bool operator<=(const Fraction &, double);
        friend bool operator<=(double, const Fraction &);
        
        friend istream& operator>>(istream& input, const Fraction &);
        friend ostream& operator<<(ostream& output, const Fraction &);
    };

}
