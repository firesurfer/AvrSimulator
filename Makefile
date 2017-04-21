machine:
	mkdir -p build/machine
	cd build/machine && CXX="ccache g++" CC="ccache gcc" cmake -DCMAKE_CXX_FLAGS=-fuse-ld=gold  -DBUILD_TESTS=ON ../.. && make -j4
	cd ..

tests:
	mkdir -p build/tests
	cd build/tests && cmake -DCMAKE_TOOLCHAIN_FILE=../../test/c/Toolchain-avr-gcc.cmake -DBUILD_TESTS=ON ../../test/c && make -j4
	cp build/tests/*.hex bin/
	cp build/tests/*.txt bin/

all: machine tests
