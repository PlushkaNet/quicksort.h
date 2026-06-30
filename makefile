DEBUG_COMPILE = gcc -g -O2 -fsanitize=address -fsanitize=undefined
COMPILE = gcc -O2

run-all: all
	./example
	./example-debug
	./large-example
	./large-example-debug
	./tests
	./tests-debug

all: example example-debug large-example large-example-debug tests tests-debug

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
