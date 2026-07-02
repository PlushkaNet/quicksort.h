DEBUG_COMPILE = gcc -g -O0 -Wpedantic -fsanitize=address -fsanitize=undefined
COMPILE = gcc -O2
DEBUG_COMPILE_CPP = g++ -g -O0 -Wpedantic -fsanitize=address -fsanitize=undefined
COMPILE_CPP = g++ -O2

run-all: all
	./example-debug
	./example
	./large-example-debug
	./large-example
	./tests-debug
	./tests
	./test-cpp-debug
	./test-cpp

.PHONY clean:
	rm -rf example example-debug large-example large-example-debug tests tests-debug test-cpp test-cpp-debug

all: example example-debug large-example large-example-debug tests tests-debug test-cpp test-cpp-debug

example:
	${COMPILE} quicksort_example.c -o example

example-debug:
	${DEBUG_COMPILE} quicksort_example.c -o example-debug

large-example:
	${COMPILE} quicksort_large_example.c -o large-example

large-example-debug:
	${DEBUG_COMPILE} quicksort_large_example.c -o large-example-debug

tests:
	${COMPILE} tests.c -o tests

tests-debug:
	${DEBUG_COMPILE} tests.c -o tests-debug

test-cpp:
	${COMPILE_CPP} test_int.cpp -o test-cpp

test-cpp-debug:
	${DEBUG_COMPILE_CPP} test_int.cpp -o test-cpp-debug
