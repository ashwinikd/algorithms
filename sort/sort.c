/**
 * @file sort.c
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 20 May 2014
 * 
 * Definitions for functions for sorting integers defined in sort.h.
 */

#include "sort.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>


///////////////////////////////////////////////////////////////////////
////////////////////////// INSERTION SORT /////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * sort_insertion - implementation of insertion sort algorithm. This
 *   function will return if the size of input is less than 2 as in
 *   such a case the input is already sorted. Otherwise it will loop
 *   through all keys and insert them in their appropriate positions.
 */
void sort_insertion(int *input, int size) {
    
    // return if the size is 0 or 1
	if(size < 2) {
		return;
	}

    /*
     * Loop invariant: At the starting of every iteration 
     *   the array input[0 ... i-1] is sorted.
     */
	for(int i = 1; i < size; i++) {
		int key = input[i];
		int j = i -1;
        
        /*
         * Loop invariant: At the beginning of every iteration
         *   for all k such that j < k <= i, input[k] > input[j]
         */
		for(; j >= 0 && input[j] > key; j--) {
			input[j + 1] = input[j];
		}
		input[j + 1] = key;
	}
}



///////////////////////////////////////////////////////////////////////
//////////////////////////// MERGE SORT ///////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * sort_merge - sorts the given array using merge sort. This calls
 *   _merge_sort which is the actual implementation of the sorting
 *   algorithm.
 */
void sort_merge(int *input, int size) {
	_merge_sort(input, 0, size - 1);
}

/**
 * _merge_sort - implementation of merge sort. This divides the
 *   input array into two equal halves and calls _merge_sort on
 *   them recursively. The index parameters start and end are
 *   both inclusive.
 */
void _merge_sort(int *input, int start, int end) {
    
    // if start == end then we have a single element which
    // is trivially sorted
	if(start < end) {
		int mid = (start + end) / 2;      /* divide into 2 equal halves */
		_merge_sort(input, start, mid);   /* _merge_sort(first half) */
		_merge_sort(input, mid + 1, end); /* _merge_sort(second half) */
		_merge(input, start, mid, end);   /* combine the results */
	}
}

/**
 * _merge - implementation of "combine" part of merge sort. This
 *   takes 4 inputs. The actual array, start index, end index and
 *   the pivot(mid) point. This function assumes that the arrays
 *   input[p ... q] and input[q+1 ... r] are already sorted.
 */
void _merge(int *input, int p, int q, int r) {
    
    // calculate the size of two arrays
	int size_l = q - p + 1; /* size of left array */
	int size_r = r - q;     /* size of right array */
    
    // create the left and right arrays and copy keys to them
	int *L = malloc(sizeof(int) * (size_l)); /* left array */
	int *R = malloc(sizeof(int) * (size_r)); /* right array */
    
	for(int i = 0; i < size_l; i++) {
		L[i] = input[p + i];
	}
	for(int i = 0; i < size_r; i++) {
		R[i] = input[q + i + 1];
	}
    
	int i = 0; /* index for left array */
	int j = 0; /* index for right array */
    int k = p; /* index for result array */
    
	for(k = p; k <= r; k++) {
        if(i >= size_l || j >= size_r) {
            break;
        }
        
		if(L[i] <= R[j]) {
			input[k] = L[i++];
		} else {
			input[k] = R[j++];
		}
	}
    
    //copy keys from from any array which is not empty.
    if(i == size_l) {
        for (; k <= r; k++) {
            input[k] = R[j++];
        }
    }
    
    if(j == size_r) {
        for (; k <= r; k++) {
            input[k] = L[i++];
        }
    }
    
    // release the auxillary arrays
	free(L);
	free(R);
}



///////////////////////////////////////////////////////////////////////
//////////////////////////// QUICK SORT ///////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * sort_quick - sort an array using quick sort. This calls 
 *   _sort_quick which is the actual implementation of quck sort
 *   algorithm.
 */
void sort_quick(int *input, int size) {
    _sort_quick(input, 0, size - 1);
}

/**
 * _sort_quick - implementation of quick sort algorithm. This
 *   calculates the pivot point using _sort_quick_partition_rand
 *   and then calls itself recursively on the two partitions. 
 *   This function can use _sort_quick_partion_rand or 
 *   _sort_quick_partition for calculating the pivot point.
 *   Do not use _sort_quick_partition_hoare for partitioning.
 */
void _sort_quick(int *input, int p, int r) {
    if (p < r) {
        int q = _sort_quick_partition_rand(input, p, r);
        _sort_quick(input, p, q - 1);
        _sort_quick(input, q + 1, r);
    }
}

/**
 * _sort_quick_partition - partition subroutine for quick sort. This
 *   will make the last key i.e. input[r] the pivot and return
 *   its index when partitioning is over.
 */
int _sort_quick_partition(int *input, int p, int r) {
    int pivot = input[r];
    int i = p - 1;
    
    int j = p;
    
    for (; j < r; j++) {
        if (input[j] <= pivot) {
            i++;
            int tmp = input[j];
            input[j] = input[i];
            input[i] = tmp;
        }
    }
    
    int tmp = input[++i];
    input[i] = input[j];
    input[j] = tmp;
    
    return i;
}

/**
 * _sort_quick_partition_rand - partition subroutine for quick sort. This
 *   will make a random key in range input[p ... r] the pivot and return
 *   its index when partitioning is over. This first selects a random a
 *   random key and exchanges it with the last key i.e. input[r]. After
 *   the exchange is done it works exactly as _sort_quick_partition.
 */
int _sort_quick_partition_rand(int *input, int p, int r) {
    int rand = _rand_between(p, r);
    int tmp = input[r];
    input[r] = input[rand];
    input[rand] = tmp;
    int pivot = input[r];
    int i = p - 1;
    
    int j = p;
    
    for (; j < r; j++) {
        if (input[j] <= pivot) {
            i++;
            tmp = input[j];
            input[j] = input[i];
            input[i] = tmp;
        }
    }
    
    tmp = input[++i];
    input[i] = input[j];
    input[j] = tmp;
    
    return i;
}

int _sort_quick_partition_hoare(int *input, int p, int r) {
    int pivot = input[p];
    int i = p - 1;
    int j = r + 1;
    while (1) {
        while (1) {
            j--;
            if (input[j] <= pivot) {
                break;
            }
        }
        
        while (1) {
            i++;
            if (input[i] >= pivot) {
                break;
            }
        }
        
        if (i < j) {
            int tmp = input[i];
            input[i] = input[j];
            input[j] = tmp;
        } else {
            return j;
        }
    }
}



///////////////////////////////////////////////////////////////////////
//////////////////////////// BUBBLE SORT //////////////////////////////
///////////////////////////////////////////////////////////////////////

void sort_bubble(int *input, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = size - 1; j > i; j--) {
            if(input[j] < input[j - 1]) {
                int tmp = input[j];
                input[j] = input[j - 1];
                input[j - 1] = tmp;
            }
        }
    }
}



///////////////////////////////////////////////////////////////////////
/////////////////////////// BINARY SEARCH /////////////////////////////
///////////////////////////////////////////////////////////////////////

int search_binary(int *input, int key, int size) {
    if(size == 0) {
        return -1;
    }
    return _search_binary(input, key, 0, size - 1);
}

int _search_binary(int *input, int key, int start, int end) {
    if(start == end && input[start] == key) {
        return start;
    }
    
    if(start == end) {
        return -1;
    }
    
    int mid = (start + end) / 2;
    if(input[mid] == key) {
        return mid;
    } else if (input[mid] < key) {
        return _search_binary(input, key, mid + 1, end);
    } else {
        return _search_binary(input, key, start, mid);
    }
}



///////////////////////////////////////////////////////////////////////
///////////////////////// INVERSION COUNT /////////////////////////////
///////////////////////////////////////////////////////////////////////

int count_inversion(int *input, int size) {
    return _count_inversion(input, 0, size - 1);
}

int _count_inversion(int *input, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        int c_l = _count_inversion(input, start, mid);
        int c_r = _count_inversion(input, mid + 1, end);
        int c_m = _count_inversion_merge(input, start, mid, end);
        return c_l + c_r + c_m;
    }
    return 0;
}

int _count_inversion_merge(int *input, int p, int q, int r) {
    int count = 0;
    int size_l = q - p + 1;
	int size_r = r - q;
	int *L = malloc(sizeof(int) * (size_l));
	int *R = malloc(sizeof(int) * (size_r));
	for(int i = 0; i < size_l; i++) {
		L[i] = input[p + i];
	}
	for(int i = 0; i < size_r; i++) {
		R[i] = input[q + i + 1];
	}
	int i = 0;
	int j = 0;
    int k = p;
	for(k = p; k <= r; k++) {
        if(i >= size_l || j >= size_r) {
            break;
        }
		if(L[i] <= R[j]) {
            count += j;
            input[k] = L[i++];
		} else {
            input[k] = R[j++];
		}
	}
    if(i == size_l) {
        for (; k <= r; k++) {
            input[k] = R[j++];
        }
    }
    
    if(j == size_r) {
        for (; k <= r; k++) {
            count += j;
            input[k] = L[i++];
        }
    }
	free(L);
	free(R);
    return count;
}



///////////////////////////////////////////////////////////////////////
/////////////////////////////// MISC //////////////////////////////////
///////////////////////////////////////////////////////////////////////

int _rand_between(int lo, int hi) {
    if (lo >= hi) {
        return lo;
    }
    int delta = hi - lo;
    
    return lo + (rand() % delta);
}

