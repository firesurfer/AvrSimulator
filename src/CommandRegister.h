#ifndef COMMANDREGISTER_H
#define COMMANDREGISTER_H

#include "Processor.h"
#include "Commands/RJMP.h"
#include "Commands/NOP.h"
class CommandRegister
{
public:
    CommandRegister(Processor* processor, MemoryMapper* mapper);
};

#endif // COMMANDREGISTER_H
