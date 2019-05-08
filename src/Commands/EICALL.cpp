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

#include "EICALL.h"

EICALL::EICALL(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0001110000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
    name = "EICALL";
}

uint32_t EICALL::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
  /*  uint8_t & sreg = SpecialRegisters[SREG];
    uint8_t registers = (uint8_t)(instruction >> 8);
    uint8_t regd = registers & 0xF0;
    uint8_t regr = registers >> 4;
    if(BitHelpers::bit_set(registers, 7))
    {
        regd+=16;
    }
    if(BitHelpers::bit_set(registers,8))
    {
        regr+=16;
    }
    uint8_t temp = Registers[regd] + Registers[regr];
    if(BitHelpers::bit_set(Registers[regd],3)&& BitHelpers::bit_set(Registers[regr],3)|| BitHelpers::bit_set(Registers[regr],3) && !BitHelpers::bit_set(temp,3) || !BitHelpers::bit_set(temp,3) && BitHelpers::bit_set(Registers[regd],3))
        BitHelpers::set_bit(sreg,SREG_H);
    if(BitHelpers::bit_set(temp,7))
        BitHelpers::set_bit(sreg,SREG_N);
    if(BitHelpers::bit_set(sreg, SREG_N) != BitHelpers::bit_set(sreg,SREG_V))
        BitHelpers::set_bit(sreg,SREG_S);
    if(temp = 0)
        BitHelpers::set_bit(sreg,SREG_Z);
    else
        BitHelpers::clear_bit(sreg,SREG_Z);
    if(BitHelpers::bit_set(Registers[regd],7) && BitHelpers::bit_set(Registers[regr],7) || BitHelpers::bit_set(Registers[regr],7)  && !BitHelpers::bit_set(temp,7) || !BitHelpers::bit_set(temp,7), BitHelpers::bit_set(Registers[regd],7))
        BitHelpers::set_bit(sreg,SREG_C);
    if(BitHelpers::bit_set(Registers[regd],7)&& BitHelpers::bit_set(Registers[regr],7) && !BitHelpers::bit_set(temp,7) || !BitHelpers::bit_set(Registers[regd],7) || !BitHelpers::bit_set(Registers[regr],7) || BitHelpers::bit_set(temp,7))
        BitHelpers::set_bit(sreg,SREG_V);


    Registers[regd] = temp;*/
    return ProgramCounter+1;
}
