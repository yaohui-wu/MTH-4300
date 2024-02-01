#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dist(0.0, 1.0);

const double PROB_CATCH_FIRE = 0.4;
const double PROB_BURN_OUT = 0.2;
const int simulations = 21;

void copy(char arr1[], char arr2[], int size);
bool on_fire(char arr[], int length);

int main() {
    double fire = 0;

    for (int n = 0; n < simulations; n++)
    {
        char forest[12] = {'x', 't', 't', 't', 't', 'F', 't', 't', 't', 't', 't', 'x'};

        for (int i = 0; i < 7; i++)
        {
            char temp[12];
            copy(forest, temp, 12);

            for (int j = 1; j < 11; j++)
            {
                if (temp[j] == 't'
                    && (temp[j - 1] == 'F' || temp[j + 1] == 'F')
                    && dist(gen) <= PROB_CATCH_FIRE)
                {
                    forest[j] = 'F';
                }
            }

            copy(forest, temp, 12);

            for (int k = 1; k < 11; k++)
            {
                if (temp[k] == 'F' && dist(gen) <= PROB_BURN_OUT)
                {
                    forest[k] = 'x';
                }
            }
        }

        if (on_fire(forest, 12))
        {
            fire++;
        }
    }

    double probability = fire / simulations;
    std::cout << probability << std::endl;

    return 0;
}

// Copy the elements of arr1 to arr2.
void copy(char arr1[], char arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr1[i];
    }
}

// Return true if at least one site is on fire and return false otherwise.
bool on_fire(char arr[], int length)
{
    for (int i = 1; i < length - 1; i++)
    {
        if (arr[i] == 'F')
        {
            return true;
        }
    }

    return false;
}

/*
The estimate of the probability that at least one site is still on fire after
7 days is 0.666667.
*/