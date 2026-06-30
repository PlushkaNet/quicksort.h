//bin/gcc $0 -O2 -o /tmp/quicksort_example.c.compiled.temp && /tmp/quicksort_example.c.compiled.temp && rm -rf /tmp/quicksort_example.c.compiled.temp && exit 0;
#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

/// all functions declaration:
// bquicksort  - for array of chars
// wquicksort  - for array of integers
// dwquicksort - for array of longs
// qwquicksort - for array of <long long>s

// quicksort_c  - alias for bquicksort
// quicksort_i  - alias for wquicksort
// quicksort_l  - alias for dwquicksort
// quicksort_ll - alias for qwquicksort

void print_bytearray(char *arr, int size) {
    int last_index = size-1;
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if(i != last_index) {
            putchar(44); // ',' (comma)
            putchar(32); // ' ' (space)
        }
    } putchar(10); // '\n' (newline)
}

// example of quicksort usage
// for bytearray (array of chars)
int main() {
    const int ARR_SIZE = 4;

    // allocate memory
    char *arr = malloc(ARR_SIZE*sizeof(char));
    if(arr == NULL) {
        puts("Insufficent memory!");
        return 1;
    }

    // fill array with numbers
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 1;
    arr[3] = 2;

    // print unsorted array in the terminal
    printf("Unsorted array: ");
    print_bytearray(arr, ARR_SIZE);

    // call sorting method (quicksort)
    bquicksort(arr, ARR_SIZE);

    // print sorted array in the terminal
    printf("Sorted array: ");
    print_bytearray(arr, ARR_SIZE);

    _qs_type_BOOL is_sorted = is_bsorted(arr, ARR_SIZE);
    if(is_sorted == _QS_TRUE) {
        puts("Array sorted succesfully");
    } else {
        puts("Array was not sorted");
    }

    // return memory to the system
    free(arr);

    return 0;
}
