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
