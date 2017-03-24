#include "DataMemory.h"

DataMemory::DataMemory(uint32_t _size, uint32_t _offset)
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

uint32_t DataMemory::GetSize()
{
    return this->size;
}

uint8_t DataMemory::Get(uint32_t address)
{
    if(address < size)
    {
        return data[address];
    }
    else
        throw std::out_of_range("Argument out of range!");
}

void DataMemory::Set(uint32_t address, uint8_t value)
{
    if(address < size)
    {
        data[address] = value;
    }
    else
        throw std::out_of_range("Argument out of range!");
}

uint8_t *DataMemory::GetDataPtr()
{
    return data;
}


