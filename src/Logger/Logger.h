/*
   Copyright 2019 Friedolin Groeger, Lennart Nachtigall

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#pragma once

#include <mutex>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <ostream>
#include <streambuf>
#include <fstream>
#include "ConsoleColor.h"
#include <iostream>

typedef enum
{
    Debug3 = 7,
    Debug2 = 6,
    Debug = 5,
    Info = 4,
    Important = 3,
    Warning = 2,
    Error = 1,
    Fatal = 0

}LogLevel;


/*
 * Easy access to the simpleLogger Singleton: Usage: LOG(<LogLevel>)<< "message" << "other message" << std:endl;
 */
#define LOG(level) simpleLogger::getInstance()->getStream(level)
#define LOG_LINE simpleLogger::getInstance()->pushLine
#define LOG_APPEND (*(simpleLogger::getInstance()))

#define LOGLEVEL(level) simpleLogger::getInstance()->setLogLevel(level)
#define LOGPATH(path) simpleLogger::getInstance()->setLogFilePath(path)

class simpleLogger : public std::ostream, std::streambuf
{
public:
    /**
     * @brief getInstance
     * @return Instance of the logger singleton
     */
    static simpleLogger* getInstance();

    /**
     * @brief setLogLevel
     * @param level
     * Sets the maximum loglevel that will be printed
     */
    void setLogLevel(LogLevel level);
    /**
     * @brief setLogFilePath
     * @param path
     * Set a path for a logfile -> This will enable logging to the given file
     */
    void setLogFilePath(std::string path);
    /**
     * @brief getStream
     * @param level
     * @return The stream that is used for logging
     * See LOG(level) above for usage
     */
    simpleLogger& getStream(LogLevel level = LogLevel::Info);
    /**
     * @brief ~simpleLogger
     * Clean up of file descriptors
     */
    virtual ~simpleLogger();
    void setDatetimeState(bool state = false);
    void pushLine();
private:

    /**
     * @brief singleton instance
     */
    static simpleLogger* instance;

    static std::mutex globalLogger_mutex;
    /**
     * @brief private constructor for simpleLogger
     */
    simpleLogger();
    /**
     * Internal streams
     */
    std::stringstream log_stream;

    std::string logFilePath = "";
    std::ofstream logFileWriter;
    LogLevel currentLogLevel = LogLevel::Info;
    /**
     * @brief emptyLog - used if the current message is beneath the set log level
     */
    bool emptyLog = false;
    bool enableDatetime = false;
   


    int overflow(int c);

};

