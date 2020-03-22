// file's name : expression.c   Tomi解释器
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fstream> //   getline(test,command_buf);
#include <string> //string str; getline(cin,str); data()函数返回指向自己的第一个字符的指针.  const char *str = str2.c_str();  //要加const，否则报错
#include "public.h"
using namespace std;
//-1 is unkonws os  0 is linux , 1 is unix , 2 is win32 ,3 is windows
int inum=0;//参数个数
//语法分析器
int command_expression(string* buf,int* ret) throw();
//写临时文件
char* writetmp(string*) throw();
//获取宽度
size_t writetmp1(string *) throw();
//解释器
int explanation(char**) throw();
//delete .tmp
//void rmtmp();

int command_expression(string* bbuf,int* ret) throw()
{
    *ret=857;//记得改！！！！！
    /*if(os==0)
    {
        cout<<"TOMI:The program is runing in linux!"<<endl;
    }*/
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
 
    if (writetmp(bbuf)==NULL)
    {
        return 2;
    }

    //read .tmp
    FILE * test1=fopen(".tmp","r+");

    
    while(fscanf(test1,"%s",pbuf)==1)
    {
        inum++;
        strcpy(outpin[inum-1],pbuf);
    }
    int copyi=inum;
    while(inum>1)
    {
        inum--;
        printf("%s\n",outpin[inum]);


    }
    inum=copyi;
    fclose(test1);
    delete [] pbuf;
    if(remove(".tmp")==EOF)
    {
        //wait
    }
    //system("rm .tmp");
    //rmtmp();
    //rmdir
    char * pingmu[inum];
    for (int i = 0; i < inum; i++)
    {
        /* code */
        //int rrr=inum-i;
        pingmu[i]=outpin[i];
    }
    
    //inum=copyi;
    /*
     *
     * 下面语法解析了，outpin开始
     */
    if (outpin[0][2]=='\0')
    {
        cout <<"DEBUG:yes"<<endl;
    }
 
    return explanation(pingmu);
}
char* writetmp(string * buf) throw()
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
size_t writetmp1(string * buf) throw()
{
    const char *com=buf->data();
    return (size_t)strlen(com);

}
int explanation(char ** command) throw()
{
    cout << command[0];
    /*switch (command[0])
    {
        case :

        default:
            break;
    }*/
    return -1;
}