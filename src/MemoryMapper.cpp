#include "MemoryMapper.h"
#include "DataMemory.h"
MemoryMapper::MemoryMapper(DataMemory* _memory, ProgramMemory *_pgm_mem)
{
    this->data_memory = _memory;
    this->program_memory = _pgm_mem;
}

DataMemory *MemoryMapper::getDataMemory()
{
    return this->data_memory;
}

ProgramMemory *MemoryMapper::getProgramMemory()
{
    return this->program_memory;
}

uint8_t MemoryMapper::getRegister(uint32_t reg)
{
    if(reg>=0x20){
        throw std::out_of_range("Only 32 Processorregisters available");
    }
    return data_memory->Get(reg);
}

uint16_t MemoryMapper::getRegister16(uint32_t reg)
{
    return (uint16_t)getRegister(reg+1)<<8|getRegister(reg);
}

uint8_t MemoryMapper::getIORegister(uint32_t reg)
{
    if(reg>=0x40){
        throw std::out_of_range("Only 64 IO-Registers available");
    }
    return data_memory->Get(reg+0x20);
}

uint16_t MemoryMapper::getIORegister16(uint32_t reg)
{
    return (uint16_t)getIORegister(reg+1)<<8|getIORegister(reg);
}

uint8_t MemoryMapper::getSRAM(uint32_t pos)
{
    return data_memory->Get(pos);
}

uint16_t MemoryMapper::getSRAM16(uint32_t pos)
{
    return (uint16_t)getSRAM(pos+1)<<8|getSRAM(pos);
}

uint8_t MemoryMapper::getSREG(uint8_t mask)
{
    return data_memory->Get(0x5F)&mask;
}

uint8_t MemoryMapper::popStack()
{
    uint16_t SP=getStackPtr();
    SP++;
    setStackPtr(SP);
    return data_memory->Get(SP);
}

void MemoryMapper::setRegister(uint32_t reg, uint8_t val)
{
    if(reg>=0x20){
        throw std::out_of_range("Only 32 Processorregisters available");
    }
    data_memory->Set(reg,val);
}

void MemoryMapper::setRegister16(uint32_t reg, uint16_t val)
{
    setRegister(reg,val);
    setRegister(reg+1,val>>8);
}

void MemoryMapper::setIORegister(uint32_t reg, uint8_t val)
{
    if(reg>=0x40){
        throw std::out_of_range("Only 64 IO-Registers available");
    }
    data_memory->Set(reg+0x20,val);
}

void MemoryMapper::setIORegister16(uint32_t reg, uint16_t val)
{
    setIORegister(reg,val);
    setIORegister(reg+1,val>>8);
}

void MemoryMapper::setSRAM(uint32_t reg, uint8_t val)
{
    data_memory->Set(reg,val);
}

void MemoryMapper::setSRAM16(uint32_t reg, uint16_t val)
{
    setSRAM(reg,val);
    setSRAM(reg+1,val>>8);
}

void MemoryMapper::setSREG(uint8_t sreg, uint8_t mask)
{
    data_memory->Set(0x5F,getSREG(~mask)|(mask&sreg));
}

void MemoryMapper::pushStack(uint8_t data)
{
    uint16_t SP=getStackPtr();
    if(SP<=0x60){
        throw std::overflow_error("Stackoverflow, did you initialize the stackpointer?");
    }
    data_memory->Set(SP,data);
    SP--;
    setStackPtr(SP);
}

uint16_t MemoryMapper::getXReg()
{
    return getRegister16(X_L);
}

uint16_t MemoryMapper::getYReg()
{
    return getRegister16(Y_L);
}

uint16_t MemoryMapper::getZReg()
{
    return getRegister16(Z_L);
}

uint16_t MemoryMapper::getStackPtr()
{
    return getSRAM16(SPL);
}

void MemoryMapper::setXReg(uint16_t data)
{
    setRegister16(X_L,data);
}

void MemoryMapper::setYReg(uint16_t data)
{
    setRegister16(Y_L,data);
}

void MemoryMapper::setZReg(uint16_t data)
{
    setRegister16(Z_L,data);
}

void MemoryMapper::setStackPtr(uint16_t data)
{
    setSRAM16(SPL,data);
}


