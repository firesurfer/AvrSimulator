#include "CommandRegister.h"

CommandRegister::CommandRegister(Processor *processor, MemoryMapper *mapper)
{
    RJMP* rjmp_cmd = new RJMP(mapper);
    NOP* nop_cmd = new NOP(mapper);
    JMP * jmp_cmd = new JMP(mapper);
    LDS_MEM * lds_mem_cmd = new LDS_MEM(mapper);

    processor->RegisterCommand(rjmp_cmd);
    processor->RegisterCommand(nop_cmd);
    processor->RegisterCommand(jmp_cmd);
    processor->RegisterCommand(lds_mem_cmd);
}
