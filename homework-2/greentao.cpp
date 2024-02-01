#include <cmath>
#include <iostream>

const int MAX = 1000;

void longest_arithmetic_sequence();
int get_primes_size();
bool is_prime(int n);
void print_seq(int length, int first_term, int common_diff);

int main()
{
    longest_arithmetic_sequence();

    return 0;
}

/* Compute the longest arithmetic sequence composed of primes, where
the first two terms are less than 1000. */
void longest_arithmetic_sequence()
{
    int primes_size = get_primes_size();
    int primes[primes_size];
    int index = 0;

    for (int i = 2; i < MAX; i++)
    {
        if (is_prime(i))
        {
            primes[index] = i;
            index++;
        }
    }

    int max_length = 0;
    int common_diff = 1;
    int first_term = 2;

    for (int i = 0; i < primes_size; i++)
    {
        for (int j = i + 1; j < primes_size; j++)
        {
            int diff = primes[j] - primes[i];
            int next = primes[j] + diff;
            int curr_length = 2;

            while (is_prime(next))
            {
                curr_length++;
                next += diff;
            }

            if (curr_length > max_length)
            {
                max_length = curr_length;
                common_diff = diff;
                first_term = primes[i];
            }
        }
    }
    
    print_seq(max_length, first_term, common_diff);
}

// Return the number of primes that are less than 1000.
int get_primes_size()
{
    int primes_size = 0;

    for (int i = 2; i < MAX; i++)
    {
        if (is_prime(i))
        {
            primes_size++;
        }
    }

    return primes_size;
}

// Return true if n is a prime integer, false otherwise.
bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    if (n == 2 || n == 3)
    {
        return true;
    }
    
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

/* Print the length and the terms of the longest arithmetic sequence composed
of primes, where the first two terms are less than 1000. */
void print_seq(int length, int first_term, int common_diff)
{
    std::cout << length << std::endl;

    for (int i = 0; i < length; i++)
    {
        std::cout << first_term << std::endl;
        first_term += common_diff;
    }
}