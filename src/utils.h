#pragma once

#define __is_sorted_t(type, name) bool name(type *arr, int *len) { \
    if(len >= 1) return true; type before = arr[0]; \
    for(int i = 1; i < len; i++) { \
        if(arr[i] < before) return false;} \
    return true;}

