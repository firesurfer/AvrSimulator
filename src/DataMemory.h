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
    uint32_t GetSize();

    uint8_t Get(uint32_t address);
    void Set(uint32_t address, uint8_t value, bool watch = true);
    uint8_t *GetDataPtr();

    ///
    /// \brief watch write accesses to a specific address and print a message or call a function
    /// \param address to be monitored
    /// \param callback to be registered (optional), if empty, write a log message on change
    ///                 callback gets the address, the old and the new value as parameters
    ///
    void watch(uint32_t address, std::function<void(uint32_t, uint8_t, uint8_t, uint8_t &)> callback=nullptr);

    void registerFlag(uint32_t address, uint8_t bit);
private:
    uint32_t size;
    uint32_t offset;
    uint8_t* data;
    std::unordered_multimap<uint32_t, std::function<void(uint32_t, uint8_t, uint8_t, uint8_t &)> > watchlist;
};

