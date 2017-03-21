#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "CommandBase.h"

class MoveCommand : public CommandBase
{
public:
    MoveCommand(DataMemory* _dataMemory);
    uint16_t GetCommand();
    uint16_t NumberOfArguments();
    uint64_t Execute(uint16_t instruction,std::vector<uint16_t> additionalWords, std::vector<uint8_t>& Registers, std::vector<uint8_t>& SpecialRegisters,uint16_t ProgramCounter,  uint16_t &StackPointer);
};

#endif // MOVECOMMAND_H
