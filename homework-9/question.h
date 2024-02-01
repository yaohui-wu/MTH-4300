// Question class header.
#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>

class Question
{
protected:
    std::string question_txt;
    std::string correct_answer;

    virtual void display();
    virtual std::string accept_response();
public:
    bool execute();
};

#endif