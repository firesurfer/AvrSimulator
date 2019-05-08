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

#include "ProgramMemory.h"

ProgramMemory::ProgramMemory(uint64_t _size, uint64_t _offset)
{
    this->size = _size;
    this->offset = _offset;
    this->data = new uint16_t[_size];
    for(uint64_t i=0; i < size;i++ )
    {
        set(i,0xFFFF);
    }
}

ProgramMemory::~ProgramMemory()
{
    delete data;
    data = NULL;
}

uint64_t ProgramMemory::getSize()
{
    return this->size;
}

uint16_t ProgramMemory::get(uint16_t address)
{
    if(address < size)
    {
        return data[address];
    }
    else
        throw std::runtime_error("Argument out of range!");
}

void ProgramMemory::set(uint16_t address, uint16_t value)
{
    if(address < size)
    {
        data[address] = value;
    }
    else
        throw std::runtime_error("Argument out of range!");
}

uint16_t *ProgramMemory::getDataPtr()
{
    return data;
}

ProgramMemory *ProgramMemory::gromFile(std::string path)
{
    std::ifstream file (path,std::ios::binary );
    if(file.is_open())
    {
        std::vector<std::string> hex_file;
        std::string line;
        while ( getline (file,line) )
        {
            if(line.at(0) != ':')
                throw std::runtime_error("This might not be an intel hexfile!");
            hex_file.push_back(line);
        }
        file.close();
        LOG(Info)<< "Program memory file: " << std::endl;
        int line_count = 0;
        ProgramMemory * mem = new ProgramMemory(32*1024,0);
        int size_total = 0;
        for(std::string & hex_line: hex_file)
        {
            if(hex_line.find(":00000001FF") == std::string::npos )
            {

                std::string str_size = hex_line.substr(1,2);

                uint16_t size= std::stoul("0x"+str_size, nullptr, 0);

                std::string str_address = hex_line.substr(3,4);

                uint16_t address =  std::stoul("0x"+str_address, nullptr, 16);
                for(int i = 0; i < size/2;i++)
                {
                    uint16_t data  = std::stoul(hex_line.substr(9+i*4,4), nullptr, 16);
                    //Swap high and lowbyte - Endianess
                    uint8_t hibyte = (data & 0xff00) >> 8;
                    uint8_t lobyte = (data & 0xff);
                    data = lobyte << 8 | hibyte;
                    mem->set(address/2+i,data);
                }
                LOG(Debug) << "  Line:         " << line_count << std::endl;
                LOG(Debug) << "  Bytes:         " << size <<std::endl;
                LOG(Debug) << "  Startaddress: " << address << std::endl;
                line_count ++;
                size_total += size;
            }
            else
                break;
        }
        LOG(Info)<< "Lines read:   " << line_count << std::endl;
        LOG(Info) << "Total Bytes:   " << size_total << std::endl;

        return mem;
    }
    else
    {
        throw std::runtime_error("Invalid path!");
    }
}

