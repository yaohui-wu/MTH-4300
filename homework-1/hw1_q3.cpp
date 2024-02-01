#include <iostream>
#include <random>

int main()
{
    std::random_device rd; // Introduces the Mersenne Twister random number generator
    std::mt19937 gen(rd()); // with 19937-bit state.
    std::uniform_real_distribution<> dis(0.0, 1.0); // Introduces the uniform distribution on (0,1)
    double x = dis(gen);
    double y = dis(gen);
    std::cout << sin(2 * M_PI * x) * sqrt(-2 * log(y)) << std::endl;
    
    return 0;
}