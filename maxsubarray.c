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
 * which crosses the mid point. This works by starting at the mid index and
 * moving in both directions while calculating the maximum sum of the left
 * and right part which includes the mid key.
 */
MaxsubarrayResult _maxsubarray_crossing(int *input, int lo, int mid, int hi) {
    int max_left = mid;              // at the end [max_left ... mid] will have max sum in left
    int max_right = mid + 1;         // at the end [mid+1 ... max_right] will have max sum in right
    int left_sum = input[mid];       // tracks the max sum for left part
    int right_sum = input[mid + 1];  // tracks the max sum for right part
    
    // calculate the max sum of left and associated index
    int sum = left_sum; // tracks the sum of left part
    for (int i = mid - 1; i >= lo; i--) {
        sum += input[i];
        if (left_sum < sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    
    // calculate the max sum of right and associated index
    sum = right_sum; // tracks the sum of right part
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

/**
 * maxsubarray_linear - calculates the maximum subarray in O(n). 
 * 
 * Algorithm:
 * We traverse the array from start to end and keep track of the
 * maximum subarray that we have encountered so far (lo, hi, sum). Other
 * than this we keep track of remaining sum (r) i.e. the sum of keys 
 * which occur after last index of maximum subarray upto the last key
 * before current key. We track another maximum subarray which
 * includes the last key (local_lo, i-1, local_sum).
 * 
 *     current_maxsubarray = (lo, hi, sum)
 *     remaining_sum       = r
 *     local_maxsubarray   = (local_lo, i - 1, local_sum)
 *     current_index       = i
 *     current_key         = key
 * 
 * The maximum subarray of A[0 ... i] is one of the following:
 *
 *     (lo, hi, sum)
 *     (lo, i, sum+r+key)
 *     (local_lo, i, local_sum+key)
 *     (i, i, key)
 *
 * We determine the correct subarray by compairing their sums. We
 * also update r and local_maxsubarray accordingly as we move forward.
 *
 * Note that:
 *     hi < local_lo < i
 * and we are not including any subarray of form (p, q, _sum) where
 *     _sum = sum of keys in A[p ... q]
 *     lo < p <= hi
 *     p <= q < i
 * We discard this subarray because
 *     _sum <= sum
 * 
 * At the end of every i^th iteration we have the maximum subarray
 * of A[0 ... i]. Hence when the loop terminates at i = size we have
 * the maximum subarray of A[0 ... size-1] which is our input array.
 */
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
