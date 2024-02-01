// FillInQ class implementation.
#include "fillinq.h"
#include <fstream>

FillInQ::FillInQ(std::string f)
{
    std::ifstream in_file(f);
    std::getline(in_file, question_txt);

    std::string correct_answer_part;

    while (getline(in_file, correct_answer_part))
    {
        correct_answer += correct_answer_part + " ";
    }
    
    in_file.close();
}

std::string FillInQ::accept_response()
{
    std::string response;
    std::getline(std::cin, response);
    response += " ";

    return response;
}