#include <iostream>
#include <string>
//warn
void warning(std::string str) throw();


void warning(std::string str) throw()
{
    std::cerr<<"WARNING: "<<str<<std::endl;
}
