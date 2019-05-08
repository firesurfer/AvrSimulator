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

#include "ConsoleColor.h"


std::string printInColor(const std::string &str, ConsoleColor color,ConsoleColor bgcolor)
{
    std::string col = "\033[" + std::to_string(color) + "m" + "\033[" + std::to_string(bgcolor) + "m";
    return col + str + "\033[" + std::to_string(FG_DEFAULT) + "m" + "\033[" + std::to_string(BG_DEFAULT) + "m";

}
