#include <iostream>

int main()
{
    int a, b;
    std::cout << "Enter two positive integers: ";
    std::cin >> a >> b;
    
    // Euclidean algorithm.
    while (b > 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    
    std::cout << a << std::endl;

    return 0;
}