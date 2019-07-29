/**********************************************************
 * Author        : Vigoroushui
 * Email         : vigoroushui@gmail.com
 * Last modified : 2019-07-29 10:29
 * Filename      : logForCpp.cc
 * Description   : logForCpp头文件中类的函数对象的实现
                   以及对封装效果的测试
 * *******************************************************/
#include "logForCpp.h"
using std::cout;
LogForApp* LogForApp::_plog=NULL;

LogForApp::LogForApp()
:_rootCategory(log4cpp::Category::getRoot().getInstance("_rootCategory"))
{
    //输出到终端
    log4cpp::OstreamAppender* ostreamAppender=new log4cpp::OstreamAppender(
        "ostreamAppender",
        &cout);
    log4cpp::PatternLayout* patternLayout1=new log4cpp::PatternLayout();
    patternLayout1->setConversionPattern("%d: %p %c %x:%m%n");
    ostreamAppender->setLayout(patternLayout1);
    _rootCategory.addAppender(ostreamAppender);
    _rootCategory.setPriority(log4cpp::Priority::DEBUG);
    //备份带回卷的日志文件记录方式，默认10M，此处设置为8M，备份文件8个
    log4cpp::RollingFileAppender* rollingFileAppender=new log4cpp::RollingFileAppender(
        "rollingFileAppender",
        "logRolling",
        8*1024,
        8);
    log4cpp::PatternLayout* patternLayout2=new log4cpp::PatternLayout();
    patternLayout2->setConversionPattern("%d: %p %c %x:%m%n");
    rollingFileAppender->setLayout(patternLayout2);
    _rootCategory.addAppender(rollingFileAppender);
    _rootCategory.setPriority(log4cpp::Priority::DEBUG);
    
    _rootCategory.info("LogForApp()");
}

LogForApp::~LogForApp()
{
    _rootCategory.info("~LogForApp()");
    _rootCategory.shutdown();
}

LogForApp* LogForApp::getInstance()
{
    if(NULL==_plog)
    {
        _plog=new LogForApp();
    }
    return _plog;
}

void LogForApp::destroy()
{
    _plog->_rootCategory.info("destroy()");
    if(_plog)
    {
        delete _plog;
        _plog=NULL;
    }
}

void LogForApp::setPriority(Priority priority)
{
    switch(priority)
    {
        case WARN:_rootCategory.setPriority(log4cpp::Priority::WARN);break;
        case ERROR:_rootCategory.setPriority(log4cpp::Priority::ERROR);break;
        case DEBUG:_rootCategory.setPriority(log4cpp::Priority::DEBUG);break;
        case INFO:_rootCategory.setPriority(log4cpp::Priority::INFO);break;
        case FATAL:_rootCategory.setPriority(log4cpp::Priority::FATAL);break;
        default:
            _rootCategory.setPriority(log4cpp::Priority::DEBUG);break;
    }
}

void LogForApp::warn(const char* msg)
{
    _rootCategory.warn(msg);
}

void LogForApp::error(const char* msg)
{
    _rootCategory.error(msg);
}

void LogForApp::debug(const char* msg)
{
    _rootCategory.debug(msg);
}

void LogForApp::info(const char* msg)
{
    _rootCategory.info(msg);
}

void LogForApp::fatal(const char* msg)
{
    _rootCategory.fatal(msg);
}

string intToString(int line)
{
    ostringstream oss;
    oss<<line;
    return oss.str();
}
void func()
{
    LogInfo("this is func");
}
int main(void)
{
    //p->warn("this is a warning!");
    //p->destroy();
    func();
    LogInfo("this is a info");
    LogWarn("system has a warning");
    LogFatal("system has a fatal");
    LogError("system has a error");
    LogDestroy();
}
    
