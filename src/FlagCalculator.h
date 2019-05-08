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
uint8_t simpleFlags(uint8_t value,uint8_t sreg=0, bool wordcheck=false);

///
/// \brief additionFlags SREG Flag calculation for a typical addition for S,N,V,Z,H,C flags
/// \param r1 first value for addition
/// \param r2 second value
/// \param sreg previous SREG value for carryadd/16bit operations,
///     will be overwritten with new flags, I and T flags are unchanged
/// \return result of addition
///
uint8_t additionFlags(uint8_t r1, uint8_t r2, uint8_t &sreg, bool wordcheck=false);

///
/// \brief subtractionFlags SREG Flag calculation for a typical subtraction for S,N,V,Z,H,C flags
/// \param r1 first value for addition
/// \param r2 second value
/// \param sreg previous SREG value for carryadd/16bit operations,
///     will be overwritten with new flags, I and T flags are unchanged
/// \return result of subtraction
///
uint8_t subtractionFlags(uint8_t r1, uint8_t r2, uint8_t &sreg, bool wordcheck=false);

///
/// \brief shiftFlags calculates Flags after shift/rol
/// \param value after shift
/// \param sreg with Carry set manually
/// \return sreg S,V,N,Z Flags set, others unchanges
///
uint8_t shiftFlags(uint8_t value, uint8_t sreg);
}

#endif // FLAGCALCULATOR_H
