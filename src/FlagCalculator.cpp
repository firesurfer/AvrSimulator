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

#include "FlagCalculator.h"
#include "ProcessorDefines.h"
#include "BitHelpers.h"

using namespace BitHelpers;
namespace FlagCalculator
{

///
/// \brief simpleFlags SREG Flag calculation for S,N,Z flags
/// \param value value to be tested
/// \param sreg optional previos sreg state with V Flag for S flag or Z flag for 16bit Zflag
/// \return temporary SREG with Z,N and S flag, other flags are 0
///
uint8_t simpleFlags(uint8_t value, uint8_t sreg, bool wordcheck){
    if(value==0 && (!wordcheck || bit_set(sreg,SREG_Z)))
        set_bit(sreg,SREG_Z);
    else
        clear_bit(sreg,SREG_Z);

    if(value&0x80)
        set_bit(sreg,SREG_N);
    else
        clear_bit(sreg,SREG_N);

    if(bit_set(sreg,SREG_N)^bit_set(sreg,SREG_V))
        set_bit(sreg,SREG_S);
    else
        clear_bit(sreg,SREG_S);

    return sreg;
}

///
/// \brief additionFlags SREG Flag calculation for a typical addition for S,N,V,Z,H,C flags
/// \param r1 first value for summation
/// \param r2 second value
/// \param sreg optional previos SREG value for carryadd/16bit operations
/// \return SREG with calculated flags, other Flags are 0
///
uint8_t additionFlags(uint8_t r1, uint8_t r2, uint8_t &sreg, bool wordcheck){
    if(((r1&0xF)+(r2&0xF)+bit_set(sreg,SREG_C))&0x10)
        set_bit(sreg,SREG_H);
    else
        clear_bit(sreg,SREG_H);

    uint16_t res = (uint16_t)r1+r2+bit_set(sreg,SREG_C);
    if(res&0x100)
        set_bit(sreg,SREG_C);
    else
        clear_bit(sreg,SREG_C);

    if(0x80&((res&~r1&~r2)|(~res&r1&r2)))//alternativ:(0x80&((r1^~r2)&(r1^res)))
        set_bit(sreg,SREG_V);
    else
        clear_bit(sreg,SREG_V);

    sreg = simpleFlags(res, sreg, wordcheck);
    return res;
}

uint8_t subtractionFlags(uint8_t r1, uint8_t r2, uint8_t &sreg, bool wordcheck){
    if((r1&0xF)<((r2&0xF)+bit_set(sreg,SREG_C)))
        set_bit(sreg,SREG_H);
    else
        clear_bit(sreg,SREG_H);

    int16_t res = (uint16_t)r1-r2-bit_set(sreg,SREG_C);
    if(res<0)
        set_bit(sreg,SREG_C);
    else
        clear_bit(sreg,SREG_C);

    if(0x80&((res&~r1&r2)|(~res&r1&~r2)))//alternativ:(0x80&((r1^r2)&(r1^res)))
        set_bit(sreg,SREG_V);
    else
        clear_bit(sreg,SREG_V);

    sreg = simpleFlags(res, sreg, wordcheck);
    return res;
}

uint8_t shiftFlags(uint8_t value, uint8_t sreg)
{
    sreg = simpleFlags(value,sreg);//for Z and N
    if(bit_set(sreg,SREG_N)^bit_set(sreg,SREG_C))
        set_bit(sreg,SREG_V);
    else
        clear_bit(sreg,SREG_V);
    sreg = simpleFlags(value,sreg);//for S
    return sreg;
}

}//namespace
