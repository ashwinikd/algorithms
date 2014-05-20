//
//  maxsubarray.h
//  algo
//
//  Created by Ashwini Dhekane on 20/05/14.
//  Copyright (c) 2014 ___ASHWINIKD___. All rights reserved.
//

#ifndef algo_maxsubarray_h
#define algo_maxsubarray_h

typedef struct {
    int lo;
    int hi;
    int sum;
} maxsubarray_result;

maxsubarray_result maxsubarray(int *input, int size);
maxsubarray_result maxsubarray_linear(int *input, int size);
maxsubarray_result _maxsubarray(int *input, int lo, int hi);
maxsubarray_result _maxsubarray_crossing(int *input, int lo, int mid, int hi);

#endif
