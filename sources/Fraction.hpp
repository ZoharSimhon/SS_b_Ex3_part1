#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{

    class Fraction
    {
    private:
        // variebles
        int numerator_;
        int denominator_;

        // helper functions
        void reduce();
        int gcd(int, int);
        int abs(int);
        int compareTo(const Fraction &);

    public:
        // constructors
        Fraction();
        Fraction(int, int);

        // Fraction(const Fraction&);
        // Fraction &operator= (const Fraction&);
        //~Fraction();

        // overload plus operator
        Fraction operator+(const Fraction &);
        Fraction operator+(float) const;
        friend Fraction operator+(float, const Fraction &);

        // overload minus operator
        Fraction operator-(const Fraction &);
        Fraction operator-(float) const;
        friend Fraction operator-(float, const Fraction &);

        // overload multiplication operator
        Fraction operator*(const Fraction &);
        Fraction operator*(float) const;
        friend Fraction operator*(float, const Fraction &);

        // overload division operator
        Fraction operator/(const Fraction &);
        Fraction operator/(float) const;
        friend Fraction operator/(float, const Fraction &);

        // overload increase by one opertor
        Fraction operator++();    // prefix
        Fraction operator++(int); // postfix

        // overload decrease by one opertor
        Fraction operator--();    // prefix
        Fraction operator--(int); // postfix

        bool operator==(const Fraction &);
        bool operator==(float) const;
        friend bool operator==(float, const Fraction &);

        bool operator>(const Fraction &);
        bool operator>(float);
        friend bool operator>(float, const Fraction &);

        bool operator<(const Fraction &);
        bool operator<(float);
        friend bool operator<(float, const Fraction &);

        bool operator>=(const Fraction &);
        bool operator>=(float);
        friend bool operator>=(float, Fraction &);

        bool operator<=(const Fraction &);
        bool operator<=(float);
        friend bool operator<=(float, Fraction &);

        friend istream &operator>>(istream &, Fraction &);
        friend ostream &operator<<(ostream &, const Fraction &);
    };

}
