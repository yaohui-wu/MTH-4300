#include "rational.h"
#include <iostream>

int main()
{
    // Test reduce()
    Rational a(6, 8);
    std::cout << "TEST reduce(): the following should be 6 / 8: " << a << std::endl;
    a.reduce();
    std::cout << "TEST reduce(): the following should be 3 / 4: " << a << std::endl;

    // Test +=
    Rational b(3, 2);
    b += Rational(-1, 3);
    std::cout << "TEST +=: the following should be 7 / 6: " << b << std::endl;

    // Test -=
    Rational c(3, 2);
    c -= Rational(1, 3);
    std::cout << "TEST -=: the following should be 7 / 6: " << c << std::endl;

    // Test *=
    Rational d(3, 2);
    d *= d;
    std::cout << "TEST *=: the following should be 9 / 4: " << d << std::endl;

    // Test /=
    Rational e(3, 2);
    e /= Rational(3, 4);
    std::cout << "TEST /=: the following should be 2 / 1: " << e << std::endl;

    // Test +
    std::cout << "TEST +: the following should be -38 / 3: " << Rational(7) + Rational(-59, 3) << std::endl;

    // Test -
    std::cout << "TEST -: the following should be 257 / 12: " << Rational(7, 4) - Rational(-59, 3) << std::endl;

    // Test *
    std::cout << "TEST *: the following should be -1 / 4: " << Rational(1, -6) * Rational(-3, -2) << std::endl;

    // Test /
    std::cout << "TEST /: the following should be 1 / 9: " << Rational(1, -6) / Rational(-3, 2) << std::endl;

    // Test ==
    bool condition = Rational(18, 30) == Rational(21, 35) && !(Rational(18, 30) == Rational(18, 20));
    if (condition)
    {
        std::cout << "TEST ==: passed" << std::endl;
    }
    else
    {
        std::cout << "TEST ==: failed" << std::endl;
    }

    // Test !=
    bool condition2 = !(Rational(1, 2) != Rational(-1, -2)) && (Rational(5, 7) != Rational(5, 9));
    if (condition2)
    {
        std::cout << "TEST !=: passed" << std::endl;
    }
    else
    {
        std::cout << "TEST !=: failed" << std::endl;
    }

    // Test <=
    bool condition3 = (Rational(1, 2) <= Rational(-1, -2)) && !(Rational(5, 7) <= Rational(5, 9));
    condition3 = condition3 && (Rational(-3) <= Rational(4, 7)) && (Rational(24, 7) <= Rational(14, 4));
    if (condition3)
    {
        std::cout << "TEST <=: passed" << std::endl;
    }
    else
    {
        std::cout << "TEST <=: failed" << std::endl;
    }

    // Test >=
    bool condition4 = (Rational(1, 2) >= Rational(-1, -2)) && (Rational(5, 7) >= Rational(5, 9));
    condition4 = condition4 && (Rational(4, 7) >= Rational(-3)) && !(Rational(24, 7) >= Rational(14, 4));
    if (condition4)
    {
        std::cout << "TEST >=: passed" << std::endl;
    }
    else
    {
        std::cout << "TEST >=: failed" << std::endl;
    }

    // Test <
    bool condition5 = !(Rational(1, 2) < Rational(-1, -2)) && !(Rational(5, 7) < Rational(5, 9));
    condition5 = condition5 && (Rational(-3) < Rational(4, 7)) && (Rational(24, 7) < Rational(14, 4));
    if (condition5)
    {
        std::cout << "TEST <: passed" << std::endl;
    }
    else
    {
        std::cout << "TEST <: failed" << std::endl;
    }

    // Test >
    bool condition6 = !(Rational(1, 2) > Rational(-1, -2)) && (Rational(5, 7) > Rational(5, 9));
    condition6 = condition6 && (Rational(4, 7) > Rational(-3)) && !(Rational(24, 7) > Rational(14, 4));
    if (condition6)
    {
        std::cout << "TEST >: passed" << std::endl;
    }
    else
    {
        std::cout << "TEST >: failed" << std::endl;
    }

    // Test >>
    std::cout << "TEST >>: Enter 143 / -91: ";
    Rational input;
    std::cin >> input;
    input.reduce();
    std::cout << "This should print out -11 / 7: " << input;
    std::cout << std::endl;
    
    return 0;
}