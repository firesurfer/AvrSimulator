#include "DataMemory.h"
#include "MemoryMapper.h"
#include "ProgramMemory.h"
#include "Processor.h"
#include "CommandRegister.h"
#include "PeripheryHandler.h"
#include "PeripheryRegister.h"
#include "Logger/Logger.h"
#include <locale>
#include <algorithm>
int main(int argc, char* argv[])
{
    LogLevel loglevel = LogLevel::Info;
    std::string programMemoryPath = "";

    for(int i = 0; i < argc;i++)
    {
        std::string arg = std::string(argv[i]);
        if( arg.find("-log") != std::string::npos)
        {
            //Okey this is the log argument
            std::string level = arg.substr(arg.find("=")+1, arg.length());
            std::transform(level.begin(), level.end(), level.begin(), ::tolower);
            if(level != "")
            {
                if(level == "debug3")
                    loglevel = LogLevel::Debug3;
                if(level == "debug2")
                    loglevel = LogLevel::Debug2;
                if(level == "debug")
                    loglevel = LogLevel::Debug;
                else if(level == "info")
                    loglevel = LogLevel::Info;
                else if(level == "important")
                    loglevel = LogLevel::Important;
                else if(level == "warning")
                    loglevel = LogLevel::Warning;
                else if(level == "wrror")
                    loglevel = LogLevel::Error;
                else if(level == "fatal")
                    loglevel = LogLevel::Fatal;
                else if(level[0] >= '0' && level[0] <= '9')
                    loglevel = (LogLevel)(level[0] - '0');
            }
        }
        //Last argument is file
        if(i+1 == argc)
            programMemoryPath = std::string(argv[i]);
    }
    LOGLEVEL(loglevel);
    DataMemory dataMemory(2048+0x60,0);

    //dataMemory->watch(0x5F); //Print important Message when changed
    dataMemory.watch(0x5F,[](uint32_t adr,uint8_t old, uint8_t nw,uint8_t &ref){if(old!=nw)LOG(Important)<<"SREG changed: "<<(int)old<<" -> "<<(int)nw<<std::endl;});//call this lambda expression when changed

    ProgramMemory * programMemory;

    if(programMemoryPath != "")
    {
        LOG(LogLevel::Info) << "Programm path: " << programMemoryPath << std::endl;
        programMemory = ProgramMemory::FromFile(programMemoryPath);
        LOGPATH(programMemoryPath + ".log");
    }
    else
    {
        throw std::runtime_error("Please pass program memory path as first argument!");
    }
    MemoryMapper dataMapper(&dataMemory, programMemory);
    PeripheryHandler periphHandler(&dataMapper);
    InterruptController intController(&dataMapper);
    PeripheryRegister::registerPeriphery(&periphHandler, &dataMapper, &intController);
    Processor processor( &dataMapper, &periphHandler, &intController);
    CommandRegister::registerCommand(&processor, &dataMapper);
    processor.PrintRegisteredCommands();
    LOG(LogLevel::Info) << "Starting execution" << std::endl;
    int count_steps=0;
    while(processor.ExecuteStep()&&count_steps<102400)
    {
        count_steps++;
    }

    LOG(LogLevel::Info) << "Finished execution" << std::endl;
    LOG(LogLevel::Info) << "Execution steps:   " << count_steps << std::endl;
    LOG(LogLevel::Info) << "Exit!" << std::endl;
    delete programMemory;
}
