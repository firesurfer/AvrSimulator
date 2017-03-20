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
    DataMemory(uint64_t _size, uint64_t _offset);
    virtual ~DataMemory();
    uint64_t GetSize();

    uint8_t Get(uint16_t address);
    void Set(uint16_t address, uint8_t value);
    uint8_t *GetDataPtr();

private:
    uint64_t size;
    uint64_t offset;
    uint8_t* data;
};

