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
        LOG(Info) << "Instruction 0x" << std::hex << program_counter*2 << ": 0x" << instruction << std::dec;
        bool found = false;

        if(instruction == 0xCFFF)
        {
            LOG(Fatal)<< "Found endless loop (without content)- Aborting programm" << std::endl;
            return Warning;
        }
        for(auto & it: commands)
        {
            if((instruction & it->CommandMask()) == (it->GetCommand() & it->CommandMask()))
            {
                LOG(Info)<< " " << it->Name() << std::endl;
#ifdef DEBUG
                LOG(Debug) << "    SREG: 0x" << std::hex << (int)this->memory_mapper->getSREG();
               LOG(Debug) << "   "<< "Stackptr: 0x" << std::hex << this->memory_mapper->getStackPtr();
                try{
                    int sp1 = this->memory_mapper->getSRAM(this->memory_mapper->getStackPtr()+1);
                    LOG(Debug) << " SP+1: 0x" << sp1;
                }catch(...){}
                try{
                    int sp2 = this->memory_mapper->getSRAM(this->memory_mapper->getStackPtr()+2);
                    LOG(Debug) << " SP+2 0x" << sp2;
                }catch(...){}
                LOG_LINE();

#endif
                uint16_t cycles = it->Execute(instruction,this->program_counter);
                this->periph_handler->handlePeriphery(cycles);
                found = true;
                return true;
            }
        }
        if(!found)
        {

            LOG(Fatal) <<std::endl << std::endl << "Illegal instruction: " << std::hex << instruction <<  std::dec << " Programcounter: " << program_counter<<std::endl;
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
    LOG(LogLevel::Info)  << "List of all known instructions: " << std::endl;
    for(auto & it: commands)
    {
        LOG(LogLevel::Info)<< "    0x" << std::hex << it->GetCommand() << std::dec  << " " << it->Name()<< std::endl;
    }
   LOG(LogLevel::Info) << "#######################################" <<std::endl;
}
