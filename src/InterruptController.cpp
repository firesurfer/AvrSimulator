#include "InterruptController.h"

InterruptController::InterruptController(MemoryMapper *_mem_mapper)
{
    this->memory_mapper = _mem_mapper;
}

uint32_t InterruptController::handleInterrupts(uint32_t cycles, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    if(!memory_mapper->getSREG(MASK_I))
        return 0;
    for(intvector_t & element: this->interruptVectors)
    {
        if(memory_mapper->getData(element.maskaddr)&(1<<element.maskbit)){
            if(memory_mapper->getData(element.flagaddr)&(1<<element.flagbit)){
                uint8_t low_byte = (uint8_t)ProgramCounter;
                uint8_t high_byte = (uint8_t)((ProgramCounter) >> 8);
                memory_mapper->pushStack(low_byte);
                memory_mapper->pushStack(high_byte);
                memory_mapper->setSREG(0,MASK_I);
                ProgramCounter = element.vectoraddress;
                if(element.clearflag){
                    uint8_t flags = memory_mapper->getDataMemory()->Get(element.flagaddr);
                    flags &= ~(1<<element.flagbit);
                    memory_mapper->getDataMemory()->Set(element.flagaddr,flags,false);
                }
                return 4;
            }
        }
    }
}

void InterruptController::addInterruptVector(intvector_t element)
{
    this->interruptVectors.push_back(element);
}
