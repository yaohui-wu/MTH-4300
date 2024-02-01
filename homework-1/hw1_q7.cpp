#include <iostream>

int main()
{
    int x, y, z;
    std::cout << "Number? ";
    std::cin >> x;
    std::cout << "Number? ";
    std::cin >> y;
    std::cout << "Number? ";
    std::cin >> z;
    int sum = x + y + z;

    while (sum != 3 * x)
    {
        x = y;
        y = z;
        std::cout << "Number? ";
        std::cin >> z;
        sum = x + y + z;
    }
    
    std::cout << "Threepeat!" << std::endl;

    return 0;
}