#include "ConsoleColor.h"


std::string printInColor(const std::string &str, ConsoleColor color,ConsoleColor bgcolor)
{
    std::string col = "\033[" + std::to_string(color) + "m" + "\033[" + std::to_string(bgcolor) + "m";
    return col + str + "\033[" + std::to_string(FG_DEFAULT) + "m" + "\033[" + std::to_string(BG_DEFAULT) + "m";

}
