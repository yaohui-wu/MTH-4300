// MultipleChoiceQ class implementation
#include "multchoiceq.h"
#include <fstream>

MultChoiceQ::MultChoiceQ(std::string f)
{
    std::ifstream in_file(f);
    std::getline(in_file, question_txt);
    int correct_answer_num;
    in_file >> correct_answer_num;
    int line_num = 1;
    std::string choice;
    std::getline(in_file, choice);

    while (std::getline(in_file, choice))
    {
        if (line_num == correct_answer_num)
        {
            correct_answer = choice;
        }

        choices.push_back(choice);
        line_num++;
    }

    in_file.close();
}

void MultChoiceQ::display()
{
    std::cout << question_txt << std::endl;
    
    for (int i = 0; i < choices.size(); i++)
    {
        std::cout << choices[i] << std::endl;
    }
}