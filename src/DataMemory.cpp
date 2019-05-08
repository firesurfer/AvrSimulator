/*
   Copyright 2019 Friedolin Groeger, Lennart Nachtigall

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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

uint32_t DataMemory::getSize()
{
    return this->size;
}

uint8_t DataMemory::get(uint32_t address)
{
    if(address < size)
    {
        //LOG(Debug3)<<"Get addr 0x"<<hex<<address<< ": 0x"<<(int)data[address] << endl;
        auto range = watchlistRead.equal_range(address);
        for(auto it = range.first; it != range.second; ++it){
            if(it->second)
                it->second(address, data[address]);
        }
        return data[address];
    }
    else
        throw out_of_range("SRAM Get: Argument out of range!");
}

uint8_t DataMemory::getDirect(uint32_t address)
{
    if(address < size)
    {
        return data[address];
    }
    else
        LOG(Fatal)<<"Data GetDirect get out of range"<<endl;

}

void DataMemory::set(uint32_t address, uint8_t value, bool watch)
{
    if(address < size)
    {
        bool watched = false;
        uint8_t ref = value;
        if(watch)
        {
            auto range = watchlistWrite.equal_range(address);
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

uint8_t *DataMemory::getDataPtr()
{
    return data;
}

void DataMemory::watchWrite(uint32_t address, std::function<void(uint32_t, uint8_t, uint8_t, uint8_t&)> callback)
{
    watchlistWrite.emplace(address, callback);
}

void DataMemory::watchRead(uint32_t address, std::function<void (uint32_t, uint8_t)> callback)
{
    watchlistRead.emplace(address, callback);
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
    watchlistWrite.emplace(address,func);
}


