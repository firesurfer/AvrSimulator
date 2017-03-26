#include "DataMemory.h"
#include "MemoryMapper.h"
#include "ProgramMemory.h"
#include "Processor.h"
#include "CommandRegister.h"
#include "PeripheryHandler.h"
#include "PeripheryRegister.h"
int main(int argc, char* argv[])
{
    DataMemory * dataMemory = new DataMemory(2048+0x60,0);

    ProgramMemory * programMemory;

    if(argc > 1)
    {
        std::string programMemoryPath = std::string(argv[1]);
        programMemory = ProgramMemory::FromFile(programMemoryPath);
        std::cout << "Programm path: " << programMemoryPath << std::endl;
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

    std::cout << "Starting execution" << std::endl;
    int count_steps=0;
    while(processor->ExecuteStep()&&count_steps<64)
    {
        count_steps++;
    }

    std::cout << "Finished execution" << std::endl;
    std::cout << "  Execution steps:   " << count_steps << std::endl;
    std::cout << std::endl;
    std::cout << "Exit!" << std::endl;
    delete cmd_register;
    delete processor;
    delete dataMemory;
    delete programMemory;

}
