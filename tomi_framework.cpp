#include "main_tomi_framework.h"

using namespace std;
class tomi
{
    public:
    protected:
    size_t tomi_error_times=0;
    void tomi_print(string tomi_print) throw()
    {
        cout << tomi_print;
    }
    void tomi_error_print(string tomi_print) throw()
    {
        cout << "[TOMI-Framework-ERROR]"<<" "<<tomi_print;
        tomi_error_times++;
    }
    size_t tomi_check_error_times() throw()
    {
        return tomi_error_times;
    }
    private:
};
class user:public tomi
{
    public:
    
    /*user(string user_name_buffer,void (*user_start_function)())
    {
        user_name=user_name_buffer;
        user_start_function();
        this->user_print("The user was ready.\n");
    }*/
    /*user(string user_name_buffer)
    {
        user_name=user_name_buffer;
        
    }*/
    
    protected:
    string user_name;

    void user_print(string user_print) throw()
    {
        if(user_name.empty())
        {
            tomi_error_print("Name error.");
            return;
        }
        string buffer="[Tomi-Framework - "+user_name+"] : "+user_print;
        tomi::tomi_print(buffer);
    }
    private:
    

};
