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
