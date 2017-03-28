#include "Processor.h"

using namespace std;

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
        int sp1=0,sp2=0,sp=this->memory_mapper->getStackPtr();
        try{
            sp1 = this->memory_mapper->getSRAM(sp+1);
        }catch(...){sp1=0;}
        try{
            sp2 = this->memory_mapper->getSRAM(sp+2);
        }catch(...){sp2=0;}
        LOG(Debug) << "SREG: 0x" << hex << (int)this->memory_mapper->getSREG()
                   << "  Stackptr: 0x" << hex << sp
                   << " SP+1: 0x" << sp1
                   << " SP+2: 0x" << sp2 << endl;

        uint16_t instruction = program_memory->Get(program_counter);
        bool found = false;

        if(instruction == 0xCFFF)
        {
            LOG(Warning)<< "Found empty endless loop (0xCFFF) on address 0x" << hex << program_counter*2 << " - Aborting programm" << endl;
            return false;
        }
        for(auto & it: commands)
        {
            if((instruction & it->CommandMask()) == (it->GetCommand() & it->CommandMask()))
            {
                LOG(Info) << "Instruction 0x" << hex << program_counter*2 << ": 0x" << instruction << " " << it->Name() << endl;
                uint16_t cycles = it->Execute(instruction,this->program_counter);
                this->periph_handler->handlePeriphery(cycles);
                found = true;
                return true;
            }
        }
        if(!found)
        {
            LOG(Fatal) << "Illegal instruction: " << hex << instruction << " on address: " << program_counter*2 <<endl;
            throw runtime_error("Error: illegal instruction!");
        }
    }
}

void Processor::RegisterCommand(CommandBase *cmd)
{
    this->commands.push_back(cmd);
}

void Processor::PrintRegisteredCommands()
{
    LOG(Debug)  << "List of all known instructions: " << endl;
    for(auto & it: commands)
    {
        LOG(Debug)<< "    0x" << hex << it->GetCommand() << " " << it->Name()<< endl;
    }
   LOG(Debug) << "#######################################" << endl;
}
