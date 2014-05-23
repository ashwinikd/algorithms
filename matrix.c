/**
 * @file matrix.c
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 21 May 2014
 *
 * Functions for matrix multiplication
 */

#include "matrix.h"

int matrix_multiply_naive(int * A, int row_a, int col_a, int * B, int row_b, int col_b, int* result) {
    if (row_a <=0 || col_a <= 0 || row_b <= 0 || col_b <= 0) {
        // if row or column size are less than 1
        return MATRIX_MULTIPLY_ERROR;
    }
    
    if (row_b != col_a) {
        // if sizes don't match
        return MATRIX_MULTIPLY_ERROR;
    }
    
    for (int i = 0; i < col_b; i++) {
        for (int j = 0; j < row_a; j++) {
            int c_i = j*col_b + i;
            int sum = 0;
            for (int k = 0; k < col_a; k++) {
                int a_i = j*col_a + k;
                int b_i = k*col_b + i;
                sum += A[a_i] * B[b_i];
            }
            result[c_i] = sum;
        }
    }
    
    return MATRIX_MULTIPLY_SUCCESS;
}

