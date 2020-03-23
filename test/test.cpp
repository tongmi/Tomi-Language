#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    string command_buf;
    getline(cin,command_buf);
    if(command_buf=="")
    {
        cout<<"滚"<<endl;
        exit(-1);
    }
    const char *com=command_buf.data();
    char str[strlen(com)+1];
    strcpy(str,com);
    for (size_t i = 0; 1; i++)
    {
        if(str[i]=='\0')
        {
            cout <<"结束"<<endl;
            return 0;
        }
        if(str[i]==' ')
        {
            cout <<"发现空格"<<endl;
        }
    }
    
    
}