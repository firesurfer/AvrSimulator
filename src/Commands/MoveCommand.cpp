#include "MoveCommand.h"

MoveCommand::MoveCommand(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t MoveCommand::GetCommand()
{
    return 0x0001;
}

uint16_t MoveCommand::NumberOfArguments()
{
    return 2;
}

uint64_t MoveCommand::Execute(uint16_t instruction, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t& StackPointer)
{

    return ProgramCounter +1;
}
