/**
 * @file maxsubarray.h
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 21 May 2014
 *
 * Algorithm for calculating maximum subarray.
 */

#ifndef __AKD_ALGO_MAXSUBARRAY_H__
#define __AKD_ALGO_MAXSUBARRAY_H__

/**
 * maxsubarray_result - the maximum subarray. This holds
 * the low and high indexes of the maximum subarray and
 * its sum
 */
typedef struct {
    int lo;
    int hi;
    int sum;
} maxsubarray_result;

/**
 * maxsubarray - returns the maximum subarray using
 * divide and conquer approach. The time complexity of this
 * function is O(n*lg(n)).
 */
maxsubarray_result maxsubarray(int *input, int size);

/**
 * maxsubarray_linear - returns the maximum subarray in linear
 * time O(n).
 */
maxsubarray_result maxsubarray_linear(int *input, int size);

/**
 * _maxsubarray - implementation of recursive algorithm for
 * calculating the maximum subarray of input[lo ... hi]
 */
maxsubarray_result _maxsubarray(int *input, int lo, int hi);

/**
 * _maxsubarray_crossing - calculates the maximum subarray 
 * which crosses the mid point. This is used as a subroutine
 * by _maxsubarray.
 */
maxsubarray_result _maxsubarray_crossing(int *input, int lo, int mid, int hi);

#endif
