machine:
	mkdir -p build/machine
	cd build/machine && CXX="g++" CC="gcc" cmake -DCMAKE_CXX_FLAGS="-fuse-ld=gold -fdiagnostics-color=always" -DBUILD_TESTS=ON ../.. && make -j8
	cd ..
	cp src/avr/iom32.h bin/

tests:
	mkdir -p build/tests
	cd build/tests && cmake -DCMAKE_TOOLCHAIN_FILE=../../test/c/Toolchain-avr-gcc.cmake -DBUILD_TESTS=ON ../../test/c && make -j4
	cp build/tests/*.hex bin/
	cp build/tests/*.lss bin/

all: machine tests
