#include "rational.h"
#include <cmath>
#include <iostream>

// Rational numbers.
Rational::Rational()
{
    num = 0;
    den = 1;
}

Rational::Rational(int num)
{
    this->num = num;
    den = 1;
}

Rational::Rational(int num, int den)
{
    this->num = num;
    this->den = den;

    // Division by zero is undefined.
    if (this->den == 0)
    {
        this->den = 1;
    }
}

/*
Return the greatest common factor of the absolute values of the numerator and
denominator.
*/
long long Rational::gcf() const
{
    long long a = std::abs(num);
    long long b = std:: abs(den);

    // Eculidean algorithm.
    while (b != 0)
    {
        long long tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

/*
Reduce the numerator and denominator to lowest terms. If the denominator is
negative, then both numerator and denominator are multiplied by −1.
*/
void Rational::reduce()
{
    if (num == 0 || num == 1)
    {
        return;
    }

    if (den < 0)
    {
        num *= -1;
        den *= -1;
    }

    long long gcd = gcf(); // Greatest common factor.
    // Simplify.
    num /= gcd;
    den /= gcd;
}

Rational Rational::operator+=(const Rational& rhs)
{
    // Additive identity.
    if (rhs.num == 0)
    {
        return *this;
    }

    if (den == rhs.den)
    {
        num += rhs.num;
    }
    else
    {
        // Get a common denominator then add the numerators.
        long long tmp = den;
        den *= rhs.den;
        num *= rhs.den;
        num += tmp * rhs.num;
    }

    reduce();

    return *this;
}

Rational Rational::operator-=(const Rational& rhs)
{
    *this += Rational(-1) * rhs;

    return *this;
}

Rational Rational::operator*=(const Rational& rhs)
{
    // Zero-product property.
    if (rhs.num == 0)
    {
        this->num = 0;

        return *this;
    }

    num *= rhs.num;
    den *= rhs.den;
    reduce();

    return *this;
}

Rational Rational::operator/=(const Rational& rhs)
{
    // Division by zero is undefined.
    if (rhs.num == 0)
    {
        return *this;
    }

    num *= rhs.den;
    den *= rhs.num;
    reduce();

    return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    Rational res(lhs.num, lhs.den); // Result after computation.
    res += rhs;

    return res;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    Rational res(lhs.num, lhs.den); // Result after computation.
    res -= rhs;

    return res;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    Rational res(lhs.num, lhs.den); // Result after computation.
    res *= rhs;

    return res;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    Rational res(lhs.num, lhs.den); // Result after computation.
    res /= rhs;

    return res;
}

bool operator==(const Rational& lhs, const Rational& rhs)
{
    Rational x(lhs.num, lhs.den);
    Rational y(rhs.num, rhs.den);
    x.reduce();
    y.reduce();

    return x.num == y.num && x.den == y.den;
}

bool operator!=(const Rational& lhs, const Rational& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Rational& lhs, const Rational& rhs)
{
    Rational x(lhs.num, lhs.den);
    Rational y(rhs.num, rhs.den);
    x.reduce();
    y.reduce();
    // Get a common denominator then compare the numerators.
    long long tmp = x.den;
    x.den *= y.den;
    x.num *= y.den;
    y.den *= tmp;
    y.num *= tmp;

    return x.num < y.num;
}

bool operator>(const Rational& lhs, const Rational& rhs)
{
    return !(lhs < rhs) && lhs != rhs;
}

bool operator<=(const Rational& lhs, const Rational& rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator>=(const Rational& lhs, const Rational& rhs)
{
    return lhs > rhs || lhs == rhs;
}

std::ostream& operator<<(std::ostream& os, const Rational& obj)
{
    std::cout << obj.num << " / " << obj.den;

    return os;
}

std::istream& operator>>(std::istream& is, Rational& obj)
{
    char tmp;
    std::cin >> obj.num >> tmp >> obj.den;

    return is;
}