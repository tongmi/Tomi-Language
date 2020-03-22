// file's name : expression.c   Tomi解释器
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fstream> //   getline(test,command_buf);
#include <string> //string str; getline(cin,str); data()函数返回指向自己的第一个字符的指针.  const char *str = str2.c_str();  //要加const，否则报错
using namespace std;
//语法分析器
int command_expression(string* buf,int* ret);
//写临时文件
char* writetmp(string*);
//获取宽度
size_t writetmp1(string *);


int command_expression(string* bbuf,int* ret)
{
    *ret=1;
    char *pbuf=new char[(size_t)writetmp1(bbuf)+4];
    /*while (1)//seatch " "
    {
        int ii=com;
        while(1)
        {
            break;
        }
        break;
    }*/
    char outpin[(size_t)writetmp1(bbuf)+2][(size_t)writetmp1(bbuf)+4];
    int i=0;//参数个数
    if (writetmp(bbuf)==NULL)
    {
        return 2;
    }


    FILE * test1=fopen(".tmp","r+");

    
    while(fscanf(test1,"%s",pbuf)==1)
    {
        i++;
        strcpy(outpin[i-1],pbuf);
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
char* writetmp(string * buf)
{
    const char *com=buf->data();
    /*if(mode==2)
    {
        return (size_t)strlen(com);
    }*/
    FILE * test0=NULL;
    test0=fopen(".tmp","w+");
    if(test0==NULL)
    {
        return NULL;
    }
    fputs(com,test0);
    fclose(test0);
    return (char*)0x11;
}
size_t writetmp1(string * buf)
{
    const char *com=buf->data();
    return (size_t)strlen(com);

}
