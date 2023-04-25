#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
using namespace ariel;

TEST_CASE("Trying to create a fraction with 0 as denominator")
{
    CHECK_THROWS_AS(Fraction(5, 0), std::invalid_argument);
}

TEST_CASE("Functions return value is a fraction")
{
    Fraction a(5,3), b(14,21), c1(7,3), c2(1,1), c3(5,2), c4(10,9);

    CHECK(a+b == c1);
    CHECK(a-b == c2);
    CHECK(a/b == c3);
    CHECK(a*b == c4);
}

TEST_CASE("Comparison operator functions are correct")
{
    Fraction a(5,3), b(14,21);

    CHECK((a == b) == false);
    CHECK((a >= b) == true);
    CHECK((a <= b) == false);
    CHECK((a < b) == false);
    CHECK((a > b) == true);
}

TEST_CASE("Postfix operator functions are correct - add/subtract 1")
{
    Fraction a(5,3), b1(8,3);
    Fraction b2 = a;

    a++;
    CHECK(a == b1);

    a--;
    CHECK(a == b2);
}

TEST_CASE("Prefix operator functions are correct")
{
    Fraction a(5,3), b1(8,3);
    Fraction b2 = a;

    CHECK(++a == b1);
    CHECK(--a == b2);
}

TEST_CASE("Stream operator functions are correct")
{
    Fraction a(5,3);

    CHECK_NOTHROW(cout << a);
}

TEST_CASE("Cant divide fraction by 0")
{
    Fraction a(5,3), b(0,8);

    CHECK_THROWS(a/b);
}

TEST_CASE("All operator functions should work on floats also")
{
    float a = 5.321, b = 4.123;

    CHECK(a+b == 9.444);
    CHECK(a-b == 1.198);
    CHECK(a*b == 21.938);
    CHECK(a/b == 1.290);
    CHECK((a == b) == false);
    CHECK((a >= b) == true);
    CHECK((a <= b) == false);
    CHECK((a < b) == false);
    CHECK((a > b) == true);
    CHECK_NOTHROW(cout << a);
    a++;
    CHECK(a == 6.321);
    a--;
    CHECK(a == 5.321);
    CHECK(++a == 6.321);
    CHECK(--a == 5.321);
}

TEST_CASE("All operator functions should work on float and fraction also")
{
    Fraction a(5,3);
    float b = 5.321;

    CHECK(b+a == 6.987);
    CHECK(a-b == -3.654);
    CHECK(b*a == 8.868);
    CHECK(a/b == 0.313);
    CHECK((b == a) == false);
    CHECK((a >= b) == false);
    CHECK((a <= b) == true);
    CHECK((a < b) == true);
    CHECK((a > b) == false);
}


