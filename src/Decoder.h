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

#ifndef DECODER_H
#define DECODER_H

#include "CommandBase.h"
#include <vector>

class Decoder
{
public:
    Decoder(std::vector<CommandBase*> & _commands);
    CommandBase* decode(uint16_t instruction);
    bool available(uint16_t instruction);
private:
    std::vector<CommandBase*> & commands;
};

#endif // DECODER_H
