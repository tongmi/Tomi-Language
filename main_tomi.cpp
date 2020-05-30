/*
 *
 * 头文件
 */
#include <iostream>
#include <csignal>
#include <unistd.h>
#include <thread>
#include <stdlib.h>
#include <cstring>
#include <fstream> //   getline(test,command_buf);
#include <string> //string str; getline(cin,str); data()函数返回指向自己的第一个字符的指针.  const char *str = str2.c_str();  //要加const，否则报错
#include "public.h"
//#include "expression.h" //解释器头文件
//#include "bufclass.h" //buf类 commandbuf公开变量  构造函数（行，最大字数）unsigned int参数 ， mode:true:启用中文支持（默认) 暂时弃用 esco
/*
 * 定义宏 (ABCDEFGHIJKLMNOPQRSTUVWXYZ)
 */
#define ERROR_0x00000001 "Abnormal exit.(0x00000001)" //异常退出
#define ERROR_0x00000002 "Unknow errors.(0x00000002)" //未知的错误
/*
 * 命名空间（创建与使用）
 */
using namespace std;
//using namespace expression;// 使用解释器的命名空间 建议取消 已弃用
/*
 * 声明定义全局变量 
 */

//char *command=NULL;//执行语句   暂时弃用
//int *command_int=NULL;//执行语句(INT)   暂时弃用
string command_buf;//命令缓存
//定义命令缓存
string *defcm_name;
string *defcm_cm;
//dictionary<string> defcm(defcm_name,defcm_cm); 
size_t defcm_number=1;
int os=-1;//-1 is unkonws os  0 is linux , 1 is unix , 2 is win32 ,3 is windows
//expression expression;//解释器对象
/*
 * 函数声明
 */
int main_tomi(int,char**) throw(); //主函数
void signalHandler(int) throw();//CTRL+c退出信号处理
int shell() throw();//shell用户交互编程
int shell_files(const char*) throw();//解释文件预处理
void ret_error(int) throw();//翻译错误代码
int command_main(string*,int*) throw();//对接解释器的api
int ifsystem() throw();//判断操作系统
extern int compile_main(char*) throw(); //compile.cpp
extern int command_expression(string*,int*) throw();//命令解析，放在expression.cpp文件


/*
 * 函数定义
 */
int main_tomi(int argc,char *argv[]) throw()
{
    //cout << argv[1]<<endl;
    signal(SIGINT, signalHandler);  //注册信号和退出函数 CTRL+c的退出
    debug_api(PROGARM_DEBUG);
    /*defcm_name=new string[1];
    defcm_cm=new string[1];*/
    defcm_name=new string[1];
    defcm_cm=new string[1];
    //dictionary<string> defcm(defcm_name,defcm_cm); 
    int ret=0;
    
    if(argc==1)
    {
        ifsystem();
        ret=shell();
        if(ret!=0)
        {
            ret_error(ret);
        }else
        {
            compile_out("Program exit.",0);
        }
    }else{//wait 1
        int num=argc-1; 
        if(num<=0)
        {
            error_out(ERROR_0x00000002);
            return 2;
        }else if(num>1)
        {
            if(strcmp(argv[1],"-c")==0)
            {
                //跳转compile_main.cpp
                ret=compile_main(argv[2]);
            }else
            {
                error_out("Not found this command!");
                ret=-1;
            }
            
        }else
        {
            //有文件
            ret=shell_files(argv[1]);
	
            if(ret!=0)
            {
                ret_error(ret);
            }
        }
    }
    return ret;
}
void signalHandler(int signum) throw()
{
    //可以不用去掉cout


    cout << "\nInterrupt signal (" << signum << ") received." << endl;
    cout << "Exit(" << signum << ")." << endl;


    // 清理并关闭
    // 终止程序  
    exit(signum);  
}
int shell() throw()
{
    // 返回值 canoot rm cout
    int ret=0;
    int sig=0;


    cout << PROGRAM_NAME << " " << PROGRAM_VERSION << " (" << PROGRAM_MODE << ", " << __DATE__ << ", " << __TIME__ << ")" << endl;
    cout << SHELL_START << endl;


    while(1)
    {
        //正常：0/1/                 -1
        if(sig==1)
        {


            cout << SHELL_FUN;


        }else{


            cout << SHELL_IN;
            

        }
        //command_buf="";
        //raise(SIGINT);
        getline(cin,command_buf);
        if(command_buf.empty())
        {
            continue;
        }
        sig=command_main(&command_buf,&ret);//发送给解释器并获取信号
        if(sig==1)
        {
            //break;
        }else if(sig==0)
        {
            //N
        }else if(sig==2)
        {
            sig=1;
        }else
        {
            break;
        }
    }
    return ret;
}
int shell_files(const char *filename) throw()
{
//wait 1.
    char shell_buf_c=0;
    size_t shell_buf_s_size=4;
    //compile_out("\n",857)

    FILE * tomi=NULL;
    int reet=0;
    tomi=fopen(filename,"r");
    if(tomi==NULL)
    {
        return 2;
    }
    while (1)
    {
        //857表示还有出现过，0表示正常
        int has_spaces=857;
        int sig_ret=0;
        shell_buf_s_size=4;
        char *shell_buf_s=(char*)malloc(2);
        strcpy(shell_buf_s,"\0");
        while (1)
        {
            if(fscanf(tomi,"%c",&shell_buf_c)==-1)
            {
                strcat(shell_buf_s,"\0");
                sig_ret=-1;
                string cbuf=shell_buf_s;
		    if(cbuf=="exit")                                
            {                                                    
                sig_ret=-1;
                break;
            }
                command_main(&cbuf,&reet);
                break;
            }
            if(shell_buf_c=='\n')
            {
                strcat(shell_buf_s,"\0");
                string ccbuf=shell_buf_s;
                if(ccbuf=="\0")
                {
                    break;
                }
		        if(ccbuf=="exit")
		        {
		            sig_ret=-1;
		            break;
		        }
                command_main(&ccbuf,&reet);
                break;
            }
            if(shell_buf_c==' ')
            {
                if(has_spaces==857)
                {
                    continue;
                }
            }
            if(shell_buf_c=='\t')
            {
                if(has_spaces==857)
                {
                    continue;
                }
            }
            has_spaces=0;
            shell_buf_s_size++;
            shell_buf_s=(char*)realloc(shell_buf_s,shell_buf_s_size);
            char shell_while_buf[2];
            shell_while_buf[0]=shell_buf_c;
            shell_while_buf[1]='\0';
            strcat(shell_buf_s,shell_while_buf);
            
        }
        free(shell_buf_s);
        if(sig_ret==-1)
        {
	        reet=0;
            break;
        }
    }
    return reet;

}
void ret_error(int ret) throw()
{
    if(ret==0)
    {
        return;
    }else if(ret==857)
    {
        error_out("ERROR EXIT.");
    }else if(ret<0)
    {
        error_out(ERROR_0x00000002);
        return;
    }
    switch(ret)
    {
        case 1:
            error_out(ERROR_0x00000001);
            break;
        case 2:
            error_out(ERROR_0x00000002);
            break;
        default:
            if(ret==857)
            {
                return;
            }
            error_out(ERROR_0x00000002);
            break;
    }
    return;
}
int command_main(string* buf,int* ret) throw()
{
    return command_expression(buf,ret);
}
//-1 is unkonws os  0 is linux , 1 is unix , 2 is windows ,3 is win32
int ifsystem() throw()
{

 
    #ifdef linux
 
       os=0;
 
       info("The program is running in linux!(UTF-8)");
 
    #endif
 
    #ifdef _UNIX
 
       os=1;
 
       info("The program is running in unix!(UTF-8)");
 
    #endif
 
    #ifdef __WINDOWS_
 
       os=2;
 
       info("The program is running in windows!(GBK)");
 
    #endif
 
    #ifdef _WIN32
 
       os=3;
 
       info("The program is running in win32!(GBK)");
 
    #endif
    if(-1==os){
 
        info("No OS Defined ,I do not know what the os is!");
    }
 
    return 0;

}
/*static char* U2G(const char* utf8) {
  int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
  wchar_t* wstr = new wchar_t[len + 1];
  memset(wstr, 0, len + 1);
  MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
  len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
  char* str = new char[len + 1];
  memset(str, 0, len + 1);
  WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
  if (wstr) delete[] wstr;
  return str;
}*/
/* 笔记 信号处理
 * SIGABRT	程序的异常终止，如调用 abort。
 * SIGFPE	错误的算术运算，比如除以零或导致溢出的操作。
 * SIGILL	检测非法指令。
 * SIGINT	接收到交互注意信号。
 * SIGSEGV	非法访问内存。
 * SIGTERM	发送到程序的终止请求。
 * void (*signal (int sig, void (*func)(int)))(int);  注册信号以及处理函数
 * int raise (signal sig);  发生信号
 * 1Ghz 单核运算能力：1,073,741,824 （10亿次）
 * virtual虚函数定义
 * template <typename T>
 * 函数模板演示：/////
 * template <class type> ret-type func-name(parameter list)
 *{
 * // 函数的主体
 * }
 * 例子：
 *
 * inline T const& Max (T const& a, T const& b) 
 * { 
 *   return a < b ? b:a; 
 * } 
 * 类模板
 * template <class type> class class-name {} 对象创建：Stack<int> /////
 * cin>>noskipws>>input[j];//不想略过空白字符，那就使用 noskipws 流控制
 * cin.get(字符变量名)可以用来接收字符
 */
