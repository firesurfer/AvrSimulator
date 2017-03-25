#include "MemoryMapper.h"

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

uint16_t MemoryMapper::getXReg()
{
    return get16bitRegister(X_L);
}

uint16_t MemoryMapper::getYReg()
{
    return get16bitRegister(Y_L);

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
