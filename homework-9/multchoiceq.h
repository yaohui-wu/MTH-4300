// MultipleChoiceQ class implementation.
#ifndef MULTCHOICEQ_H
#define MULTCHOICEQ_H

#include "question.h"
#include <vector>

class MultChoiceQ: public Question
{
private:
    std::vector<std::string> choices;
protected:
    virtual void display();
public:
    MultChoiceQ(std::string);
};

#endif