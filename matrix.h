/**
 * @file matrix.h
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 21 May 2014
 *
 * Functions for matrix multiplication
 */

#ifndef __AKD_MATRIX_H__
#define __AKD_MATRIX_H__

#define MATRIX_MULTIPLY_ERROR 1
#define MATRIX_MULTIPLY_SUCCESS 0

/**
 * matrix_multiply_naive - multiplies matrices A[row_a][col_a] and
 *   B[row_b][col_b] and stores the result in result. There are no
 *   error checks here `result` should be big enough to store the
 *   result of multiplication. The element position is calculated
 *   as 
 *        A[i, j] = i * row_a + j
 * 
 *   Returns MATRIX_MULTIPLY_SUCCESS if multiplication was successful
 *   or MATRIX_MULTIPLY_ERROR otherwise.
 */
int matrix_multiply_naive(int * A, int row_a, int col_a, int * B, int row_b, int col_b, int* result);

#endif
