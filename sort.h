/**
 * @file sort.h
 * @author Ashwini Kumar Dhekane<ashwini@ashwinidhekane.com>
 * @date 20 May 2014
 *
 * Functions for sorting integers. All functions sort in ascending
 * order unless stated otherwise. Following algorithms are declared:
 *   - Insertion Sort
 *   - Merge Sort
 *   - Quick Sort
 *   - Bubble Sort
 *   - Binary Search
 *   - Inversion Count
 */



#ifndef __AKD_ALGO_SORT_H__
#define __AKD_ALGO_SORT_H__

///////////////////////////////////////////////////////////////////////
////////////////////////// INSERTION SORT /////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * sort_insertion - sort the given array of a given size using
 *  insertion sort.
 *
 * Example:
 *   int[4] A = {3,1,4,6};
 *   sort_insertion(A, 4);
 */
void sort_insertion(int *input, int size);



///////////////////////////////////////////////////////////////////////
//////////////////////////// MERGE SORT ///////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * sort_merge - sort the array `input` of size `size` using
 *   merge sort.
 *
 * Example:
 *   int[4] A = {3,1,4,6};
 *   sort_merge(A, 4);
 */
void sort_merge(int *input, int size);

/**
 * _merge_sort - implementation of merge sort algorithm which calls itself
 *   recursively.
 */
void _merge_sort(int *input, int start, int end);

/**
 * _merge - merge subroutine for merge sort algorithm.
 */
void _merge(int *input, int p, int q, int r);



///////////////////////////////////////////////////////////////////////
//////////////////////////// QUICK SORT ///////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * sort_quick - sort the array `input` of size `size` using quick
 *   sort.
 *
 * Example:
 *   int[4] A = {3,1,4,6};
 *   sort_quick(A, 4);
 */
void sort_quick(int *input, int size);

/**
 * _sort_quick - implementation of quick sort algorithm.
 */
void _sort_quick(int *input, int p, int r);

/**
 * _sort_quick_partition - partition subroutine for quick sort which
 *    calculates the the pivot using the last input[r].
 */
int _sort_quick_partition(int *input, int p, int r);

/**
 * _sort_quick_partition_rand - partition subroutine for quick sort
 *   which calculates the pivot using a random element in range
 *   input[p...r]
 */
int _sort_quick_partition_rand(int *input, int p, int r);

/**
 * _sort_quick_partition_hoare - partition subroutine for quick sort
 *   which calculates the pivot according to C. A. R. Hoare's
 *   partitioning algorithm.
 */
int _sort_quick_partition_hoare(int *input, int p, int r);



///////////////////////////////////////////////////////////////////////
//////////////////////////// BUBBLE SORT //////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * sort_bubble - sort the array `input` of size `size` using bubble sort.
 *
 * Example:
 *   int[4] A = {3,1,4,6};
 *   sort_bubble(A, 4);
 */
void sort_bubble(int *input, int size);



///////////////////////////////////////////////////////////////////////
////////////////////// SORTING IN LINEAR TIME /////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * sort_counting - sorts the input array with given minimum and maximum
 * keys and stores the sorted array in output. The sort uses counting
 * sort to sort the array. There are no error checks output array should
 * be large enough to store the output.
 */
void sort_counting(int *input, int size, int min_key, int max_key, int *output);



///////////////////////////////////////////////////////////////////////
/////////////////////////// BINARY SEARCH /////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * search_binary - search for `key` in sorted array `input` of size `size`.
 *
 * Function will return -1 if key is not found or if size is 0. Otherwise
 * the it will return the index of key in the array.
 */
int search_binary(int *input, int key, int size);

/**
 * _search_binary - implementation of recursive algorithm for binary search
 *   on a sorted array.
 */
int _search_binary(int *input, int key, int start, int end);



///////////////////////////////////////////////////////////////////////
///////////////////////// INVERSION COUNT /////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * count_inversion - count number of inversions in an array of a given size.
 */
int count_inversion(int *input, int size);

/**
 * _count_inversion - implementation of recursive algorithm for counting
 *   number of inversions in an array using divide and conquer. This is the
 *   divide part of the algorithm.
 */
int _count_inversion(int *input, int start, int end);

/**
 * _count_inversion_merge - combine part of divide-and-conquer algorithm for
 *   counting inversions.
 */
int _count_inversion_merge(int *input, int p, int q, int r);



///////////////////////////////////////////////////////////////////////
/////////////////////////////// MISC //////////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * _rand_between - returns a random int between lo and hi.
 */
int _rand_between(int lo, int hi);

#endif
