#include <iostream>

// Print the elements of the array.
void print(int* ptr, int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << *(ptr + i) << " ";
    }
}

int main()
{
    // Get entries from user and store them in a dynamic array.
    std::cout << "How many entries? ";
    int num_entries;
    std::cin >> num_entries;
    int* arr;
    arr = new int[num_entries];

    for (int i = 0; i < num_entries; i++)
    {
        std::cout << "Enter an integer: ";
        std::cin >> arr[i];
    }

    print(arr, num_entries);
    std::cout << std::endl;
    delete[] arr;

    return 0;
}