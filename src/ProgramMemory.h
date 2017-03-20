#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
class ProgramMemory
{
public:
    ProgramMemory(uint64_t _size, uint64_t _offset);
    virtual ~ProgramMemory();
    uint64_t GetSize();

    uint16_t Get(uint16_t address);
    void Set(uint16_t address, uint16_t value);
    uint16_t *GetDataPtr();
    static ProgramMemory* FromFile(std::string path);
private:
    uint64_t size;
    uint64_t offset;
    uint16_t* data;
};


