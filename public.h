
//梦琪触发器
static bool Mengqi=false;

//Information for systemos
extern int os;
//debug mode
#define PROGARM_DEBUG false
//progarm mod
#define PROGRAM_MODE "default"
//progarm name
#define PROGRAM_NAME "tomi"
//program version
#define PROGRAM_VERSION "0.0.0.1-test0"
//input fun
#define SHELL_FUN "... "
//input in
#define SHELL_IN ">>> "
//information for start
#define SHELL_START "Type \"help\" or \"update_logs\" for more information."
//info out
extern void info(std::string) throw();
//debug api
extern void debug_api(bool tmp) throw();
//debug info
extern void debug_info(std::string) throw();
extern void debug_info(int) throw();
//error out
extern void error_out(std::string) throw();
//cout 857
extern void compile_out(std::string,int) throw();
extern void compile_out(std::string) throw();
//com num
extern size_t inum;
//warning info
extern void warning(std::string) throw();
//command_out
extern void command_out(char * str,std::string str_1) throw();
//dictionary
//#include "tomi_framework_dictionary.cpp"













