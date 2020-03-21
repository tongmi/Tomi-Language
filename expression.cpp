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
    char pbuf[strlen(com)+4];
    /*while (1)//seatch " "
    {
        int ii=com;
        while(1)
        {
            break;
        }
        break;
    }*/
    char outpin[strlen(com)+2][strlen(com)+4];
    int i=0;//参数个数
    FILE * test0=fopen(".tmp","w+");
    fputs(com,test0);
    fclose(test0);


    FILE * test1=fopen(".tmp","r+");

    
    while(fscanf(test1,"%s",pbuf)==1)
    {
        i++;
        strcat(outpin[i-1],pbuf);
    }
    while(i>1)
    {
        i--;
        printf("%s\n",outpin[i]);


    }
    fclose(test1);
    system("rm .tmp");
    /*
     *
     * 下面语法解析了，outpin开始
     */

 
    return 1;
}