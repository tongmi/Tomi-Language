#include <iostream>
using namespace std;
typedef dictionary dic;
class dictionary
{
    public:
    dictionary(int * d_first_array,int * d_last_array)
    {
        first_array=d_first_array;
        last_array=d_last_array;
    }
    int * read(size_t number)
    {
        int __return__ [2];
        __return__[0]=first_array[number];
        __return__[1]=last_array[number];
        return __return__;
    }
    private:
    int * first_array=NULL;
    int * last_array=NULL;
    int array_kind=0;
};