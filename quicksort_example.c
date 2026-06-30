#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

// example of quicksort usage
// for bytearray (array of chars)
int main() {
    const int ARR_SIZE = 4;
    char *arr = malloc(ARR_SIZE*sizeof(char));
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 1;
    arr[3] = 2;
    bquicksort(arr, ARR_SIZE);
    for(int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", arr[i]);
    } putchar(10);
    free(arr);
}

/// all functions declaration:
// bquicksort  - for array of chars
// wquicksort  - for array of integers
// dwquicksort - for array of longs
// qwquicksort - for array of <long long>s

// quicksort_c  - alias for bquicksort
// quicksort_i  - alias for wquicksort
// quicksort_l  - alias for dwquicksort
// quicksort_ll - alias for qwquicksort
