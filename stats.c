/**
 * @file stats.c
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 24 May 2014
 *
 * Functions for stats calculation.
 */

#include <stdio.h>
#include "stats.h"
#include "sort.h"

/**
 * stat_min - find the minimum key in an array.
 */
int stat_min(int * input, int size) {
    int min = input[0];
    for (int i = 1; i < size - 1; i++) {
        if (input[i] < min) {
            min = input[i];
        }
    }
    return min;
}

/**
 * stat_max - find the maximum key in an array.
 */
int stat_max(int *input, int size) {
    int max = input[0];
    for (int i = 1; i < size - 1; i++) {
        if (input[i] > max) {
            max = input[i];
        }
    }
    return max;
}

/**
 * stat_ith_min - find ith order statistic of the given
 * array.
 */
int stat_ith_min(int *input, int size, int i) {
    return _stat_ith_min(input, 0, size - 1, i);
}

/**
 * _stat_ith_min - finds ith order statistic of the given
 * array. This partitions the input array and finds the
 * ith minimum key by calling itself recursively.
 */
int _stat_ith_min(int *input, int p, int r, int i) {
    if (p == r) {
        return input[p];
    }
    int q = _sort_quick_partition_rand(input, p, r);
    if (i == q) {
        return input[q];
    }
    if (i < q) {
        return _stat_ith_min(input, p, q - 1, i);
    }
    return _stat_ith_min(input, q + 1, r, i - q);
}
