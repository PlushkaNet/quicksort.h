#include <cstdlib>
#include <functional>
#include <iostream>
#include <chrono>

#include "quicksort.h"

template <typename T>
T *generate_large_data(int len) {
    T *arr = new T[len];
    for(int i = 0; i < len; i++) {
        arr[i] = std::rand();
    }
    return arr;
}

template <typename T>
bool run_test_only(std::function<void(T*, int, int)> sort_func, std::function<bool(T*, int)> check_func, T *data, int len) {
    auto start = std::chrono::high_resolution_clock::now();
    sort_func(data, 0, len);
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "sorting complete in " << (stop-start).count() / 1000000 << " ms (started at: " <<
        start.time_since_epoch().count() << ", ended at: " << stop.time_since_epoch().count() << ")\n";
    return check_func(data, len);
}

template <typename T>
bool run_test(std::function<void(T*, int, int)> sort_func, std::function<bool(T*, int)> check_func, int len) {
    T *data = generate_large_data<T>(len);
    std::cout << "data generated\n";
    bool status = run_test_only<T>(sort_func, check_func, data, len);
    delete[] data;
    return status;
}

int main() {
    enum {ARR_LENGTH = 10000000};
    std::cout << "testing quicksort for 10 million items\n";
    if(!run_test<int>(quicksort_i_s, is_sorted_i, ARR_LENGTH)) return 1;
    std::cout << "test quicksort_i_s passed\n";
}
