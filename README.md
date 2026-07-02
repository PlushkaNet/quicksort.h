# quicksort.h
## One-header library with simple sorting methods
> **You can navigate into quicksort_example.c to see example of usage**

## Avaliable methods:
- `bquicksort` (for sorting bytes)
- `wquicksort` (for sorting WORDs)
- `dwquicksort` (for sorting DWORDs)
- `qwquicksort` (for sorting QWORDs)
- `quicksort_c` (for sorting chars)
- `quicksort_i` (for sorting integers)
- `quicksort_l` (for sorting longs)
- `quicksort_ll` (for sorting long longs)
- `quicksort_f` (for sorting floats)
- `quicksort_d` (for sorting doubles)
- `bquicksort_s` (for sorting bytes only in exact memory range)
- `wquicksort_s` (for sorting WORDs only in exact memory range)
- `dwquicksort_s` (for sorting DWORDs only in exact memory range)
- `qwquicksort_s` (for sorting QWORDs only in exact memory range)
- `quicksort_c_s` (for sorting chars only in exact memory range)
- `quicksort_i_s` (for integers chars only in exact memory range)
- `quicksort_l_s` (for sorting longs only in exact memory range)
- `quicksort_ll_s` (for sorting long longs only in exact memory range)
- `quicksort_f_s` (for sorting floats only in exact memory range)
- `quicksort_d_s` (for sorting doubles only in exact memory range)

## Convenience methods
- `is_bsorted` (checks if array of bytes is sorted)
- `is_wsorted` (checks if array of WORDs is sorted)
- `is_dwsorted` (checks if array of DWORDs is sorted)
- `is_qwsorted` (checks if array of QWORDs is sorted)
- `is_sorted_c` (checks if array of chars is sorted)
- `is_sorted_i` (checks if array of integers is sorted)
- `is_sorted_l` (checks if array of longs is sorted)
- `is_sorted_ll` (checks if array of long longs is sorted)
- `is_sorted_f` (checks if array of floats is sorted)
- `is_sorted_d` (checks if array of doubles is sorted)

### Internal bool type
Result of is_sorted-like method is always a bool-like variable. In C++ it is standart bool. In C - it is unsigned char (int8bit). For convenience you can use `_qs_type_BOOL` type, which represents internal bool type.

#### _qs_type_BOOL states:
- `qs_TRUE` is true
- `qs_FALSE` is false
