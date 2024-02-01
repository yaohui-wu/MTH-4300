#include <iostream>
#include <string>

class Student
{
public:
    std::string name; // Name of the student.
    int num_submitted; // Number of assignments currently submitted.
    int scores[10]; // Homework grades.

    Student();
    Student(std::string);
    void add_score(int);
    double average() const;
    void display() const;
};

int main()
{
    Student x;
    Student y("Evan");
    x.display();
    y.add_score(3);
    y.add_score(4);
    y.add_score(6);
    y.display();

    for (int i = 1; i <= 20; i++)
    {
        y.add_score(1);
    }
    
    y.display();

    return 0;
}

Student::Student()
{
    name = "?";
    num_submitted = 0;
}

Student::Student(std::string name)
{
    this->name = name;
    num_submitted = 0;
}

/*
Add the grade to the student's record if the number of assignments submitted
is less than 10.
*/
void Student::add_score(int score)
{
    if (num_submitted < 10)
    {
        scores[num_submitted] = score;
        num_submitted++;
    }
}

// Return the average of the student's homework grades.
double Student::average() const
{
    if (num_submitted == 0)
    {
        return 0;
    }
    
    double average = 0;

    for (int i = 0; i < num_submitted; i++)
    {
        average += scores[i];
    }
    
    average /= num_submitted;

    return average;
}

// Print the student's name and grade average.
void Student::display() const
{
    double student_average = average();
    std::cout << "Name: " << name << std::endl;
    std::cout << "Average: " << student_average << std::endl;
}