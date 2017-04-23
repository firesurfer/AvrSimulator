#ifndef INTERRUPTCONTROLLER_H
#define INTERRUPTCONTROLLER_H

#include "MemoryMapper.h"
#include <vector>
#include <processorflags.h>

typedef struct{
    uint32_t vectoraddress;
    uint32_t flagaddr;
    uint32_t flagbit;
    uint32_t maskaddr;
    uint32_t maskbit;
    bool clearflag;
    //priority
} intvector_t;

class InterruptController
{
public:
    InterruptController(MemoryMapper* _mem_mapper);
    uint32_t handleInterrupts(uint32_t cycles, uint16_t &ProgramCounter, ProcessorFlags &flags);
    void addInterruptVector(intvector_t element);
private:
    MemoryMapper* memory_mapper;
    std::vector<intvector_t> interruptVectors;
};

#endif // PERIPHERYHANDLER_H
