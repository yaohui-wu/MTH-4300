#include <cmath>
#include <iostream>

int main()
{
    double x, y;
    std::cout << "Enter two positive real numbers between 0 and 1: ";
    std::cin >> x >> y;
    std::cout << sin(2 * M_PI * x) * sqrt(-2 * log(y)) << std::endl;

    return 0;
}