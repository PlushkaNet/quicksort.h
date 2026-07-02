// file with tests for quicksort.h
#include <stdio.h>

#include "quicksort.h"

_qs_type_BOOL is_sorted_test() {
    char sorted_arr[4] = {1, 2, 3, 4};
    return is_sorted_c(sorted_arr, 4);
}

_qs_type_BOOL int_sort_small_test() {
    int arr[8] = {89181, 54192, 19138, 12392, 1248, 0, -99, -142971};
    quicksort_i(arr, 8);
    return is_sorted_i(arr, 8);
}

_qs_type_BOOL char_sort_small_test() {
    char arr[8] = {128, -91, 57, 12, 98, 0, -99, -81};
    quicksort_c(arr, 8);
    return is_sorted_c(arr, 8);
}

_qs_type_BOOL float_sort_small_test() {
    float arr[8] = {127.819, -91.912, 57.128, 57.129, 98.0, 0.1, -99.99, -81.18};
    quicksort_f(arr, 8);
    return is_sorted_f(arr, 8);
}

_qs_type_BOOL double_sort_small_test() {
    float arr[8] = {127.81912731236781, 127.81912731236782, 57.128, 57.129, 98.0, 0.1, -99.99, -81.18};
    quicksort_f(arr, 8);
    return is_sorted_f(arr, 8);
}

_qs_type_BOOL l_sort_small_test() {
    long arr[8] = {
        29749124917924,
        -198724874214,
        1278149152927,
        -1692164971264,
        524729212124,
        0,
        124791274981,
        8372574998
    };
    quicksort_l(arr, 8);
    return is_sorted_l(arr, 8);
}

_qs_type_BOOL ll_sort_small_test() {
    long long arr[8] = {
        2974912491431847924,
        -19872491419874214,
        127814994789152927,
        -1692164921764971264,
        52472921749812124,
        0,
        12471924791274981,
        83725898174998
    };
    quicksort_ll(arr, 8);
    return is_sorted_ll(arr, 8);
}

int main() {
    if(is_sorted_test() == qs_FALSE) return 1;
    puts("is_sorted test passed");
    if(int_sort_small_test() == qs_FALSE) return 1;
    puts("int_sort_small_test test passed");
    if(char_sort_small_test() == qs_FALSE) return 1;
    puts("char_sort_small_test test passed");
    if(l_sort_small_test() == qs_FALSE) return 1;
    puts("l_sort_small_test test passed");
    if(ll_sort_small_test() == qs_FALSE) return 1;
    puts("ll_sort_small_test test passed");
    if(float_sort_small_test() == qs_FALSE) return 1;
    puts("float_sort_small_test test passed");
    if(double_sort_small_test() == qs_FALSE) return 1;
    puts("double_sort_small_test test passed");

    puts("all tests passed");
}
