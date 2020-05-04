#include <iostream>
#include <string>
//INFO 
void info(std::string str) throw();
//out 857 was not endl
void compile_out(std::string,int) throw();
void compile_out(std::string) throw();
//notfound
void command_out(char * str,std::string str_1) throw();


void info(std::string str) throw()
{
    std::cout<<"TOMI: "<<str<<std::endl;
}
void compile_out(std::string str,int mode) throw()
{
    if (mode!=0)
    {
        /* code */
        std::cout<<str;
    }else
    {
        std::cout<<str<<std::endl;
    }
}
void compile_out(std::string str) throw()
{
    std::cout<<str<<std::endl;
}

void command_out(char * str,std::string str_1) throw()
{
    std::cout << str << ": " << str_1 <<std::endl;
}