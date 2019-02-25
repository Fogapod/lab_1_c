#include <iostream>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

#define GOLDN_RATIO (1 + sqrt(5)) / 2

void print_arr(const int *array, const int &len);

// 1
int find_index_iterative(const int *array, const int &len, const int &item);

// 2
int find_index_barrier(const int *array, const int &len, const int &item);

// 4
int find_index_binary(const int *array, const int &len, const int &item);

// 5
int find_index_binary_golden_ratio(const int *array, const int &len, const int &item);

int main()
{
    std::srand(std::time(nullptr));

    int array_len;

    std::cout << "Enter array len: ";
    std::cin >> array_len;
    if (array_len < 1) {
        std::cout << "Array len should be > 1" << std::endl;
        return 1;
    }

    int item;
    int *arr = new int[static_cast<unsigned long>(array_len)];


    for (int i = 0; i < array_len; i++) {
        arr[i] = std::rand() % 20 + 1;
    }

    std::cout << "Random array: ";
    print_arr(arr, array_len);

    std::cout << "Enter item to search: ";
    std::cin >> item;

    std::cout << "Searching for: " << item << std::endl;

    std::cout << "Algo 1: " << find_index_iterative(arr, array_len, item) << std::endl;
    std::cout << "Algo 2: " << find_index_barrier(arr, array_len, item) << std::endl;

    std::sort(arr, arr + array_len);
    std::cout << "Sorted array: ";
    print_arr(arr, array_len);

    std::cout << "Algo 4: " << find_index_binary(arr, array_len, item) << std::endl;
    std::cout << "Algo 5: " << find_index_binary_golden_ratio(arr, array_len, item) << std::endl;

    return 0;
}

void print_arr(const int *array, const int &len)
{
    std::cout << "[ ";
    for (int i = 0; i < len; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

// 1 comparisons: 2n + 1
int find_index_iterative(const int *array, const int &len, const int &item)
{
    for (int i = 0; i < len; i++) {
        if (array[i] == item) return i;
    }

    return -1;
}

// 2 comparisons: n (+1)
int find_index_barrier(const int *array, const int &len, const int &item)
{
    int *barrier_array = new int[static_cast<unsigned long>(len + 1)];
    for (int i = 0; i < len; i++) {
        barrier_array[i] = array[i];
    }
    barrier_array[len] = item;

    int i = 0;
    while (*barrier_array++ != item) i++;

    delete[] (barrier_array - i - 1);

    return i == len? -1: i;
}

// 4 comparisons: ln(n) + 1
int find_index_binary(const int *array, const int &len, const int &item)
{
    int l = 0;
    int r = len - 1;
    int m;

    while (l < r) {
        m = (l + r) / 2;
        if (array[m] < item) l = m + 1;
        else r = m;
    }

    return array[r] == item? r: -1;
}

// 5 comparisons: ln(n * GOLDEN_RATIO) + 1
int find_index_binary_golden_ratio(const int *array, const int &len, const int &item)
{
    int l = 0;
    int r = len - 1;
    int m = l;

    while (l < r) {
        m = l + static_cast<int>((r - l) / GOLDN_RATIO);
        if (array[m] < item) l = m + 1;
        else r = m;
    }

    return array[r] == item? r: -1;
}
