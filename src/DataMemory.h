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

#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <functional>
#include "Logger/Logger.h"
class DataMemory
{
public:
    DataMemory(uint32_t _size, uint32_t _offset);
    virtual ~DataMemory();
    uint32_t getSize();

    uint8_t get(uint32_t address);
    uint8_t getDirect(uint32_t address);
    uint16_t getDirect16(uint32_t address);
    void set(uint32_t address, uint8_t value, bool watchWrite = true);
    void setDirect16(uint32_t address, uint16_t value);
    void setDirect(uint32_t address, uint8_t value){set(address,value,false);}
    uint8_t *getDataPtr();

    ///
    /// \brief watch write accesses to a specific address and print a message or call a function
    /// \param address to be monitored
    /// \param callback to be registered (optional), if empty, write a log message on change
    ///                 callback gets the address, the old and the new value as parameters
    ///
    void watchWrite(uint32_t address, std::function<void(uint32_t, uint8_t, uint8_t, uint8_t &)> callback=nullptr);

    void watchRead(uint32_t address, std::function<void(uint32_t, uint8_t)> callback);

    void registerFlag(uint32_t address, uint8_t bit);
private:
    uint32_t size;
    uint32_t offset;
    uint8_t* data;
    std::unordered_multimap<uint32_t, std::function<void(uint32_t, uint8_t, uint8_t, uint8_t &)> > watchlistWrite;
    std::unordered_multimap<uint32_t, std::function<void(uint32_t, uint8_t)> > watchlistRead;
};

