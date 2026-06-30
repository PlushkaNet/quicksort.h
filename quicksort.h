#pragma once

#ifndef BYTE
typedef char BYTE;
#endif

#ifndef WORD
typedef int WORD;
#endif

#ifndef DWORD
typedef long DWORD;
#endif

#ifndef QWORD
typedef long long QWORD;
#endif

typedef char _QS_BYTE;
typedef int _QS_WORD;
typedef long _QS_DWORD;
typedef long long _QS_QWORD;
typedef float _QS_FLOAT;
typedef double _QS_DOUBLE;

#ifdef __cplusplus
typedef bool _QS_BOOL;
#define _QS_TRUE true
#define _QS_FALSE false
#else
typedef unsigned char _QS_BOOL;
#define _QS_TRUE 1
#define _QS_FALSE 0
#endif

#define __swap_t(type, a, b) type c = a; a = b; b = c;
#define __quicksort_t(type, name) void name(type *arr, _QS_WORD start, _QS_WORD len) { \
    if(start >= len) return; type pivot = arr[start]; _QS_WORD i = start-1; \
    for(_QS_WORD j = start+1; j < len; j++) { \
        if(arr[j] < pivot) { \
            _QS_WORD it = ++i; __swap_t(type, arr[it], arr[j]) }} \
    name(arr, start, ++i); \
    for(_QS_WORD j = i; j < len; j++) { \
        if(arr[j] == pivot) { \
            _QS_WORD it = i++; __swap_t(type, arr[it], arr[j]) }} \
    name(arr, i, len);}

__quicksort_t(BYTE,  bquicksort_s  )
__quicksort_t(WORD,  wquicksort_s  )
__quicksort_t(DWORD, dwquicksort_s )
__quicksort_t(QWORD, qwquicksort_s )

__quicksort_t(_QS_FLOAT, quicksort_f_s )
__quicksort_t(_QS_DOUBLE, quicksort_d_s)

#if BYTE == _QS_BYTE
#define quicksort_c_s  bquicksort_s
#else
__quicksort_t(_QS_BYTE, quicksort_c_s)
#endif

#if WORD == _QS_WORD
#define quicksort_i_s  wquicksort_s
#else
__quicksort_t(_QS_WORD, quicksort_i_s)
#endif

#if DWORD == _QS_DWORD
#define quicksort_l_s  dwquicksort_s
#else
__quicksort_t(_QS_DWORD, quicksort_l_s)
#endif

#if QWORD == _QS_QWORD
#define quicksort_ll_s qwquicksort_s
#else
__quicksort_t(_QS_QWORD, quicksort_ll_s)
#endif

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

#define __is_sorted_t(type, name) _QS_BOOL name(type *arr, _QS_WORD len) { \
    if(len <= 1) return _QS_TRUE; \
    for(int i = 1; i < len; i++) { \
        if(arr[i-1] > arr[i]) return _QS_FALSE;} \
    return _QS_TRUE;}

__is_sorted_t(BYTE,  is_bsorted)
__is_sorted_t(WORD,  is_wsorted)
__is_sorted_t(DWORD, is_dwsorted)
__is_sorted_t(QWORD, is_qwsorted)

#if BYTE == _QS_BYTE
#define is_sorted_c is_bsorted
#else
__is_sorted_t(_QS_BYTE, is_sorted_c)
#endif

#if WORD == _QS_WORD
#define is_sorted_i is_wsorted
#else
__is_sorted_t(_QS_WORD, is_sorted_i)
#endif

#if DWORD == _QS_DWORD
#define is_sorted_l is_dwsorted
#else
__is_sorted_t(_QS_DWORD, is_sorted_l)
#endif

#if QWORD == _QS_QWORD
#define is_sorted_ll is_qwsorted
#else
__is_sorted_t(_QS_QWORD, is_sorted_ll)
#endif

__is_sorted_t(_QS_FLOAT, is_sorted_f)
__is_sorted_t(_QS_DOUBLE, is_sorted_d)
