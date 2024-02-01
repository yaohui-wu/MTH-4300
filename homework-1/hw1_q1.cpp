#include <iostream>
#include <string>

int main()
{
    std::string name;
    int month, day, year;
    std::cout << "Enter your name and date of birth: ";
    std::cin >> name >> month >> day >> year;
    std::cout << name << "\'s birthday is " << month << "/" << day << "/"
    << year << "." << std::endl;
    
    return 0;
}

/*
Input: Sue Ann 12 11 2010
Output: Sue's birthday is 0/garbage value/garbage value.
Input: Peter
Output: The program does not display anything because it is waiting for the
other inputs.
Input: Frank 4/8/1912
Output: Frank's birthday is 4/0/garbage value.
*/