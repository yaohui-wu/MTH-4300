// Question class implementation.
#include "question.h"

void Question::display()
{
    std::cout << question_txt << std::endl;
}

std::string Question::accept_response()
{
    std::string response;
    std::getline(std::cin, response);

    return response;
}

bool Question::execute()
{
    display();
    std::string response = accept_response();
    
    return response == correct_answer;
}