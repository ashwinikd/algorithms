/**
 * @file heap.h
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 23 May 2014
 *
 * Heap declarations for Integers.
 */

#ifndef __AKD_ALGO_HEAP_H__
#define __AKD_ALGO_HEAP_H__


///////////////////////////////////////////////////////////////////////
//////////////////////////// STRUCTURES ///////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * IntegerHeap - Heap data structure which stores integers.
 * Contains array which stores the keys and the size information.
 */
typedef struct {
    int *keys;  // key store
    int size;   // size of heap
} IntegerHeap;



///////////////////////////////////////////////////////////////////////
//////////////////////// SORTING FUNCTIONS ////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * heap_sort_asc - sorts the input array in ascending order using
 * heap sort.
 */
void heap_sort_asc(int *array, int size);

/**
 * heap_sort_desc - sorts the input array in descending order using
 * heap sort.
 */
void heap_sort_desc(int *array, int size);



///////////////////////////////////////////////////////////////////////
//////////////////////// MAX HEAP FUNCTIONS ///////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * heap_build_max_heap - builds a max heap from a given array. 
 * The source array is not copied to heap's key store instead 
 * the source array itself is set as the key store. Hence any 
 * changes made to source array by user user will be visible in 
 * heap's key store. So be careful.
 */
void heap_build_max_heap(IntegerHeap *heap, int *source, int size);

/**
 * _heap_max_heapify - max heapify subroutine. This will traverse
 * the subtree rooted at index and fix any nodes which are
 * voilating the max heap property.
 */
void _heap_max_heapify(IntegerHeap *heap, int index);

/**
 * heap_maximum - returns the maximum key stored in this heap. It is
 * assumed that the heap is a max heap.
 */
int heap_maximum(IntegerHeap *heap);

/**
 * heap_extract_max - removes the maximum key from this heap and
 * returns it. It is assumed that the heap is a max heap.
 */
int heap_extract_max(IntegerHeap *heap);

/**
 * heap_increase_key - increases the key stored at a given node in
 * the heap. It is assumed that this is a max heap.
 */
void heap_increase_key(IntegerHeap *heap, int i, int key);

/**
 * heap_max_heap_insert - inserts a key into the max heap. There
 * are no error checks here heap should have enough capacity to
 * store the key.
 */
void heap_max_heap_insert(IntegerHeap *heap, int key);

/**
 * heap_max_heap_delete - deletes a node from the max heap.
 */
void heap_max_heap_delete(IntegerHeap *heap, int i);



///////////////////////////////////////////////////////////////////////
//////////////////////// MIN HEAP FUNCTIONS ///////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * heap_build_min_heap - builds a min heap from a given array. 
 * The source array is not copied to heap's key store instead 
 * the source array itself is set as the key store. Hence any 
 * changes made to source array by user user will be visible in 
 * heap's key store. So be careful.
 */
void heap_build_min_heap(IntegerHeap *heap, int *source, int size);

/**
 * _heap_min_heapify - min heapify subroutine. This will traverse
 * the subtree rooted at index and fix any nodes which are
 * voilating the min heap property.
 */
void _heap_min_heapify(IntegerHeap *heap, int index);

/**
 * heap_minimum - returns the minimum key stored in this heap. It is
 * assumed that the heap is a min heap.
 */
int heap_minimum(IntegerHeap *heap);

/**
 * heap_extract_min - removes the minmum key from this heap and
 * returns it. It is assumed that the heap is a min heap.
 */
int heap_extract_min(IntegerHeap *heap);

/**
 * heap_decrease_key - decreases the key stored at a given node in
 * the heap. It is assumed that this is a min heap.
 */
void heap_decrease_key(IntegerHeap *heap, int i, int key);

/**
 * heap_min_heap_insert - inserts a key into the min heap. There
 * are no error checks here heap should have enough capacity to
 * store the key.
 */
void heap_min_heap_insert(IntegerHeap *heap, int key);

/**
 * heap_min_heap_delete - deletes a node from the min heap.
 */
void heap_min_heap_delete(IntegerHeap *heap, int i);



///////////////////////////////////////////////////////////////////////
//////////////////////// TRAVERSE FUNCTIONS ///////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * heap_get_parent - get the index ofparent of a node in the 
 * heap. This will not check if the given node is present in the 
 * heap and will simply return the index of parent assuming that 
 * it is there.
 */
int heap_get_parent(IntegerHeap *heap, int index);

/**
 * heap_get_left - get the index of left child of a node in the 
 * heap. This will not check if the given node is present in the 
 * heap and will simply return the index of left child assuming 
 * that it is there.
 */
int heap_get_left(IntegerHeap *heap, int index);

/**
 * heap_get_right - get the index ofright child of a node in the 
 * heap. This will not check if the given node is present in the 
 * heap and will simply return the index of right child assuming 
 * that it is there.
 */
int heap_get_right(IntegerHeap *heap, int index);



///////////////////////////////////////////////////////////////////////
/////////////////////////////// MISC //////////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * _heap_pring_heap - prints the parent child relationships in this
 * heap to the console.
 */
void _heap_print_heap(IntegerHeap *heap);

#endif
