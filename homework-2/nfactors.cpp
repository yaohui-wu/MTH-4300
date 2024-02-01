#include <iostream>

int nfactors(int n);

int main()
{
    int n;

    do
    {
        std::cout << "Enter a positive integer: ";
        std::cin >> n;
    } while (n <= 0);

    int least_pos_int = nfactors(n);
    std::cout << least_pos_int << std::endl;

    return 0;
}

// Return the least positive integer which has exactly n positive integer factors.
int nfactors(int n)
{
    int factors = 0;
    int least_pos_int = 1;

    while (factors < n)
    {
        for (int i = 1; i <= least_pos_int; i++)
        {
            if (least_pos_int % i == 0)
            {
                factors++;
            }
        }

        if (factors == n)
        {
            return least_pos_int;
        }

        factors = 0;
        least_pos_int++;
    }
}