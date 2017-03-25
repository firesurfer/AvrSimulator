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
uint8_t simpleFlags(uint8_t value,uint8_t sreg){
    if(value==0 && bit_set(sreg,SREG_Z))
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
uint8_t additionFlags(uint8_t r1, uint8_t r2, uint8_t sreg){
    if(((r1&0xF)+(r2&0xF)+bit_set(sreg,SREG_C))&0x10)
        set_bit(sreg,SREG_H);
    else
        clear_bit(sreg,SREG_H);

    uint16_t res=(uint16_t)r1+r2+bit_set(sreg,SREG_C);
    if(res&0x100)
        set_bit(sreg,SREG_C);
    else
        clear_bit(sreg,SREG_C);

    if(0x80&((res&~r1&~r2)|(~res&r1&r2)))//alternativ:(0x80&((r1^~r2)&(r1^res)))
        set_bit(sreg,SREG_V);
    else
        clear_bit(sreg,SREG_V);

    return simpleFlags(res, sreg);
}

}//namespace
