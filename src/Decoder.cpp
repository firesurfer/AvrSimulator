#include "Decoder.h"

Decoder::Decoder(std::vector<CommandBase *> &_commands):commands(_commands)
{

}

CommandBase *Decoder::decode(uint16_t instruction)
{
    for(auto & it: commands)
    {
        if((instruction & it->CommandMask()) == (it->GetCommand() & it->CommandMask()))
        {
            return it;
        }
    }
    return NULL;
}

bool Decoder::available(uint16_t instruction)
{
    return decode(instruction) != NULL;
}
