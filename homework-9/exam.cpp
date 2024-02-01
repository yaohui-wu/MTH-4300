// Exam class implementation
#include "exam.h"

void Exam::add_q(Question *question)
{
    question_list.push_back(question);
}

void Exam::run()
{
    double correct_responses = 0;

    for (int i = 0; i < question_list.size(); i++)
    {
        bool is_correct = question_list[i]->execute();

        if (is_correct)
        {
            correct_responses++;
        }
    }
    
    double grade = correct_responses / question_list.size() * 100;
    std::cout << grade << std::endl;
}