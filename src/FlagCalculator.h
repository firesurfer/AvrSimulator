#ifndef FLAGCALCULATOR_H
#define FLAGCALCULATOR_H
#include <cinttypes>

namespace FlagCalculator
{

///
/// \brief simpleFlags SREG Flag calculation for S,N,Z flags
/// \param value value to be tested
/// \param sreg optional previos sreg state with V Flag for S flag or Z flag for 16bit Zflag
/// \return temporary SREG with Z,N and S flag, other flags are 0
///
uint8_t simpleFlags(uint8_t value,uint8_t sreg=0);

///
/// \brief additionFlags SREG Flag calculation for a typical addition for S,N,V,Z,H,C flags
/// \param r1 first value for summation
/// \param r2 second value
/// \param sreg optional previos SREG value for carryadd/16bit operations
/// \return SREG with calculated flags, other Flags are 0
///
uint8_t additionFlags(uint8_t &r1, uint8_t r2, uint8_t sreg=0);

}

#endif // FLAGCALCULATOR_H
