#include <fstream>
#include <iostream>
#include <string>

int main()
{
    // Read the file and print the line with the longest length.
    std::ifstream in_file("sentences.txt");
    std::string s;
    std::string longest;
    int max_length = 0;

    while (std::getline(in_file, s))
    {
        if (s.size() > max_length)
        {
            longest = s;
            max_length = longest.size();
        }
    }
    
    in_file.close();
    std::cout << longest << std::endl;

    return 0;
}