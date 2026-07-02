// SPDX-License-Identifier: MIT
/*
 * Copyright (C) 2026 PlushkaNet (github.com/PlushkaNet)
 */

#pragma once

/*
 * This header provides macro-generated, type-safe quicksort functions
 * for integer and floating-point types.
 * The algorithm uses three-way partitioning, this grants high performance
 * even on arrays with many duplicates.
 *
 * General features:
 * - Strongly-typed functions.
 * - Automatic adaptation to custom type macros: if `BYTE`, `WORD`, `DWORD`, or
 *   `QWORD` are defined before inclusion, the corresponding sort functions
 *   are generated for those types; otherwise standard types (char, int, long,
 *   long long) are used.
 * - Convenience is_sorted_* functions that return `qs_TRUE` or `qs_FALSE`.
 * 
 * Usage example:
 * @code
 *   #include "quicksort.h"
 *   int main() {
 *       int arr[5] = {91, 23, 999, -912, 0};
 *       quicksort_i(arr, 5);                  // sort the array
 *       if(is_sorted_i(arr, 5) == qs_TRUE) {
 *           // array is sorted
 *       }
 *   }
 * @endcode
 */

typedef char _qs_type_BYTE;
typedef int _qs_type_WORD;
typedef long _qs_type_DWORD;
typedef long long _qs_type_QWORD;
typedef float _qs_type_FLOAT;
typedef double _qs_type_DOUBLE;

#ifdef __cplusplus
typedef bool _qs_type_BOOL;
#define _qs_TRUE true
#define _qs_FALSE false
#else
typedef unsigned char _qs_type_BOOL;
#define _qs_TRUE 1
#define _qs_FALSE 0
#endif

#define _qs_quicksort_swap_t(type, a, b) type c = a; a = b; b = c;
#define _qs_quicksort_t(type, name) void name(type *arr, _qs_type_WORD start, _qs_type_WORD len) { \
    if((len-start) <= 1) return; type pivot = arr[(len+start)/2]; _qs_type_WORD i = start; \
    for(_qs_type_WORD j = start; j < len; j++) { \
        if(arr[j] < pivot) { _qs_quicksort_swap_t(type, arr[i], arr[j]); i++; }} \
    name(arr, start, i); \
    for(_qs_type_WORD j = i; j < len; j++) { \
        if(arr[j] == pivot) { _qs_quicksort_swap_t(type, arr[i], arr[j]); i++; }} \
    name(arr, i, len); }

#define _qs_is_sorted_t(type, name) _qs_type_BOOL name(type *arr, _qs_type_WORD len) { \
    if(len <= 1) return _qs_TRUE; \
    for(_qs_type_WORD i = 1; i < len; i++) { \
        if(arr[i-1] > arr[i]) return _qs_FALSE; } \
    return _qs_TRUE; }

#ifdef BYTE
_qs_quicksort_t(BYTE, bquicksort_s)
_qs_is_sorted_t(BYTE, is_bsorted)

#if BYTE == _qs_type_BYTE
#define _qs_alias_BYTE
#endif

#else
#define _qs_alias_BYTE
_qs_quicksort_t(_qs_type_BYTE, bquicksort_s)
_qs_is_sorted_t(_qs_type_BYTE, is_bsorted)
#endif

#ifdef WORD
_qs_quicksort_t(WORD, wquicksort_s)
_qs_is_sorted_t(WORD, is_wsorted)

#if WORD == _qs_type_WORD
#define _qs_alias_WORD
#endif

#else
#define _qs_alias_WORD
_qs_quicksort_t(_qs_type_WORD, wquicksort_s)
_qs_is_sorted_t(_qs_type_WORD, is_wsorted)
#endif

#ifdef DWORD
_qs_quicksort_t(DWORD, dwquicksort_s)
_qs_is_sorted_t(DWORD, is_dwsorted)

#if DWORD == _qs_type_DWORD
#define _qs_alias_DWORD
#endif

#else
#define _qs_alias_DWORD
_qs_quicksort_t(_qs_type_DWORD, dwquicksort_s)
_qs_is_sorted_t(_qs_type_DWORD, is_dwsorted)
#endif

#ifdef QWORD
_qs_quicksort_t(QWORD, qwquicksort_s)
_qs_is_sorted_t(QWORD, is_qwsorted)

#if QWORD == _qs_type_QWORD
#define _qs_alias_QWORD
#endif

#else
#define _qs_alias_QWORD
_qs_quicksort_t(_qs_type_QWORD, qwquicksort_s)
_qs_is_sorted_t(_qs_type_QWORD, is_qwsorted)
#endif

_qs_quicksort_t(_qs_type_FLOAT, quicksort_f_s)
_qs_quicksort_t(_qs_type_DOUBLE, quicksort_d_s)

#ifdef _qs_alias_BYTE
#define quicksort_c_s bquicksort_s
#define is_sorted_c is_bsorted
#else
_qs_quicksort_t(_qs_type_BYTE, quicksort_c_s)
_qs_is_sorted_t(_qs_type_BYTE, is_sorted_c)
#endif

#ifdef _qs_alias_WORD
#define quicksort_i_s wquicksort_s
#define is_sorted_i is_wsorted
#else
_qs_quicksort_t(_qs_type_WORD, quicksort_i_s)
_qs_is_sorted_t(_qs_type_WORD, is_sorted_i)
#endif

#ifdef _qs_alias_DWORD
#define quicksort_l_s dwquicksort_s
#define is_sorted_l is_dwsorted
#else
_qs_quicksort_t(_qs_type_DWORD, quicksort_l_s)
_qs_is_sorted_t(_qs_type_DWORD, is_sorted_l)
#endif

#ifdef _qs_alias_QWORD
#define quicksort_ll_s qwquicksort_s
#define is_sorted_ll is_qwsorted
#else
_qs_quicksort_t(_qs_type_QWORD, quicksort_ll_s)
_qs_is_sorted_t(_qs_type_QWORD, is_sorted_ll)
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

_qs_is_sorted_t(_qs_type_FLOAT, is_sorted_f)
_qs_is_sorted_t(_qs_type_DOUBLE, is_sorted_d)

#define qs_TRUE _qs_TRUE
#define qs_FALSE _qs_FALSE
