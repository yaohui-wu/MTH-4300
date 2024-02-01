// main().
#include "question.h"
#include "shortansq.h"
#include "fillinq.h"
#include "multchoiceq.h"
#include "exam.h"

int main()
{
    Exam exam;
    ShortAnsQ *question1 = new ShortAnsQ("q1_sa.txt");
    FillInQ *question2 = new FillInQ("q2_fitb.txt");
    MultChoiceQ *question3 = new MultChoiceQ("q3_mc.txt");
    FillInQ *question4 = new FillInQ("q4_fitb.txt");
    MultChoiceQ *question5 = new MultChoiceQ("q5_mc.txt");
    
    exam.add_q(question1);
    exam.add_q(question2);
    exam.add_q(question3);
    exam.add_q(question4);
    exam.add_q(question5);
    exam.run();

    return 0;
}