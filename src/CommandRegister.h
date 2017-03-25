#ifndef COMMANDREGISTER_H
#define COMMANDREGISTER_H

#include "Processor.h"
#include "Commands/RJMP.h"
#include "Commands/NOP.h"
#include "Commands/JMP.h"
#include "Commands/LDS_MEM.h"
class CommandRegister
{
public:
    CommandRegister(Processor* processor, MemoryMapper* mapper);
};

#endif // COMMANDREGISTER_H
