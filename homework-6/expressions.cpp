#include "rational.h"
#include <iostream>

void expression1();
Rational cont_frac(Rational, int);
void expression2();
void expression3();

int main()
{
    expression1();
    expression2();
    expression3();

    return 0;
}

/*
Compute a finite regular continued fraction up to the last denominator 1/8.
*/
void expression1()
{
    // Expression 1.
    // 81201 / 56660.
    Rational s1(1, 8);
    std::cout << "Expression 1 equals: " << cont_frac(s1, 8) << std::endl;
}

Rational cont_frac(Rational x, int n)
{
    // The continues fraction ends when n - 1 = 2 where n is the last denominator.
    if (n <= 2)
    {
        return Rational(1) + x;
    }

    // Calculate the last fraction at the bottom every time.
    Rational tmp1(n - 1);
    tmp1 += x;
    Rational tmp2(1);
    Rational res = tmp2 / tmp1;

    return cont_frac(res, n - 1);
}

/*
Compute the partial sum of the alternating harmonic series up to n=7.
*/
void expression2()
{
    // Expression 2.
    // 319 / 420.
    Rational s2(1);

    for (int i = 2; i <= 7; i++)
    {
        Rational tmp(1, i);

        if (i % 2 == 0)
        {
            s2 -= tmp;
        }
        else
        {
            s2 += tmp;
        }
    }
    
    s2.reduce();
    std::cout << "Expression 2 equals: " << s2 << std::endl;
}

/*
Compute the partial sum of the series of the 1/(n^3) up to n=3.
*/
void expression3()
{
    // Expression 3.
    // 256103 / 201600.
    Rational s3(1);

    for (int i = 2; i <= 5; i++)
    {
        Rational tmp(1, i * i * i);
        s3 += tmp;
    }

    s3.reduce();
    std::cout << "Expression 3 equals: " << s3 << std::endl;
}