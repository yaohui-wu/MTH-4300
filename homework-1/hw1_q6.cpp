#include <iostream>

int main()
{
    double x;
    std::cout << "Enter a positive real number: ";
    std::cin >> x;
    int terms = 1;
    double sum = 1;
    double denominator = 2;
    
    while (sum < x)
    {
        sum += 1 / denominator;
        terms++;
        denominator++;
    }
    
    std::cout << terms << std::endl;
    
    return 0;
}