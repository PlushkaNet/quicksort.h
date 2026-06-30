example:
	clang -O2 quicksort_example.c -o example

example-debug:
	clang -g -O2 -fsanitize=address -fsanitize=undefined quicksort_example.c -o example-debug
