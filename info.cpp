#include <iostream>
#include <string>
//INFO 
void info(std::string str) throw();

void info(std::string str) throw()
{
    std::cout<<"TOMI:"<<str<<std::endl;
}