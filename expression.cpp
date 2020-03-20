// file's name : expression.c   Tomi解释器
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fstream> //   getline(test,command_buf);
#include <string> //string str; getline(cin,str); data()函数返回指向自己的第一个字符的指针.  const char *str = str2.c_str();  //要加const，否则报错
using namespace std;
int command_expression(string* buf,int* ret);//语法分析器


int command_expression(string* buf,int* ret)
{
    *ret=1;
    const char *com=buf->data();
    

    return 1;
}