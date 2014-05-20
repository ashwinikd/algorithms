//
//  maxsubarray.c
//  algo
//
//  Created by Ashwini Dhekane on 20/05/14.
//  Copyright (c) 2014 ___ASHWINIKD___. All rights reserved.
//

#include "maxsubarray.h"

maxsubarray_result maxsubarray(int *input, int size) {
    return _maxsubarray(input, 0, size - 1);
}

maxsubarray_result maxsubarray_linear(int *input, int size) {
    maxsubarray_result result;
    result.lo = 0;
    result.hi = 0;
    result.sum = input[0];
    
    int remaining_sum = 0;
    
    maxsubarray_result _result;
    _result.lo = -1;
    _result.hi = -1;
    _result.sum = 0;
    
    for (int i = 1; i < size; i++) {
        int full_sum = result.sum + remaining_sum + input[i];
        if (_result.lo < 0) {
            if (input[i] >= full_sum) {
                result.hi = i;
                result.sum = full_sum;
            } else {
                _result.lo = i;
                _result.hi = i;
                _result.sum = input[i];
                remaining_sum += input[i];
            }
        } else {
            int curr_sum = _result.sum + input[i];
            if (input[i] >= curr_sum && input[i] >= result.sum && input[i] >= full_sum) {
                result.lo = i;
                result.hi = i;
                result.sum = input[i];
                _result.lo = -1;
                _result.hi = -1;
                _result.sum = 0;
                remaining_sum = 0;
            } else if (curr_sum >= input[i] && curr_sum >= result.sum && curr_sum >= full_sum) {
                result.lo = _result.lo;
                result.hi = i;
                result.sum = curr_sum;
                _result.lo = -1;
                _result.hi = -1;
                _result.sum = 0;
                remaining_sum = 0;
            } else if (full_sum >= input[i] && full_sum >= curr_sum && full_sum >= curr_sum) {
                result.hi = i;
                result.sum = full_sum;
                _result.lo = -1;
                _result.hi = -1;
                _result.sum = 0;
                remaining_sum = 0;
            } else {
                remaining_sum += input[i];
                if (curr_sum >= input[i]) {
                    _result.hi = i;
                    _result.sum = curr_sum;
                } else {
                    _result.lo = i;
                    _result.hi = i;
                    _result.sum = input[i];
                }
            }
        }
    }
    
    return result;
}

maxsubarray_result _maxsubarray(int *input, int lo, int hi) {
    maxsubarray_result result;
    
    if (lo == hi) {
        result.lo = lo;
        result.hi = lo;
        result.sum = input[hi];
        return result;
    }
    
    int mid = (lo + hi) / 2;
    maxsubarray_result left = _maxsubarray(input, lo, mid);
    maxsubarray_result right = _maxsubarray(input, mid + 1, hi);
    maxsubarray_result cross = _maxsubarray_crossing(input, lo, mid, hi);
    
    if (left.sum >= right.sum && left.sum >= cross.sum) {
        return left;
    } else if (right.sum >= left.sum && right.sum >= cross.sum) {
        return right;
    } else {
        return cross;
    }
}

maxsubarray_result _maxsubarray_crossing(int *input, int lo, int mid, int hi) {
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
    
    maxsubarray_result result;
    result.lo = max_left;
    result.hi = max_right;
    result.sum = left_sum + right_sum;
    
    return result;
}
