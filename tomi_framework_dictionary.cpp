#include <iostream>
#include <string>
template <class T>
class dictionary
{
    public:
    dictionary(T * d_first_array,T * d_last_array)
    {
        first_array=d_first_array;
        last_array=d_last_array;
    }
    T * read(size_t number) throw()
    {
        T __return__ [2];
        __return__[0]=first_array[number];
        __return__[1]=last_array[number];
        return __return__;
    }
    protected:
    string user_name="Dictionary";
    private:
    
    T * first_array=NULL;
    T * last_array=NULL;
    T array_kind=0;
};
