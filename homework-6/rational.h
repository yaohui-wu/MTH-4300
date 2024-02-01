#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
private:
    long long num; // Numerator.
    long long den; // Denominator.

    long long gcf() const;
public:
    Rational();
    Rational(int);
    Rational(int, int);
    void reduce();
    Rational operator+=(const Rational&);
    Rational operator-=(const Rational&);
    Rational operator*=(const Rational&);
    Rational operator/=(const Rational&);

    friend Rational operator+(const Rational&, const Rational&);
    friend Rational operator-(const Rational&, const Rational&);
    friend Rational operator*(const Rational&, const Rational&);
    friend Rational operator/(const Rational&, const Rational&);
    friend bool operator==(const Rational&, const Rational&);
    friend bool operator!=(const Rational&, const Rational&);
    friend bool operator<(const Rational&, const Rational&);
    friend bool operator>(const Rational&, const Rational&);
    friend bool operator<=(const Rational&, const Rational&);
    friend bool operator>=(const Rational&, const Rational&);
    friend std::ostream& operator<<(std::ostream&, const Rational&);
    friend std::istream& operator>>(std::istream&, Rational&);
};

#endif