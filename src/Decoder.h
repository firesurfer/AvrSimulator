#ifndef DECODER_H
#define DECODER_H

#include "CommandBase.h"
#include <vector>

class Decoder
{
public:
    Decoder(std::vector<CommandBase*> & _commands);
    CommandBase* decode(uint16_t instruction);
private:
    std::vector<CommandBase*> & commands;
};

#endif // DECODER_H
