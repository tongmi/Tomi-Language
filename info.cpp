#include <iostream>
#include <string>
//INFO 
void info(std::string str) throw();
//out
void compile_out(std::string) throw();

void info(std::string str) throw()
{
    std::cout<<"TOMI:"<<str<<std::endl;
}
void compile_out(std::string str) throw()
{
    std::cerr<<str<<std::endl;
}