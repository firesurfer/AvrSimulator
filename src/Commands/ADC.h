#ifndef ADC_H
#define ADC_H

#include "CommandBase.h"
class ADC:public CommandBase
{
public:
    ADC(DataMemory* _dataMemory);
    virtual uint16_t GetCommand();
    virtual uint16_t NumberOfArguments();
    virtual uint16_t CommandSize();
    virtual uint64_t Execute(uint16_t instruction,std::vector<uint8_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t>& SpecialRegisters,uint16_t ProgramCounter, uint16_t& StackPointer);
};

#endif // ADC_H
