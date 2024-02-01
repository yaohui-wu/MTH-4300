// FillInQ class header.
#ifndef FILLINQ_H
#define FILLINQ_H

#include "question.h"

class FillInQ : public Question
{
private:
    int num_blanks;
protected:
    virtual std::string accept_response();
public:
    FillInQ(std::string);
};

#endif