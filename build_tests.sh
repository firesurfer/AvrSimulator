mkdir -p test_build
cd test_build
cmake -DCMAKE_TOOLCHAIN_FILE=../test/c/Toolchain-avr-gcc.cmake -DBUILD_TESTS=ON ../test/c
make -j2

cp *.hex ../bin
