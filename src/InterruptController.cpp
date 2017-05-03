#include "InterruptController.h"

InterruptController::InterruptController(MemoryMapper *_mem_mapper)
{
    this->memoryMapper = _mem_mapper;
    this->dataMem = _mem_mapper->getDataMemory();
}

uint32_t InterruptController::handleInterrupts(uint32_t cycles, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    if(!memoryMapper->getSREG(MASK_I))
        return 0;
    if(flags.skipNextInstruction)
        return 0;
    for(auto & it: this->interruptVectors)
    {
        auto element = it.second;
        if(memoryMapper->getData(element.maskaddr)&(1<<element.maskbit)){
            if(memoryMapper->getData(element.flagaddr)&(1<<element.flagbit)){
                LOG(Info)<<"UDRE interrupt started:\n";
                uint8_t low_byte = (uint8_t)ProgramCounter;
                uint8_t high_byte = (uint8_t)((ProgramCounter) >> 8);
                memoryMapper->pushStack(low_byte);
                memoryMapper->pushStack(high_byte);
                memoryMapper->setSREG(0,MASK_I);
                ProgramCounter = element.vectoraddress;
                if(element.clearflag){
                    uint8_t flags = dataMem->GetDirect(element.flagaddr);
                    flags &= ~(1<<element.flagbit);
                    dataMem->SetDirect(element.flagaddr,flags);
                }
                return 4;
            }
        }
    }
}

void InterruptController::addInterruptVector(intvector_t element)
{
    this->interruptVectors.emplace(element.vectoraddress,element);
}
