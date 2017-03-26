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
        std::cout << "Instruction 0x" << std::hex << program_counter << ": 0x" << instruction << std::dec << std::endl;
        bool found = false;

        if(instruction == 0xCFFF)
        {
            std::cout << "Found endless loop (without content)- Aborting programm" << std::endl;
            return false;
        }
        for(auto & it: commands)
        {
            if((instruction & it.second->CommandMask()) == it.first)
            {
                uint16_t cycles = it.second->Execute(instruction,this->program_counter);
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
    this->commands.insert(std::pair<uint16_t,CommandBase*>(cmd->GetCommand(),cmd));
}
