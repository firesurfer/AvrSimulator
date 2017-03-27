#include "Processor.h"

Processor::Processor(MemoryMapper *_memory_mapper, PeripheryHandler* _periph_handler)
{
    this->program_counter = 0;
    this->memory_mapper = _memory_mapper;
    this->program_memory = memory_mapper->getProgramMemory();
    this->periph_handler =_periph_handler;


}

bool Processor::ExecuteStep()
{

    if(program_counter >= program_memory->GetSize())
        return false;
    else
    {
        uint16_t instruction = program_memory->Get(program_counter);
        std::cout << "Instruction 0x" << std::hex << program_counter*2 << ": 0x" << instruction << std::dec;
        bool found = false;

        if(instruction == 0xCFFF)
        {
            std::cout << "Found endless loop (without content)- Aborting programm" << std::endl;
            return false;
        }
        for(auto & it: commands)
        {
            if((instruction & it->CommandMask()) == (it->GetCommand() & it->CommandMask()))
            {
                std::cout << " " << it->Name() << std::endl;
#ifdef DEBUG
                std::cout << "Stackptr: 0x" << std::hex << this->memory_mapper->getStackPtr() << std::dec << std::endl;
#endif
                uint16_t cycles = it->Execute(instruction,this->program_counter);
                this->periph_handler->handlePeriphery(cycles);
                found = true;
                return true;
            }
        }
        if(!found)
        {
            std::cout << "Illegal instruction: " << std::hex << instruction <<  std::dec << " Programcounter: " << program_counter<<std::endl;
            throw std::runtime_error("Error: illegal instruction!");
        }
    }
}

void Processor::RegisterCommand(CommandBase *cmd)
{
    this->commands.push_back(cmd);
}

void Processor::PrintRegisteredCommands()
{
    std::cout << "List of all known instructions: " << std::endl;
    for(auto & it: commands)
    {
        std::cout << "    0x" << std::hex << it->GetCommand() << std::dec  << " " << it->Name()<< std::endl;
    }
    std::cout << "#######################################" <<std::endl;
}
