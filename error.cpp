#include "error.h"
void error_out(std::string) throw();

void error_out(std::string err) throw()
{
    std::cerr<<std::endl<<"ERROR: "<<err<<std::endl;
}