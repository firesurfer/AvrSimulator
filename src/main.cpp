#include "DataMemory.h"
#include "MemoryMapper.h"
#include "ProgramMemory.h"
#include "Processor.h"
#include "CommandRegister.h"
int main(int argc, char* argv[])
{
    DataMemory * dataMemory = new DataMemory(2048,0);

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
    Processor * processor = new Processor( dataMapper);
    CommandRegister* cmd_register = new CommandRegister(processor,dataMapper);


    while(processor->ExecuteStep())
    {

    }
    std::cout << "Finished execution" << std::endl;
    delete cmd_register;
    delete processor;
    delete dataMemory;
    delete programMemory;

}
