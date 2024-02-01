#include <fstream>
#include <iostream>

int main()
{
    std::ofstream out_file("squares.txt");

    // Write the first 200 positive square integers to the file.
    for (int i = 1; i <= 200; i++)
    {
        out_file << i * i << std::endl;
    }
    
    out_file.close();

    return 0;
}