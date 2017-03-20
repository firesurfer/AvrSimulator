#include "ProgramMemory.h"

ProgramMemory::ProgramMemory(uint64_t _size, uint64_t _offset)
{
    this->size = _size;
    this->offset = _offset;
    this->data = new uint16_t[_size];
}

ProgramMemory::~ProgramMemory()
{
    delete data;
    data = NULL;
}

uint64_t ProgramMemory::GetSize()
{
    return this->size;
}

uint16_t ProgramMemory::Get(uint16_t address)
{
    if(address < size)
    {
        return data[address];
    }
    else
        throw std::runtime_error("Argument out of range!");
}

void ProgramMemory::Set(uint16_t address, uint16_t value)
{
    if(address < size)
    {
        data[address] = value;
    }
    else
        throw std::runtime_error("Argument out of range!");
}

uint16_t *ProgramMemory::GetDataPtr()
{
    return data;
}

ProgramMemory *ProgramMemory::FromFile(std::string path)
{
    std::ifstream file (path,std::ios::binary );
    if(file.is_open())
    {
        file.seekg (0, std::ios::end);
        std::streampos size = file.tellg();

        ProgramMemory * mem = new ProgramMemory(size,0);
        file.seekg (0, std::ios::beg);

        char * memblock = new char[size];

        file.read(memblock,size);
        file.close();
        std::memcpy(mem->GetDataPtr(), memblock, size);

        delete memblock;
        return mem;
    }
    else
    {
        throw std::runtime_error("Invalid path!");
    }
}

