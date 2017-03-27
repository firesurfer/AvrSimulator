# AVR simulator / interpreter

This program reads an intel ihex file for ATmega32 microcontrollers. It performs the operations stated in the hexfile.

# How to build

Simply run the `setup_build.sh`.
You will need the following dependencies installed:

* cmake
* gcc/g++
* ccache
* gold
* avr-gcc

Afterwards you can simply step into the `build/machine` or `build/tests` folder and run `make`. 

# How to run a program

Step into the bin directory, run the register_machine with the ihex file as an argument.

```
cd bin
./register_machine <your file>
```
