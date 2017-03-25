#ifndef PERIPHERYHANDLER_H
#define PERIPHERYHANDLER_H

#include "MemoryMapper.h"

class PeripheryHandler
{
public:
    PeripheryHandler(MemoryMapper* _mem_mapper);
    void handlePeriphery(uint16_t cycles);
private:
    MemoryMapper* memory_mapper;
};

#endif // PERIPHERYHANDLER_H
