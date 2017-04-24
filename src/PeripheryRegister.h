#ifndef PERIPHERYREGISTER_H
#define PERIPHERYREGISTER_H
#include "PeripheryHandler.h"
#include "InterruptController.h"

class PeripheryRegister
{
public:
    static void registerPeriphery(PeripheryHandler* handler, MemoryMapper* mapper, InterruptController* intController);
};

#endif // PERIPHERYREGISTER_H
