#include "Logger.h"

simpleLogger* simpleLogger::instance = NULL;

std::mutex simpleLogger::globalLogger_mutex;



simpleLogger *simpleLogger::getInstance()
{
    if(instance == NULL)
        instance = new simpleLogger();
    return instance;
}

simpleLogger::~simpleLogger()
{
    logFileWriter.close();
}

void simpleLogger::setDatetimeState(bool state)
{
    this->enableDatetime = state;
}

void simpleLogger::pushLine()
{
    std::cout << std::endl;
    if(logFileWriter.is_open())
        logFileWriter << std::endl;
}

void simpleLogger::setLogLevel(LogLevel level)
{
    currentLogLevel = level;
}

void simpleLogger::setLogFilePath(std::__cxx11::string path)
{
    if(path != "" && logFileWriter.is_open())
        logFileWriter.close();

    logFileWriter.open(path);
    logFilePath = path;
}

simpleLogger &simpleLogger::getStream(LogLevel level)
{

    //Some thread safety - not perfect
    std::lock_guard<std::mutex> lock(globalLogger_mutex);

    emptyLog = false;
    if(level > currentLogLevel)
    {
        emptyLog = true;
        //return *this;//no return, write to logfile on all debuglevels
    }
    //clear log_stream
    log_stream.str("");


    //Get time
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    //Generate loglevel output
    std::string levelStr = "";
    switch(level)
    {
    case Debug3:
        levelStr = printInColor("Debug3 ", ConsoleColor::FG_BLUE);
        break;
    case Debug2:
        levelStr = printInColor("Debug2 ", ConsoleColor::FG_BLUE);
        break;
    case Debug:
        levelStr = printInColor("Debug1 ", ConsoleColor::FG_BLUE);
        break;
    case Info:
        levelStr = printInColor("Info   ", ConsoleColor::FG_GREEN);
        break;
    case Important:
        levelStr = printInColor("Important", ConsoleColor::FG_WHITE, ConsoleColor::BG_GREEN);
        break;
    case Warning:
        levelStr = printInColor("Warning", ConsoleColor::FG_RED);
        break;
    case Error:
        levelStr = printInColor("Error  ", ConsoleColor::FG_RED, ConsoleColor::BG_YELLOW);
        break;

    case Fatal:
        levelStr = printInColor("Fatal  ", ConsoleColor::FG_RED, ConsoleColor::BG_WHITE);
        break;
    }
    if(enableDatetime)
    {
    //Write preset into log_stream
#if __GNUC__ >= 5
    log_stream<< std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << " : " << levelStr << ": ";
#else
    log_stream << ctime (&in_time_t) << " : " << levelStr << ": ";
#endif
    }
    else
    {
         log_stream<< levelStr << ": ";
    }
    //Return this as stream
    return *this;
}

simpleLogger::simpleLogger():std::ostream(this)
{

}

int simpleLogger::overflow(int c)
{
    std::string s;
    if(c!=EOF)//Check if there is a character to append
        s+=(char)c;

    if(logFileWriter.is_open())
        logFileWriter << log_stream.str() << s << std::flush;
    if(!emptyLog)
        std::cout << log_stream.str() << s << std::flush;
    log_stream.str("");
    return c;
}
