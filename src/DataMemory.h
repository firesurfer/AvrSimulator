#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
class DataMemory
{
public:
    DataMemory(uint32_t _size, uint32_t _offset);
    virtual ~DataMemory();
    uint32_t GetSize();

    uint8_t Get(uint32_t address);
    void Set(uint32_t address, uint8_t value);
    uint8_t *GetDataPtr();

private:
    uint32_t size;
    uint32_t offset;
    uint8_t* data;
};

