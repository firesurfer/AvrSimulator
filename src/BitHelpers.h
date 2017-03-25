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
    static void swap_bytes(uint16_t & integer)
    {
        uint8_t hibyte = (integer & 0xff00) >> 8;
        uint8_t lobyte = (integer & 0xff);
        integer = lobyte << 8 | hibyte;
    }

};

#endif // BITHELPERS_H
