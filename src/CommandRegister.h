#ifndef COMMANDREGISTER_H
#define COMMANDREGISTER_H

#include "Processor.h"
class CommandRegister
{
public:
    static void registerCommand(Processor* processor, MemoryMapper* mapper);
};

#endif // COMMANDREGISTER_H
