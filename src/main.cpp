#include "DataMemory.h"
#include "MemoryMapper.h"
#include "ProgramMemory.h"
#include "Processor.h"
#include "CommandRegister.h"
#include "PeripheryHandler.h"
#include "PeripheryRegister.h"
#include "Logger/Logger.h"
int main(int argc, char* argv[])
{
    DataMemory * dataMemory = new DataMemory(2048+0x60,0);

    ProgramMemory * programMemory;

    if(argc > 1)
    {
        std::string programMemoryPath = std::string(argv[1]);
        LOG(LogLevel::Info) << "Programm path: " << programMemoryPath << std::endl;
        programMemory = ProgramMemory::FromFile(programMemoryPath);

    }
    else
    {
        throw std::runtime_error("Please pass program memory path as first argument!");
    }
    MemoryMapper *dataMapper = new MemoryMapper(dataMemory, programMemory);
    PeripheryHandler* periphHandler = new PeripheryHandler(dataMapper);
    PeripheryRegister * periphRegister = new PeripheryRegister(periphHandler,dataMapper);
    Processor * processor = new Processor( dataMapper,periphHandler);
    CommandRegister* cmd_register = new CommandRegister(processor,dataMapper);
    processor->PrintRegisteredCommands();
    LOG(LogLevel::Info) << "Starting execution" << std::endl;
    int count_steps=0;
    while(processor->ExecuteStep()&&count_steps<64)
    {
        count_steps++;
    }

     LOG(LogLevel::Info) << "Finished execution" << std::endl;
     LOG(LogLevel::Info) << "  Execution steps:   " << count_steps << std::endl;
     LOG(LogLevel::Info)<< std::endl;
     LOG(LogLevel::Info) << "Exit!" << std::endl;
    delete cmd_register;
    delete processor;
    delete dataMemory;
    delete programMemory;

}
