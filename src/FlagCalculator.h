#ifndef FLAGCALCULATOR_H
#define FLAGCALCULATOR_H
#include <cinttypes>
#include "ProcessorDefines.h"

namespace FlagCalculator
{

///
/// \brief simpleFlags SREG Flag calculation for S,N,Z flags
/// \param value value to be tested
/// \param sreg optional previos sreg state with V Flag for S flag or Z flag for 16bit Zflag
/// \return temporary SREG with Z,N and S flag, other flags are 0/unchanged
///
uint8_t simpleFlags(uint8_t value,uint8_t sreg=0);

///
/// \brief additionFlags SREG Flag calculation for a typical addition for S,N,V,Z,H,C flags
/// \param r1 first value for summation
/// \param r2 second value
/// \param sreg optional previos SREG value for carryadd/16bit operations
/// \return SREG with calculated flags, other Flags are 0/unchanged
///
uint8_t additionFlags(uint8_t &r1, uint8_t r2, uint8_t sreg=0);

///
/// \brief shiftFlags calculates Flags after shift/rol
/// \param value after shift
/// \param sreg with Carry set manually
/// \return sreg S,V,N,Z Flags set, others unchanges
///
uint8_t shiftFlags(uint8_t value, uint8_t sreg);
}

#endif // FLAGCALCULATOR_H
