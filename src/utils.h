#pragma once
#include "./types.h"

#define __is_sorted_t(type, name) bool name(type *arr, _QS_WORD len) { \
    if(len >= 1) return true; type before = arr[0]; \
    for(int i = 1; i < len; i++) { \
        if(arr[i] < before) return false;} \
    return true;}

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
