DEBUG_COMPILE = clang -g -O2 -fsanitize=address -fsanitize=undefined
COMPILE = clang -O2

run-all: all
	./example
	./example-debug
	./large-example
	./large-example-debug

all: example example-debug large-example large-example-debug

example:
	${COMPILE} quicksort_example.c -o example

example-debug:
	${DEBUG_COMPILE} quicksort_example.c -o example-debug

large-example:
	${COMPILE} quicksort_large_example.c -o large-example

large-example-debug:
	${DEBUG_COMPILE} quicksort_large_example.c -o large-example-debug
