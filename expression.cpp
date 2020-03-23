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
int explanation(char**,int*) throw();
//delete .tmp
//void rmtmp();

int command_expression(string* bbuf,int* ret) throw()
{
    inum=0;
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
    ///////////////////////////////////////////
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
    /*while(inum>1)
    {
        inum--;
        printf("%s\n",outpin[inum]);


    }*/
    inum=copyi;
    fclose(test1);
    delete [] pbuf;
    if(remove(".tmp")==EOF)
    {
        compile_out("Connot delete .tmp.");
    }
    ///////////////////////////////////////////////////////////////////////
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
 
    return explanation(pingmu,ret);
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
int explanation(char ** command,int* proret) throw()
{
    //cout << command[0];
    int ret=857;
    static int funmode=0;
    /*switch (command[0])
    {
        case help:
            compile_out("Help :eeeeeeee还没想好");
            break;
        case exit:
            ret=-1;
            break;
        case fun:
            ret=1;
            break;
        default:
            compile_out("The command not found.");
            break;
    }*/
    /*
     * 模板
     * if(strcmp(command[0],"")==0)
    {
                if(funmode==0)
        {
            ret=0;
        }
        ret=;
    }
     */
    if(strcmp(command[0],"help")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        compile_out("Help :eeeeeeee还没想好");
    }
    if(strcmp(command[0],"exit")==0)
    {
        *proret=0;
        ret=-1;
    }
    if(strcmp(command[0],"fun")==0)
    {
        funmode=1;
        ret=1;
    }
    if(strcmp(command[0],"endfun")==0)
    {
        funmode=0;
        ret=0;
    }
    if(strcmp(command[0],"update_logs")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        compile_out("update_logs :eeeeeeee还没想好");
    }
    if(strcmp(command[0],"echo")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        //还要写
        compile_out(command[1]);
    }






    if(ret==857)
    {
        if(funmode==1)
        {
            compile_out("The command not found.");
            ret=2;
        }else
        {

        ret=0;
        compile_out("The command not found.");
        }
    }

    return ret;
}