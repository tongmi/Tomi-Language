// file's name : expression.c   Tomi解释器
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fstream> //   getline(test,command_buf);
#include <string> //string str; getline(cin,str); data()函数返回指向自己的第一个字符的指针.  const char *str = str2.c_str();  //要加const，否则报错
#include "public.h"
using namespace std;
//-1 is unkonws os  0 is linux , 1 is unix , 2 is win32 ,3 is windows
size_t inum=0;//参数个数
size_t com_length=0;
//语法分析器
int command_expression(string* buf,int* ret) throw();
/*
//写临时文件
char* writetmp(string*) throw();
//获取宽度
size_t writetmp1(string *) throw();
//解释器
*/
int explanation(char**,int*) throw();
//delete .tmp
//void rmtmp();

int command_expression(string* bbuf,int* ret) throw()
{
    inum=1;
    *ret=857;//记得改！！！！！
    //命令参数 最大长度
    int com_len=0;
    /*if(os==0)
    {
        cout<<"TOMI:The program is runing in linux!"<<endl;
    }*/
    int com_max_len=0;
    int last_space=-1;
    const char *com=bbuf->data();
    char *str =new char[strlen(com)+1];//缓存
    com_length=strlen(com)+1;
    strcpy(str,com);
    if(str[0]==' ')
    {
        warning("You cannot use spaces at the beginning!");
        return 0;
    }
    for (size_t i = 0; 1; i++)
    {
        if(str[i]=='\0')
        {
            break;
        }
        if(str[i]==' ')
        {
            inum++;
            if(i-last_space-1>com_max_len)
            {
                com_max_len=i-last_space;
                last_space=i;
            }else
            {
                last_space=i;
            }
            
        }
        /*if(str[i]=='\t')
        {

        }*/
    }
    //debug_info(inum);//test
    
    char outpin[inum][com_max_len+1];
    char *pingmu[inum];
    for (size_t i = 0; i < inum; i++)
    {
        pingmu[i]=outpin[i];
    }
    
    last_space=0;//this use to ...
    com_max_len=0;//用作第二维
    //write
    for (size_t i = 0; 1; i++)
    {
        //int forsig=0;
        if(str[i]=='\0')
        {
            outpin[last_space][com_max_len]='\0';
            //forsig=857;
            break;
            continue;
        }
        if(str[i]==' ')
        {
            outpin[last_space][com_max_len]='\0';
            last_space++;
            com_max_len=0;
            continue;
            
        }
        if(str[i]=='\t')
        {
            continue;
        }
        
        outpin[last_space][com_max_len]=str[i];
        com_max_len++;
        
        /*if(forsig!=0)
        {
            break;
        }*/
    }
    delete [] str;

    return explanation(pingmu,ret);

}
/*char* writetmp(string * buf) throw()
{
    FILE * test0=NULL;
    test0=fopen(".tmp","w+");
    if(test0==NULL)
    {
        return NULL;
    }
    fputs(com,test0);
    fclose(test0);
    return (char*)0x11;
}*/
/*
size_t writetmp1(string * buf) throw()
{
    const char *com=buf->data();
    return (size_t)strlen(com);

}*/
int explanation(char ** command,int* proret) throw()
{
    //cout << command[0];
    int ret=857;
    static int funmode=0;
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
    if(strcmp(command[0],"")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
    }
    if(strcmp(command[0],"help")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        command_out(command[0],"NULL");
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
        command_out(command[0],"NULL");
    }
    if(strcmp(command[0],"compile")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        char compile_buf[com_length+inum];
        for (size_t i = 1; i <= inum-1 ; i++)
        {
            if(i==1)
            {
                strcpy(compile_buf,"\0");
            }else
            {
                strcat(compile_buf," ");
            }
            strcat(compile_buf,command[i]);
        }
        system(compile_buf);

    }
    if(strcmp(command[0],"echo")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }

        //int numm=1;
        if(inum==2)
        {
            compile_out(command[1],0);
        }
        if(inum>2)
        {
            for (size_t i = 1; 1; i++)
            {
                int testt=inum-1;
                if(i>=testt)
                {
                    if(command[i][0]=='\0')
                    {
                        compile_out("",0);
                    }else
                    {
                        compile_out(command[i],0);
                    }
                    
                    break;
                }else
                {
                    if(command[i][0]=='\0')
                    {
                        compile_out(" ",857);
                    }else
                    {
                        compile_out(command[i],857);
                        compile_out(" ",857);
                    }
                }
                

            
            }
        }
        
    }






    if(ret==857)
    {
        if(funmode==1)
        {
            command_out(command[0],"Command not found.");
            ret=2;
        }else
        {
            ret=0;
            command_out(command[0],"Command not found.");
        }
    }

    return ret;
}

 /*///////////////////////////////////////////
    /*if (writetmp(bbuf)==NULL)
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


    }*//*
    inum=copyi;
    fclose(test1);
    delete [] pbuf;
    if(remove(".tmp")==EOF)
    {
        compile_out("Connot delete .tmp.");
    }*/
    ///////////////////////////////////////////////////////////////////////*/
    //system("rm .tmp");
    //rmtmp();
    //rmdir