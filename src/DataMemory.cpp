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

void DataMemory::Set(uint32_t address, uint8_t value, bool watch)
{
    if(address < size)
    {
        bool watched = false;
        uint8_t ref = value;
        if(watch)
        {
            auto range = watchlist.equal_range(address);
            for(auto it = range.first; it != range.second; ++it){
                if(it->second)
                    it->second(address, data[address], value, ref);
                else
                    watched=true;
            }
            if(watched)
                LOG(Important)<<"watched change of addr 0x"<<hex<<address<< " from 0x"<<(int)data[address]<< " to 0x" <<(int)value << endl;
            else
                LOG(Debug2)<<"Change of addr 0x"<<hex<<address<< " from 0x"<<(int)data[address]<< " to 0x" <<(int)value << endl;
        }else
            LOG(Debug3)<<"Direct access of addr 0x"<<hex<<address<< " from 0x"<<(int)data[address]<< " to 0x" <<(int)value << endl;

        data[address] = ref;
    }
    else
        throw out_of_range("SRAM Set: Argument out of range!");
}

uint8_t *DataMemory::GetDataPtr()
{
    return data;
}

void DataMemory::watch(uint32_t address, std::function<void(uint32_t, uint8_t, uint8_t, uint8_t&)> callback)
{
    watchlist.emplace(address, callback);
}

void DataMemory::registerFlag(uint32_t address, uint8_t bit)
{
    auto func = [bit](uint32_t addr, uint8_t oldval, uint8_t newval, uint8_t &ref){
        if(newval & (1<<bit)){
            ref &= ~(1<<bit);
            LOG(Info)<<"Flag: "<<(int)bit<<" in 0x"<<hex<<addr<<" cleared"<<endl;
        }else{
            //keep old flagstate if 0 is written
            if(oldval & (1<<bit))
                ref |= (1<<bit);
            else
                ref &= ~(1<<bit);
        }
    };
    watchlist.emplace(address,func);
}


