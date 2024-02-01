// Exam class header.
#ifndef EXAM_H
#define EXAM_H

#include "question.h"
#include <vector>

class Exam
{
private:
    std::vector<Question*> question_list;
public:
    void add_q(Question*);
    void run();
};

#endif