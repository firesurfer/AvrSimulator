#include "DataMemory.h"

using namespace std;

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
        //LOG(Debug3)<<"Get addr 0x"<<hex<<address<< ": 0x"<<(int)data[address] << endl;
        return data[address];
    }
    else
        throw out_of_range("SRAM Get: Argument out of range!");
}

void DataMemory::Set(uint32_t address, uint8_t value)
{
    if(address < size)
    {
        bool watched = false;
        auto range = watchlist.equal_range(address);
        for(auto it = range.first; it != range.second; ++it){
            if(it->second)
                it->second(address, data[address], value);
            else
                watched=true;
        }
        if(watched)
            LOG(Important)<<"Change of addr 0x"<<hex<<address<< " from 0x"<<(int)data[address]<< " to 0x" <<(int)value << endl;
        else
            LOG(Debug2)<<"Change of addr 0x"<<hex<<address<< " from 0x"<<(int)data[address]<< " to 0x" <<(int)value << endl;
        data[address] = value;
    }
    else
        throw out_of_range("SRAM Set: Argument out of range!");
}

uint8_t *DataMemory::GetDataPtr()
{
    return data;
}

void DataMemory::watch(uint32_t address, std::function<void(uint32_t, uint8_t, uint8_t)> callback)
{
    watchlist.emplace(address, callback);
}


