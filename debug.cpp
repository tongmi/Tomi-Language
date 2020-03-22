#include "debug.h"
bool debug= false;
void debug_api(bool tmp) throw();
void debug_info(std::string) throw();

void debug_api(bool tmp) throw()
{
    debug=tmp;
    if(debug==true)
    {
        debug_info("Debug mode is running!");
    }
}
void debug_info(std::string tmp) throw()
{
    std::cout<<"DEBUG:"<<tmp<<std::endl;
}