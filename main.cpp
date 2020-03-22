/*
 * 头文件
 */
#include <iostream>
#include <csignal>
#include <unistd.h>
#include <fstream> //   getline(test,command_buf);
#include <string> //string str; getline(cin,str); data()函数返回指向自己的第一个字符的指针.  const char *str = str2.c_str();  //要加const，否则报错
#include "public.h"
//#include "expression.h" //解释器头文件
//#include "bufclass.h" //buf类 commandbuf公开变量  构造函数（行，最大字数）unsigned int参数 ， mode:true:启用中文支持（默认) 暂时弃用 esco
/*
 * 定义宏 (ABCDEFGHIJKLMNOPQRSTUVWXYZ)
 */
#define ERROR_0x00000001 "ERROR:Abnormal exit.(0x00000001)" //异常退出
#define ERROR_0x00000002 "ERROR:Unknow errors.(0x00000002)" //未知的错误
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
int os=-1;//-1 is unkonws os  0 is linux , 1 is unix , 2 is win32 ,3 is windows
//expression expression;//解释器对象
/*
 * 函数声明
 */
int main(int,char**); //主函数
void signalHandler(int) throw();//CTRL+c退出信号处理
int shell() throw();//shell用户交互编程
int shell(const char*) throw();//解释文件预处理
void ret_error(int) throw();//翻译错误代码
int command_main(string*,int*) throw();//对接解释器的api
int ifsystem() throw();//判断操作系统
extern int command_expression(string*,int*) throw();//命令解析，放在expression.cpp文件


/*
 * 函数定义
 */
int main(int argc,char *argv[])
{
    signal(SIGINT, signalHandler);  //注册信号和退出函数 CTRL+c的退出
    debug_api(PROGARM_DEBUG);
    int ret=0;
    ifsystem();
    if(argc==1)
    {
        ret=shell();
        if(ret!=0)
        {
            ret_error(ret);
        }
    }else{//wait 1
        int num=argc-1; 
        if(num<=0)
        {
            error_out(ERROR_0x00000002);
            return 2;
        }else{
            //有文件
            ret=shell(argv[num]);
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
        
        //raise(SIGINT);
        getline(cin,command_buf);
        sig=command_main(&command_buf,&ret);//发送给解释器并获取信号
        if(sig==1)
        {
            //break;
        }else if(sig==0)
        {
            //N
        }else
        {
            break;
        }
    }
    return ret;
}
int shell(const char *filename) throw()
{
//wait 1.
    FILE * tomi=NULL;
    tomi=fopen(filename,"r");
    if(tomi==NULL)
    {
        return 2;
    }
}
void ret_error(int ret) throw()
{
    if(ret==0)
    {
        return;
    }else if(ret==857)
    {
        error_out("DEBUG EXIT.");
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
    if(buf==NULL)
    {
        *ret=1;
        //cout << *buf<< endl;
        return 1;
    }
    return command_expression(buf,ret);
    
}
//-1 is unkonws os  0 is linux , 1 is unix , 2 is windows ,3 is win32
int ifsystem() throw()
{

 
    #ifdef linux
 
       os=0;
 
       info("TOMI:The program is runing in linux!");
 
    #endif
 
    #ifdef _UNIX
 
       os=1;
 
       info("TOMI:The program is runing in unix!");
 
    #endif
 
    #ifdef __WINDOWS_
 
       os=2;
 
       info("TOMI:The program is runing in windows!");
 
    #endif
 
    #ifdef _WIN32
 
       os=3;
 
       info("TOMI:The program is runing in win32!");
 
    #endif
    if(-1==os){
 
        info("TOMI:No OS Defined ,I do not know what the os is!");
 
    }
 
    return 0;

}
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