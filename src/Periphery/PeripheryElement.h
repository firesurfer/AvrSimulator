#ifndef PERIPHERYELEMENT_H
#define PERIPHERYELEMENT_H


#include "MemoryMapper.h"
class PeripheryElement
{
public:
    PeripheryElement(MemoryMapper* mapper);
    virtual void handle(uint32_t cycles);
protected:
    MemoryMapper* mem_mapper;
};

#endif // PERIPHERYELEMENT_H
