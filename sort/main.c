//
//  main.c
//  algo
//
//  Created by Ashwini Dhekane on 20/05/14.
//  Copyright (c) 2014 ___ASHWINIKD___. All rights reserved.
//

#include <stdio.h>
#include "sort.h"

int main(int argc, const char * argv[])
{
    int arr[10] = {6,5,4,3,2,1};
    printf("Number of inversions %d\n", count_inversion(arr, 6));
    for (int i = 0; i < 6; i++) {
        printf("%d \n", arr[i]);
    }
}

