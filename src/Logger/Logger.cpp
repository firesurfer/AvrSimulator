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
    if(logFileWriter != NULL)
    {
        logFileWriter->flush();
        delete logFileWriter;
    }

}

void simpleLogger::setLogLevel(LogLevel level)
{
    currentLogLevel = level;
}

void simpleLogger::setLogFilePath(std::__cxx11::string path)
{
    std::ofstream writer(path);
    if(writer.is_open())
    {
        if(logFilePath == "" && path != "")
            logFileWriter = new std::ofstream(path);
        else
        {
            delete logFileWriter;
            if(path != "")
                logFileWriter = new std::ofstream(path);
        }
        this->logFilePath = path;
    }
}

simpleLogger &simpleLogger::getStream(LogLevel level)
{

    //Some thread safety - not perfect
    std::lock_guard<std::mutex> lock(globalLogger_mutex);

    emptyLog = false;
    if(level < currentLogLevel)
    {
        emptyLog = true;
        return *this;
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
    case Debug:
        levelStr = printInColor("Debug", ConsoleColor::FG_DEFAULT, ConsoleColor::BG_GREEN);
        break;
    case Info:
        levelStr = printInColor("Info ", ConsoleColor::FG_GREEN);
        break;
    case Important:
        levelStr = printInColor("Important ", ConsoleColor::FG_BLUE);
        break;
    case Warning:
        levelStr = printInColor("Warning ", ConsoleColor::FG_RED);
        break;
    case Error:
        levelStr = printInColor("Error ", ConsoleColor::FG_RED, ConsoleColor::BG_YELLOW);
        break;

    case Fatal:
        levelStr = printInColor("Fatal ", ConsoleColor::FG_RED, ConsoleColor::BG_WHITE);
        break;
    }
    //Write preset into log_stream
#if __GNUC__ >= 5
    log_stream<< std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << " : " << levelStr << " : ";
#else
    log_stream << ctime (&in_time_t) << " : " << levelStr << " : ";
#endif

    //Return this as stream
    return *this;
}




simpleLogger::simpleLogger():std::ostream(this)
{

}

int simpleLogger::overflow(int c)
{
    char ch = (char)c;
    if(ch == '\n')
    {
        if(emptyLog)
            return 0;
        std::cout << log_stream.str()  << std::endl;
        if(logFilePath != "")
            *logFileWriter << log_stream.str() << std::endl;
        log_stream.str("");

    }
    else
    {
        if(emptyLog)
            return 0;
        log_stream << ch;

    }
    return 0;
}
