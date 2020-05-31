// file's name : expression.c   Tomi解释器
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fstream> //   getline(test,command_buf);
#include <string> //string str; getline(cin,str); data()函数返回指向自己的第一个字符的指针.  const char *str = str2.c_str();  //要加const，否则报错
#include "public.h"
#ifdef linux
    #include "include/linux/conio.h"
#endif
 
#ifdef _UNIX
    #include "include/linux/conio.h"
#endif
 
#ifdef __WINDOWS_
    #include <conio.h>
#endif
 
#ifdef _WIN32
    #include <conio.h>
#endif

using namespace std;
typedef unsigned long long size_t;
//-1 is unkonws os  0 is linux , 1 is unix , 2 is win32 ,3 is windows
size_t inum=0;//参数个数
size_t com_length=0;
extern string path;
string M_info="strcmp(command[0],\"read\")==0||strcmp(command[0],\"mengqi\")==0||strcmp(command[0],\"chenmengqi\")==0||strcmp(command[0],\"jiemei\")==0||strcmp(command[0],\"haojiemei\")==0||strcmp(command[0],\"guimi\")==0||strcmp(command[0],\"haoguimi\")==0||strcmp(command[0],\"梦琪\")==0||strcmp(command[0],\"陈梦琪\")==0||strcmp(command[0],\"姐妹\")==0||strcmp(command[0],\"好姐妹\")==0||strcmp(command[0],\"闺蜜\")==0||strcmp(command[0],\"好闺蜜\")==0)\n";
string M1_info="梦琪真的是个很好的女孩纸，太喜欢她啦，一定要好好珍惜呀！！！\n我们情同姐妹，真的很喜欢她！！";
extern string *defcm_name;
extern string *defcm_cm;
//extern dictionary<string> defcm; 
extern size_t defcm_number;
//语法分析器
int command_expression(string* buf,int* ret) throw();
//文件处理
extern int shell_files(const char*) throw();//解释文件预处理
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
    *ret=857;//记得改！！
    //命令参数 最大长度
    int com_len=0;
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
    if(str[0]=='#')
    {
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
    }

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
//mshta vbscript:msgbox("梦琪在不在",1,"在不在，一起玩呀")(window.close)
int explanation(char ** command,int* proret) throw()
{
    //cout << command[0];
    int ret=857;
    static int funmode=0;
    if(strcmp(command[0],"read")==0||strcmp(command[0],"mengqi")==0||strcmp(command[0],"chenmengqi")==0||strcmp(command[0],"jiemei")==0||strcmp(command[0],"haojiemei")==0||strcmp(command[0],"guimi")==0||strcmp(command[0],"haoguimi")==0||strcmp(command[0],"梦琪")==0||strcmp(command[0],"陈梦琪")==0||strcmp(command[0],"姐妹")==0||strcmp(command[0],"好姐妹")==0||strcmp(command[0],"闺蜜")==0||strcmp(command[0],"好闺蜜")==0)
    {
        string info0="strcmp(command[0],\"read\")==0||strcmp(command[0],\"mengqi\")==0||strcmp(command[0],\"chenmengqi\")==0||strcmp(command[0],\"jiemei\")==0||strcmp(command[0],\"haojiemei\")==0||strcmp(command[0],\"guimi\")==0||strcmp(command[0],\"haoguimi\")==0||strcmp(command[0],\"梦琪\")==0||strcmp(command[0],\"陈梦琪\")==0||strcmp(command[0],\"姐妹\")==0||strcmp(command[0],\"好姐妹\")==0||strcmp(command[0],\"闺蜜\")==0||strcmp(command[0],\"好闺蜜\")==0)\n";
        string info1="梦琪真的是个很好的女孩纸，太喜欢她啦，一定要好好珍惜呀！！！\n我们情同姐妹，真的很喜欢她！！";
        string info_type=info0+info1;
        cout << info_type <<endl;
        system("start mshta vbscript:msgbox(\"梦琪在不在\",1,\"在不在，一起玩呀\")(window.close)");
        Mengqi=true;

	    return 0;
    }
    if(strcmp(command[0],"help")==0||strcmp(command[0],"update_logs")==0||strcmp(command[0],"帮助")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        command_out(command[0],"read:It is important!");
        return ret;
    }
    if(strcmp(command[0],"import")==0||strcmp(command[0],"导入")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        if(inum==1)
        {
            return ret;
        }
        
        bool importmode=true;
        size_t i=0;
        while (importmode==true)
        {
            switch (i)
            {
            case 2:
                char temp[sizeof(command[1])+1];

                strcpy(temp,command[1]);
                if(shell_files(temp)!=2)
                {
                    importmode=false;
                }
                break;
            case 0:
                char temep[sizeof(command[1])+10];
                strcpy(temep,"import/");
                strcat(temep,command[1]);
                if(shell_files(temep)!=2)
                {
                    importmode=false;
                }
                break;
            case 1:{
                if( path.empty() )
                {
                    break;
                }
                size_t tmtest=path.length()+4;
                char temp[tmtest];
                strcpy(temp,path.c_str());
                size_t times = 0;
                for (size_t i = 0; i < tmtest; i++)
                {
                    if(temp[i]=='/'||temp[i]=='\\')
                    {
                        times=i;
                    }
                }
                temp[times+1]='\0';
                strcat(temp,command[1]);
                if(shell_files(temp)!=2)
                {
                    importmode=false;
                }
                break;
                }
            default:
                command_out(command[0],"Not found the file!");
                importmode=false;
                break;
            }
            
            i++;
        }
        
        
        return ret;
    }
    if(strcmp(command[0],"shutdown")==0||strcmp(command[0],"关机")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        system("shutdown -s");
        return ret;
    }
    if(strcmp(command[0],"reboot")==0||strcmp(command[0],"重启")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        system("shutdown -r");
        return ret;
    }
    if(strcmp(command[0],"exit")==0||strcmp(command[0],"退出")==0)
    {
        *proret=0;
        ret=-1;
	    return ret;
    }
    if(strcmp(command[0],"fun")==0||strcmp(command[0],"函数")==0)
    {
        funmode=1;
        ret=1;
	return ret;
    }
    if(strcmp(command[0],"endfun")==0||strcmp(command[0],"结束函数")==0)
    {
        funmode=0;
        ret=0;
	return ret;
    }
    if(strcmp(command[0],"pause")==0||strcmp(command[0],"按键")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        
        compile_out("Press any key to continue...",857);
        /*while(1){
        if(kbhit()){
        break;
        }
        }
        }   */
        getch();
        compile_out("");
        /*while(1)
        {
            if(kbhit())
            {
                break;
            }
        }*/
	return ret;
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
	return ret;
    }
    if(strcmp(command[0],"print")==0 || strcmp(command[0],"打印")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }

                     
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
        return ret;
    }
    if(strcmp(command[0],"syscm")==0 ||strcmp(command[0],"系统命令")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        if (inum==1)
        {
            return 0;
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
	return ret;
    }
    if(strcmp(command[0],"echo")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        if (inum==1)
        {
            return 0;
        }
        char compile_buf[com_length+inum];
        for (size_t i = 0; i <= inum-1 ; i++)
        {
            if(i==0)
            {
                strcpy(compile_buf,"\0");
            }else
            {
                strcat(compile_buf," ");
            }
            strcat(compile_buf,command[i]);
        }
        system(compile_buf);
	return ret;
    }
    if(strcmp(command[0],"defcm")==0||strcmp(command[0],"define_command")==0||strcmp(command[0],"定义命令")==0)
    {
        if(funmode==0)
        {
            ret=0;
        }
        if(inum<3)
        {
            return ret;
        }
        defcm_number++;
        
        
        string defcm_name_tmp[defcm_number-1];
        for (size_t i = 0; i < defcm_number-1; i++)
        {
            defcm_name_tmp[i]=defcm_name[i];
        }
        
        string defcm_cm_tmp[defcm_number-1];
        for (size_t i = 0; i < defcm_number-1; i++)
        {
            defcm_cm_tmp[i]=defcm_cm[i];
        }
        delete [] defcm_name;
        delete [] defcm_cm;
        defcm_name=new string[defcm_number];
        defcm_cm=new string[defcm_number];
        for (size_t i = 0; i < defcm_number-1; i++)
        {
            defcm_name[i]=defcm_name_tmp[i];
        }
        for (size_t i = 0; i < defcm_number-1; i++)
        {
            defcm_cm[i]=defcm_cm_tmp[i];
        }
        //defcm_name=(string*)realloc(defcm_name,sizeof(string)*defcm_number);
        //defcm_cm=(string*)realloc(defcm_cm,sizeof(string)*defcm_number);
        
        defcm_name[defcm_number-2]=command[1];
        
        string defcm_tmp;
        
        for (size_t i = 3; i <= inum; i++)
        {
            /* code */
            defcm_tmp=defcm_tmp+command[i-1]+" ";
        }
        
        defcm_cm[defcm_number-2]=defcm_tmp;
        
        return ret;
    }
    
    /*这里开始新代码*/
    //变量容器
    //自定义指令




    for (size_t i = 0; i < defcm_number-1; i++)
    {   
        if(command[0]==defcm_name[i])
        {  
            if(funmode==0)
            {
                ret=0;
            }
            int ret_tmp;
            command_expression(&defcm_cm[i],&ret_tmp);
            return ret;
        }
        /* code */
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

