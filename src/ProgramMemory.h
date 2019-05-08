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
#include <vector>
#include <cstring>
#include <sstream>
#include "Logger/Logger.h"
class ProgramMemory
{
public:
    ProgramMemory(uint64_t _size, uint64_t _offset);
    virtual ~ProgramMemory();
    uint64_t getSize();

    uint16_t get(uint16_t address);
    void set(uint16_t address, uint16_t value);
    uint16_t *getDataPtr();
    static ProgramMemory* gromFile(std::string path);
private:
    uint64_t size;
    uint64_t offset;
    uint16_t* data;
};


