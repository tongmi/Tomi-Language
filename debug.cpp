#include "debug.h"
bool debug= false;

void debug_api(bool tmp) throw();
void debug_info(std::string) throw();
void debug_info(int) throw();
//if debug mode ,error return -1
int if_debug() throw();

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
    if(if_debug()==-1)
    {
        return;
    }
    std::clog<<"DEBUG: "<<tmp<<std::endl;
}

void debug_info(int tmp) throw()
{
    if(if_debug()==-1)
    {
        return;
    }
    std::clog<<"DEBUG: "<<tmp<<std::endl;
}




int if_debug() throw()
{
    if(debug!=true)
    {
        //error_out("Debug mode was not runing.");
        return -1;
    }
    return 0;
}