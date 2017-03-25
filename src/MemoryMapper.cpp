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

uint8_t MemoryMapper::getIORegister(uint32_t reg)
{
    if(reg>=0x40){
        throw std::out_of_range("Only 64 IO-Registers available");
    }
    return data_memory->Get(reg+0x20);
}

uint8_t MemoryMapper::getSRAM(uint32_t pos)
{
    return data_memory->Get(pos);
}

uint8_t MemoryMapper::getSREG(uint8_t mask)
{
    return data_memory->Get(0x5F)&mask;
}

uint8_t MemoryMapper::popStack()
{
    uint16_t SP=(uint16_t)data_memory->Get(0x5E)<<8;
    SP|=data_memory->Get(0x5D);
    SP++;
    data_memory->Set(0x5E,SP>>8);
    data_memory->Set(0x5D,SP);
    return data_memory->Get(SP);
}

void MemoryMapper::setRegister(uint32_t reg, uint8_t val)
{
    if(reg>=0x20){
        throw std::out_of_range("Only 32 Processorregisters available");
    }
    data_memory->Set(reg,val);
}

void MemoryMapper::setIORegister(uint32_t reg, uint8_t val)
{
    if(reg>=0x40){
        throw std::out_of_range("Only 64 IO-Registers available");
    }
    data_memory->Set(reg+0x20,val);
}

void MemoryMapper::setSRAM(uint32_t reg, uint8_t val)
{
    data_memory->Set(reg,val);
}

void MemoryMapper::setSREG(uint8_t sreg, uint8_t mask)
{
    data_memory->Set(getSREG(~mask)|(mask&sreg),0x5F);
}

void MemoryMapper::pushStack(uint8_t data)
{
    uint16_t SP=(uint16_t)data_memory->Get(0x5E)<<8;
    SP|=data_memory->Get(0x5D);
    if(SP<=0x60){
        throw std::overflow_error("Stackoverflow, did you initialize the stackpointer?");
    }
    data_memory->Set(SP,data);
    SP--;
    data_memory->Set(0x5E,SP>>8);
    data_memory->Set(0x5D,SP);
}

uint16_t MemoryMapper::getZReg()
{
    return get16bitRegister(Z_L);
}

uint16_t MemoryMapper::getStackPtr()
{
    return get16bitRegister(SPL);
}

void MemoryMapper::setXReg(uint16_t data)
{
    set16bitRegister(X_L,data);
}

void MemoryMapper::setYReg(uint16_t data)
{
    set16bitRegister(Y_L,data);
}

void MemoryMapper::setZReg(uint16_t data)
{
    set16bitRegister(Z_L,data);
}

void MemoryMapper::setStackPtr(uint16_t data)
{
    set16bitRegister(SPL,data);
}

uint16_t MemoryMapper::get16bitRegister(uint8_t l_reg)
{
     uint16_t* reg_ptr = (uint16_t*)&data_memory->GetDataPtr()[l_reg];
     uint16_t reg = *reg_ptr;
     BitHelpers::swap_bytes(reg);
     return reg;
}

void MemoryMapper::set16bitRegister(uint8_t l_reg,uint16_t val)
{
     uint16_t* reg_ptr = (uint16_t*)&data_memory->GetDataPtr()[l_reg];
     BitHelpers::swap_bytes(val);
     *reg_ptr = val;
}
