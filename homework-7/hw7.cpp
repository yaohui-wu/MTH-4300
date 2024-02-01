// Question 1 solution.
void List::erase(int n)
{
    for (int i = n; i < num_entries - 1; i++)
    {
        listptr[n] = listptr[n + 1];
    }

    num_entries--;
}

void List::insert(int n, std::string s)
{
    if (num_entries >= capacity)
    {
        reserve();
    }

    for (int i = num_entries; i > n; i--)
    {
        listptr[i] = listptr[i - 1];
    }

    listptr[n] = s;
    num_entries++;
}

List &List::operator+=(const List &rhs)
{
    for (int i = 0; i < rhs.num_entries; i++)
    {
        this->append(rhs.listptr[i]);
    }

    return *this;
}

// Question 2 solution.
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> names;
    std::string name;

    do
    {
        std::cout << "Enter a name: ";
        std::cin >> name;
        bool is_unique = true;

        for (int i = 0; i < names.size(); i++)
        {
            if (name == names[i])
            {
                is_unique = false;
                break;
            }
        }

        if (is_unique && name != "STOP")
        {
            names.push_back(name);
        }
    } while (name != "STOP");

    std::cout << names.size() << std::endl;

    return 0;
}

// Question 3 solution.
#include "PointBag.h"

PointBag::PointBag()
{
    size = 0;
    pointarr = nullptr;
}

PointBag &PointBag::operator+=(Point rhs)
{
    Point *tmp = new Point[size];

    for (int i = 0; i < size; i++)
    {
        tmp[i] = pointarr[i];
    }

    size++;
    pointarr = new Point[size];

    for (int i = 0; i < size - 1; i++)
    {
        pointarr[i] = tmp[i];
    }

    delete[] tmp;
    pointarr[size - 1] = rhs;

    return *this;
}

double PointBag::diameter()
{
    double max_d = 0;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            double d = pointarr[i].distance(pointarr[j]);

            if (d > max_d)
            {
                max_d = d;
            }
        }
    }

    return max_d;
}

// Question 4 solution.
/*
a. 
Ctor1 (IntArray x(4);)
Ctor1 (IntArray y = 5;)
Ctor2 (IntArray z = y;)
Ctor2 (x = y;)
Op= (x = y;)
Dtor (x = y;)
Ctor1 (IntArray zzz(2);)
Dtor (IntArray zzz(2);)
Ctor1 (IntArray zzz(2);)
Dtor (IntArray zzz(2);)
Ctor1 (IntArray zzz(2);)
Dtor (IntArray zzz(2);)
*/

/*
b. x and y share the same memory so if y is changed then x will also be changed
and printing the output of x might have undefined behaviors.
*/

/*
c. x and y will have different memory so the answer in part a will not have a duplicate.
*/
/*

d. The class does not have a overloaded operator [] so we need to implement it.
Ctor1
5
Dtor
*/