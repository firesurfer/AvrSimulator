#include "DataMemory.h"

DataMemory::DataMemory(uint64_t _size, uint64_t _offset)
{
    this->size = _size;
    this->offset = _offset;
    this->data = new uint8_t[_size];
}

DataMemory::~DataMemory()
{
    delete data;
    data = NULL;
}

uint64_t DataMemory::GetSize()
{
    return this->size;
}

uint8_t DataMemory::Get(uint16_t address)
{
    if(address < size)
    {
        return data[address];
    }
    else
        throw std::runtime_error("Argument out of range!");
}

void DataMemory::Set(uint16_t address, uint8_t value)
{
    if(address < size)
    {
        data[address] = value;
    }
    else
        throw std::runtime_error("Argument out of range!");
}

uint8_t *DataMemory::GetDataPtr()
{
    return data;
}


