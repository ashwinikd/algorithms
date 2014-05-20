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

int main(int argc, const char * argv[])
{
    int arr[10] = {-3,6,5,4,-7,3,2,1,-2};
//    printf("Number of inversions %d\n", count_inversion(arr, 7));
//    for (int i = 0; i < 7; i++) {
//        printf("%d \n", arr[i]);
//    }
    
    maxsubarray_result result = maxsubarray(arr, 8);
    printf("left: %d, right: %d, sum: %d\n", result.lo, result.hi, result.sum);
    
    result = maxsubarray_linear(arr, 8);
    printf("left: %d, right: %d, sum: %d\n", result.lo, result.hi, result.sum);
    
}

