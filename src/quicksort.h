#pragma once
#define BYTE  char
#define WORD  int
#define DWORD long
#define QWORD long long

#define __swap_t(type, a, b) type c = a; a = b; b = c;
#define __quicksort_t(type, name) void name(type *arr, WORD start, WORD len) { \
    if(start >= len) return; type pivot = arr[start]; WORD i = start-1; \
    for(WORD j = ++start; j < len; j++) { \
        if(arr[j] < pivot) { \
            WORD it = ++i; __swap_t(type, arr[it], arr[j]) }} \
    name(arr, start, ++i); \
    for(WORD j = i; j < len; j++) { \
        if(arr[j] == pivot) { \
            WORD it = i++; __swap_t(type, arr[it], arr[j]) }} \
    name(arr, i, len);}

__quicksort_t(BYTE,  bquicksort_s  )
__quicksort_t(WORD,  wquicksort_s  )
__quicksort_t(DWORD, dwquicksort_s )
__quicksort_t(QWORD, qwquicksort_s )

__quicksort_t(float, quicksort_f_s )
__quicksort_t(double, quicksort_d_s)

#define quicksort_c_s  bquicksort_s
#define quicksort_i_s  wquicksort_s
#define quicksort_l_s  dwquicksort_s
#define quicksort_ll_s qwquicksort_s

#define bquicksort(arr, len) bquicksort_s(arr, 0, len)
#define wquicksort(arr, len) wquicksort_s(arr, 0, len)
#define dwquicksort(arr, len) dwquicksort_s(arr, 0, len)
#define qwquicksort(arr, len) qwquicksort_s(arr, 0, len)

#define quicksort_c(arr, len) quicksort_c_s(arr, 0, len)
#define quicksort_i(arr, len) quicksort_i_s(arr, 0, len)
#define quicksort_l(arr, len) quicksort_l_s(arr, 0, len)
#define quicksort_ll(arr, len) quicksort_ll_s(arr, 0, len)

#define quicksort_f(arr, len) quicksort_f_s(arr, 0, len)
#define quicksort_d(arr, len) quicksort_d_s(arr, 0, len)
