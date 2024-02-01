#include <iostream>
#include <string>

void copy(std::string* arr1, std::string* arr2, int length);

int main()
{
    std::string* arr = new std::string[5];
    int arr_length = 5;
    int index = -1;

    do
    {
        index++;

        // Allocate a new dynamic array with twice the size.
        if (index > arr_length - 1)
        {
            int old_arr_length = arr_length;
            arr_length *= 2;
            std::string* new_arr = new std::string[arr_length];
            copy(arr, new_arr, old_arr_length);
            delete[] arr;
            arr = new_arr;
        }
        
        std::cin >> arr[index];
    } while (arr[index] != "STOP");

    delete[] arr;
    
    return 0;
}

// Copy the elements of array 1 to array 2.
void copy(std::string* arr1, std::string* arr2, int length)
{
    for (int i = 0; i < length; i++)
    {
        *(arr2 + i) = *(arr1 + i);
    }
}