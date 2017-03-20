#include "DataMemory.h"
#include "ProgramMemory.h"
#include "Processor.h"
int main(int argc, char* argv[])
{
    DataMemory * dataMemory = new DataMemory(2048,0x0060);
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

    Processor * processor = new Processor(32, programMemory, dataMemory);
    while(processor->ExecuteStep())
    {

    }
    std::cout << "Finished execution" << std::endl;
    delete processor;
    delete dataMemory;
    delete programMemory;

}
