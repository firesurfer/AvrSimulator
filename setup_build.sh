#!/bin/bash
export "CC=ccache gcc"
export "CXX=ccache g++"
mkdir -p build
cd build
cmake ..
make -j8
