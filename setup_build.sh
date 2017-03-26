#!/bin/bash
export "CC=ccache gcc"
export "CXX=ccache g++"
mkdir -p build
cd build
cmake -DCMAKE_CXX_FLAGS=-fuse-ld=gold  -DBUILD_TESTS=ON ..
make -j8
