#ifndef BITHELPERS_H
#define BITHELPERS_H
#include <cinttypes>

class BitHelpers
{
public:
    BitHelpers();
    static bool bit_set(uint8_t byte, uint8_t pos)
    {
        return byte & pos;
    }
    static bool bit_set(uint16_t word, uint8_t pos)
    {
        return word & pos;
    }
    static void clear_bit(uint8_t &byte, uint8_t pos)
    {
        byte = byte & ~(1<<pos);
    }
    static void set_bit(uint8_t & byte, uint8_t pos)
    {
        byte |= (1<<pos);
    }
    static void set_bit(uint16_t & byte, uint8_t pos)
    {
        byte |= (1<<pos);
    }

};

#endif // BITHELPERS_H
