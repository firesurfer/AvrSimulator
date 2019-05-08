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

#ifndef CONSOLE_COLOR_H
#define CONSOLE_COLOR_H
#include <string>

typedef enum ConsoleColor {
    FG_RED      = 31,
    FG_GREEN    = 32,
    FG_BLUE     = 34,
    FG_WHITE = 37,
    FG_YELLOW = 33,
    FG_DEFAULT  = 39,
    BG_RED      = 41,
    BG_GREEN    = 42,
    BG_BLUE     = 44,
    BG_DEFAULT  = 49,
    BG_WHITE = 47,
    BG_YELLOW = 43
}ConsoleColor;

std::string printInColor(const std::string& str, ConsoleColor color, ConsoleColor bgcolor = BG_DEFAULT);

#endif
