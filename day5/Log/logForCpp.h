#pragma once
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <string>
#include <sstream>
using std::string;
using std::ostringstream;
enum Priority{
    EMERG=0,
    FATAL=0,
    ALERT=100,
    CRIT=200,
    ERROR=300,
    WARN=400,
    NOTICE=500,
    INFO=600,
    DEBUG=700,
    NOTSET=800
};
class LogForApp
{
public:
    static LogForApp* getInstance();
    static void destroy();
    void setPriority(Priority priority);
    void warn(const char* msg);
    void error(const char* msg);
    void debug(const char* msg);
    void info(const char* msg);
    void fatal(const char* msg);
private:
    LogForApp();
    ~LogForApp();
private:
    static LogForApp* _plog;
    log4cpp::Category& _rootCategory;
};
LogForApp* LogForApp::_plog=NULL;
static LogForApp* p=LogForApp::getInstance();
std::string intToString(int line);
#define msgPlus(msg) string(msg).append(" fileName:").append(__FILE__)\
                    .append(" functionName:").append(__func__).\
                    append(" line:").append(intToString(__LINE__)).c_str()
#define SetPriority(priority) p->setPriority(priority)
#define LogInfo(msg) p->info(msgPlus(msg))
#define LogError(msg) p->error(msgPlus(msg))
#define LogWarn(msg) p->warn(msgPlus(msg))
#define LogDebug(msg) p->debug(msgPlus(msg))
#define LogFatal(msg) p->fatal(msgPlus(msg))
#define LogDestroy() p->destroy()
