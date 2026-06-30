#include <stdio.h>

#include "quicksort.h"

void print_intarray(int *arr, int size) {
    int last_index = size-1;
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if(i != last_index) {
            putchar(44); // ',' (comma)
            putchar(32); // ' ' (space)
        }
    } putchar(10); // '\n' (newline)
}

int main() {
    enum {ARR_SIZE = 56};
    int arr[ARR_SIZE] = {
        8, 1, 3, 2, 8, 9, 41, 85, 24, 98, 23, 56, 90, 43, 691, 913, 54, 556, 891, 63, 29, 299, 907, 831, 374,
        3791, 6419, 9481, 732, 913, 7461, 43128, 2819, 7129, 74651, 8138, 817, 62, 1, 8, 0, -91, -912, 871, 9231, 361, 99, 81, 271, 8490, 9135, 1832,
        7139, 912, 8319, 9120
    };

    quicksort_i(arr, ARR_SIZE);
    printf("Sorted: ");
    print_intarray(arr, ARR_SIZE);

    _qs_type_BOOL is_sorted = is_sorted_i(arr, ARR_SIZE);
    if(is_sorted == _QS_TRUE) {
        puts("Array sorted succesfully");
    } else {
        puts("Array was not sorted");
    }
}
