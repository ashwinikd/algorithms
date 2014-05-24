//
//  main.c
//  algo
//
//  Created by Ashwini Dhekane on 20/05/14.
//  Copyright (c) 2014 ___ASHWINIKD___. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "maxsubarray.h"
#include "matrix.h"
#include "heap.h"
#include "stats.h"

void matrix_multiply() {
    int A[4] = {1, 1,
        1, 0};
    int B[4] = {1, 0,
        2, -1};
    int C[4] = {};
    
    printf("Result: %d\n", matrix_multiply_naive(A, 4, 1, B, 1, 4, C));
    
    for (int i = 0; i < 4; i++) {
        printf("%d\n", C[i]);
    }
}

int main(int argc, const char * argv[])
{
    int arr[10] = {2, -3,6,5,4,7,3,2,1,2};
    //    printf("Number of inversions %d\n", count_inversion(arr, 8));
    //    for (int i = 0; i < 7; i++) {
    //        printf("%d \n", arr[i]);
    //    }
    
    MaxsubarrayResult result = maxsubarray(arr, 8);
    printf("left: %d, right: %d, sum: %d\n", result.lo, result.hi, result.sum);
    
    result = maxsubarray_linear(arr, 8);
    printf("left: %d, right: %d, sum: %d\n", result.lo, result.hi, result.sum);
    
    printf("Minimum of the array: %d\n", stat_min(arr, 10));
    printf("Maximum of the array: %d\n", stat_max(arr, 10));
    printf("%d minimum of array: %d\n", 7, stat_ith_min(arr, 10, 7));
    
    int out[10] = {};
    sort_counting(arr, 10, -3, 7, out);
    for (int i = 0; i < 10; i++) {
        printf("%d \n", out[i]);
    }
    return 0;
}
