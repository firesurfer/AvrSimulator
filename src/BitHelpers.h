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

#ifndef BITHELPERS_H
#define BITHELPERS_H
#include <cinttypes>

#define CLR_BIT(x,pos) BitHelpers::clear_bit(x,pos)
#define SET_BIT(x,pos) BitHelpers::set_bit(x,pos)
#define BIT_SET(x,pos) BitHelpers::bit_set(x,pos)

namespace BitHelpers
{
    inline uint8_t bit_set(uint8_t byte, uint8_t pos)
    {

        return (byte>>pos) & 1;
    }
    inline uint8_t bit_set(uint16_t word, uint8_t pos)
    {
        return (word >>pos)& 1;
    }
    inline void clear_bit(uint8_t &byte, uint8_t pos)
    {
        byte = byte & ~(1<<pos);
    }
    inline void clear_bit(uint16_t &word, uint8_t pos)
    {
        word = word & ~(1<<pos);
    }

    inline void set_bit(uint8_t & byte, uint8_t pos)
    {
        byte |= (1<<pos);
    }
    inline void set_bit(uint16_t & byte, uint8_t pos)
    {
        byte |= (1<<pos);
    }
    inline void swap_bytes(uint16_t & integer)
    {
        uint8_t hibyte = (integer & 0xff00) >> 8;
        uint8_t lobyte = (integer & 0xff);
        integer = lobyte << 8 | hibyte;
    }

}

#endif // BITHELPERS_H
