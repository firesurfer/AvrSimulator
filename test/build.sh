#!/bin/bash
avr-as -a --mmcu=atmega32 test.asm 
 avr-objcopy   -j .text -j .data -O ihex a.out test.hex

