#include <iostream>

int main()
{
    char c;
    std::cout << "Enter a letter: ";
    std::cin >> c;
    char next_c;

    if (c == 'Z' || c == 'z')
    {
        next_c = c - 25;
    }
    else
    {
        next_c = c + 1;
    }
    
    std::cout << next_c << std::endl;

    return 0;
}