#include "doctest.h"
#include <stdexcept>
#include <stddef.h>
#include <iostream>
#include <sstream>

#include "Fraction.hpp"
using namespace ariel;

TEST_CASE("Constructor")
{
    // check that we can't define zero in the denominator
    CHECK_THROWS(Fraction(5, 0));
    // check that the constructor reduce the fraction
    CHECK(Fraction(3, 6) == 0.5);
    // check INTEGERS?
    CHECK(Fraction(6, 3) == 2);
}

TEST_CASE("Plus operator")
{
    Fraction a(4, 5), b(2, 10);
    // check Fraction + Fraction
    CHECK((a + b) == 1);
    // check Fraction + float
    Fraction c(8, 4);
    CHECK((c + 3.213) == 5.213);
    // check float + Fraction
    Fraction d(3, 3000);
    CHECK((3.999 + d) == 4);
}

TEST_CASE("Minus operator")
{
    Fraction a(20, 36), b(1, 18);
    // check Fraction - Fraction
    CHECK((a - b) == 0.5);
    // check Fraction - float
    Fraction c(10, 40);
    CHECK((c - 1) == -0.75);
    // check float - Fraction
    Fraction d(5, 100);
    CHECK((0.05 - d) == 0);
}

TEST_CASE("Multiplication operator")
{
    Fraction a(25, 4), b(8, 50);
    // check Fraction * Fraction
    CHECK((a * b) == 1);
    // check Fraction * float
    Fraction c(12, 100);
    CHECK((c * 0) == 0);
    // check float * Fraction
    Fraction d(12, 1000);
    CHECK((1 * d) == 0.012);
}

TEST_CASE("Division operator")
{
    Fraction a(1, 25), b(5, 4);
    // check Fraction / Fraction
    CHECK((a / b) == 0.032);
    // check Fraction / float
    Fraction c(27, 4);
    CHECK((c / 0.24) == 28.125);
    // check float / Fraction
    Fraction d(12, 448);
    CHECK((0 / d) == 0);
    // check division in 0
    Fraction e(0, 29);
    CHECK_THROWS((a / e));
}

TEST_CASE("Increase by one opertor")
{
    Fraction a(1, 25);
    // check prefix
    CHECK((++a) == 1.04);
    // check postfix
    CHECK((a++) == 1.04);
    CHECK(a == 2.04);
}

TEST_CASE("Decrease by one opertor")
{
    Fraction a(4, 100);
    // check prefix
    CHECK((a--) == 0.04);
    // check postfix
    CHECK((--a) == -1.96);
    CHECK(a == -1.96);
}

TEST_CASE("Equality opertor")
{
    Fraction a(26, 39), b(2, 3);
    // check Fraction == Fraction
    CHECK(a == b);
    // check Fraction = float
    Fraction c(-128, 1024);
    CHECK(c == -0.125);
    // check float == Fraction
    Fraction d(2045, -250);
    CHECK(d == -8.18);
}

TEST_CASE("Less-then opertor")
{
    Fraction a(26, 39), b(2, 3);
    // check Fraction < Fraction
    CHECK((a < b) == false);
    // check Fraction < float
    Fraction c(-286, 1024); //-0.279
    CHECK((c < (-0.1)) == true);
    // check float < Fraction
    Fraction d(2045, -255); //-8.019
    CHECK((-8 < d) == false);
}

TEST_CASE("Greater-then opertor")
{
    Fraction a(8, 200); // 0.04
    Fraction b(7, 49);  // 0.142
    // check Fraction > Fraction
    CHECK((b > a) == true);
    // check Fraction > float
    Fraction c(82, 4); // 20.5
    CHECK((c > 20.599) == false);
    // check float > Fraction
    Fraction d(-92, 1024); //-0.089
    CHECK((0 > d) == true);
}

TEST_CASE("Less-then or equal to opertor")
{
    Fraction a(12, 144), b(1, 12);
    // check Fraction <= Fraction
    CHECK((a <= b) == true);
    // check Fraction <= float
    Fraction c(1025, 6); // 170.833
    CHECK((c <= 170.834) == true);
    // check float <= Fraction
    Fraction d(160, -2028); //-0.078
    CHECK((-1.295 <= d) == false);
}

TEST_CASE("Greater-then or equal to opertor")
{
    Fraction a(49, 700); // 0.007
    Fraction b(-29, 58); //-0.5
    // check Fraction >= Fraction
    CHECK((b >= a) == false);
    // check Fraction >= float
    Fraction c(-56, 256); //-0.218
    CHECK((c >= 0.218) == false);
    // check float >= Fraction
    Fraction d(93, 1023); // 0.090
    CHECK((0.09 >= d) == true);
}

TEST_CASE("Output opertor")
{
    Fraction a(93, 1023);
    stringstream output;
    // check that the output operator doesn't throw an error
    CHECK_NOTHROW(output << a);
    // check that the Fraction is reduced
    CHECK(output.str() == "1/11");
}