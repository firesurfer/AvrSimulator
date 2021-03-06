#!/bin/bash

mkdir -p build/machine
cd build/machine
CXX="g++" CC="gcc" cmake -DCMAKE_CXX_FLAGS="-fuse-ld=gold -fdiagnostics-color=always" -DBUILD_TESTS=ON ../..
make -j8

cd ..
mkdir -p tests
cd tests
cmake -DCMAKE_TOOLCHAIN_FILE=../../test/c/Toolchain-avr-gcc.cmake -DBUILD_TESTS=ON ../../test/c
make -j2

cp *.hex ../../bin
cp *.lss ../../bin
