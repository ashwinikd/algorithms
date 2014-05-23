/**
 * @file maxsubarray.c
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 21 May 2014
 *
 * Definitions for functions which calculating maximum subarray.
 */

#include "maxsubarray.h"


///////////////////////////////////////////////////////////////////////
/////////////////// DIVIDE & CONQUER [O(n*lg(n)] //////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * maxsubarray - calculates maximum subarray or given array
 * in O(n*lg(n)) time. This calls _maxsubarray on complete
 * range of the input array and returns its result.
 */
MaxsubarrayResult maxsubarray(int *input, int size) {
    return _maxsubarray(input, 0, size - 1);
}

/**
 * _maxsubarray - finds maximum subarray of range input[lo ... hi]
 * by recursively dividing the range into two equal halves. Then it
 * calculates the maximum subarray which crosses the mid point
 * using _maxsubarray_crossing. The result is the maximum of the
 * three viz. maxsubarray of left, maxsubarray or right or 
 * maxsubarray which crosses mid point.
 */
MaxsubarrayResult _maxsubarray(int *input, int lo, int hi) {
    MaxsubarrayResult result;
    
    if (lo == hi) { // if lo==hi we have single element (trivial)
        result.lo = lo;
        result.hi = lo;
        result.sum = input[hi];
        return result;
    }
    
    // divide the array into two equal halves
    int mid = (lo + hi) / 2;
    MaxsubarrayResult left = _maxsubarray(input, lo, mid);      // left half
    MaxsubarrayResult right = _maxsubarray(input, mid + 1, hi); // right half
    
    MaxsubarrayResult cross = _maxsubarray_crossing(input, lo, mid, hi); // maxsubarray of cross
    
    // return the maximum
    
    if (left.sum >= right.sum && left.sum >= cross.sum) {
        return left;
    } else if (right.sum >= left.sum && right.sum >= cross.sum) {
        return right;
    } else {
        return cross;
    }
}

/**
 * _maxsubarray_crossing - returns the maximum subarray of input[lo ... hi]
 * which crosses the mid point. 
 */
MaxsubarrayResult _maxsubarray_crossing(int *input, int lo, int mid, int hi) {
    int max_left = mid;
    int max_right = mid + 1;
    int left_sum = input[mid];
    int right_sum = input[mid + 1];
    
    int sum = left_sum;
    for (int i = mid - 1; i >= lo; i--) {
        sum += input[i];
        if (left_sum < sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    
    sum = right_sum;
    for (int i = mid + 2; i <= hi; i++) {
        sum += input[i];
        if (right_sum < sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    
    MaxsubarrayResult result;
    result.lo = max_left;
    result.hi = max_right;
    result.sum = left_sum + right_sum;
    
    return result;
}



///////////////////////////////////////////////////////////////////////
////////////////////////// LINEAR [O(n)] //////////////////////////////
///////////////////////////////////////////////////////////////////////

MaxsubarrayResult maxsubarray_linear(int *input, int size) {
    MaxsubarrayResult result;
    result.lo = 0;
    result.hi = 0;
    result.sum = input[0];
    
    MaxsubarrayResult _result;
    _result.lo = result.lo;
    _result.hi = result.hi;
    _result.sum = result.sum;
    
    int remaining_sum = 0;
    
    for (int i = 1; i < size; i++) {
        int sum = result.sum + remaining_sum + input[i];
        int adjacent_sum = _result.sum + input[i];
        if (sum >= input[i] && sum >= adjacent_sum && sum >= result.sum) {
            // input[result.lo ... i] is the max subarray
            result.hi = i;
            result.sum = sum;
            _result.lo = result.lo;
            _result.hi = i;
            _result.sum = sum;
            remaining_sum = 0;
        } else if (adjacent_sum >= sum && adjacent_sum >= input[i] && adjacent_sum >= result.sum) {
            // input[_result.lo ... i] is the max subarray
            result.lo = _result.lo;
            result.hi = i;
            result.sum = adjacent_sum;
            _result.hi = i;
            _result.sum = adjacent_sum;
            remaining_sum = 0;
        } else if (result.sum >= sum && result.sum >= adjacent_sum && result.sum >= input[i]) {
            // input[result.lo ... result.hi] is the max subarray
            remaining_sum += input[i];
            if (adjacent_sum >= input[i]) {
                _result.hi = i;
                _result.sum = adjacent_sum;
            } else {
                _result.lo = i;
                _result.hi = i;
                _result.sum = input[i];
            }
        } else {
            // input[i ... i] is the max subarray
            result.lo = i;
            result.hi = i;
            result.sum = input[i];
            _result.lo = i;
            _result.hi = i;
            _result.sum = input[i];
            remaining_sum = 0;
        }
    }
    
    return result;
}
