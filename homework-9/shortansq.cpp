// ShortAnsQ class implementation.
#include "shortansq.h"
#include <fstream>

ShortAnsQ::ShortAnsQ(std::string f)
{
    std::ifstream in_file(f);
    std::getline(in_file, question_txt);
    std::getline(in_file, correct_answer);
    in_file.close();
}