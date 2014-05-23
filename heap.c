/**
 * @file heap.c
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 23 May 2014
 *
 * Implementations for heap functions.
 */

#include <stdio.h>
#include "heap.h"
#include <limits.h>



///////////////////////////////////////////////////////////////////////
//////////////////////// SORTING FUNCTIONS ////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * heap_sort_asc - sorts the input array in ascending order using
 * heap sort. This will build a max heap from the input array and
 * start exchanging the root key (which is the maximum) with the
 * last key in the heap and then running max_heapify subroutine on 
 * the root.
 *
 * At the start of every iteration the array[i ... size-1] is
 * sorted in ascending order. Hence when the loop terminates at i=0
 * the input array[0 ... size-1] is sorted.
 */
void heap_sort_asc(int *array, int size) {
    IntegerHeap heap;
    heap_build_max_heap(&heap, array, size);
    for (int i = heap.size - 1; i > 0; i--) {
        int tmp = heap.keys[i];
        heap.keys[i] = heap.keys[0];
        heap.keys[0] = tmp;
        heap.size--;
        _heap_max_heapify(&heap, 0);
    }
}

/**
 * heap_sort_desc - sorts the input array in decending order using
 * heap sort. This will build a min heap from the input array and
 * start exchanging the root key (which is the minimum) with the
 * last key in the heap and then running min_heapify subroutine on
 * the root.
 *
 * At the start of every iteration the array[i ... size-1] is
 * sorted in decending order. Hence when the loop terminates at i=0
 * the input array[0 ... size-1] is sorted.
 */
void heap_sort_desc(int *array, int size) {
    IntegerHeap heap;
    heap_build_min_heap(&heap, array, size);
    for (int i = heap.size - 1; i > 0; i--) {
        int tmp = heap.keys[i];
        heap.keys[i] = heap.keys[0];
        heap.keys[0] = tmp;
        heap.size--;
        _heap_min_heapify(&heap, 0);
    }
}



///////////////////////////////////////////////////////////////////////
//////////////////////// MAX HEAP FUNCTIONS ///////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * heap_build_max_heap - builds a max heap from a given array.
 * The source array is not copied to heap's key store, instead
 * the source array itself is set as the key store. Hence any
 * changes made to source array by user user will be visible in
 * heap's key store. So be careful.
 */
void heap_build_max_heap(IntegerHeap *heap, int *source, int size) {
    heap->size = size;
    heap->keys = source;
    for (int i = size / 2; i >= 0; i--) {
        _heap_max_heapify(heap, i);
    }
}

/**
 * _heap_max_heapify - max heapify subroutine. This will traverse
 * the subtree rooted at index and fix any nodes which are
 * voilating the max heap property.
 *
 * This starts at the given node and checks if it violates the max
 * heap property by compairing it with its children. If it does
 * then the node is exchanged with the child with maximum key and
 * process is repeated on the node with new position.
 */
void _heap_max_heapify(IntegerHeap *heap, int index) {
    int i = index;
    
    while (1) {
        int largest = i;
        int l = heap_get_left(heap, i);
        int r = heap_get_right(heap, i);
        
        if (l < heap->size && heap->keys[l] > heap->keys[i]) {
            largest = l;
        }
        if (r < heap->size && heap->keys[r] > heap->keys[largest]) {
            largest = r;
        }
        if (i != largest) {
            int tmp = heap->keys[i];
            heap->keys[i] = heap->keys[largest];
            heap->keys[largest] = tmp;
            i = largest;
        } else {
            break;
        }
    }
}

/**
 * heap_maximum - returns the maximum key stored in this heap. It is
 * assumed that the heap is a max heap.
 */
int heap_maximum(IntegerHeap *heap) {
    return heap->keys[0];
}

/**
 * heap_extract_max - removes the maximum key from this heap and
 * returns it. It is assumed that the heap is a max heap.
 *
 * This exchanges the root element(which has the maximum key)
 * with the last node, decreases the heap size and calls 
 * max_heapify on the root node.
 */
int heap_extract_max(IntegerHeap *heap) {
    if (heap->size < 1) {
        return -1;
    }
    int max = heap->keys[0];
    heap->keys[0] = heap->keys[heap->size - 1];
    heap->size--;
    _heap_max_heapify(heap, 0);
    return max;
}

/**
 * heap_increase_key - increases the key stored at a given node in
 * the heap. It is assumed that this is a max heap. If the new key
 * is smaller than the current key store in the node this function
 * will return without making any change.
 *
 * If the new key is greater than the one currently stored then it
 * is set to the new value. After increment all nodes follow the
 * max heap property except may be the parent of node whose key
 * was increased. Hence we traverse the heap upwards (towards the
 * root) exchanging the node with its parent if max heap property
 * is being violated.
 */
void heap_increase_key(IntegerHeap *heap, int i, int key) {
    if(key < heap->keys[i]) {
        return;
    }
    if (i >= heap->size) {
        return;
    }
    
    heap->keys[i] = key;
    
    int j = i;
    while (heap->keys[i] > heap->keys[heap_get_parent(heap, j)]) {
        int p = heap_get_parent(heap, j);
        heap->keys[j] = heap->keys[p];
        j = p;
    }
    heap->keys[j] = heap->keys[i];
}

/**
 * heap_max_heap_insert - inserts a key into the max heap. There
 * are no error checks here heap should have enough capacity to
 * store the key.
 *
 * This increases the heap size by 1 and sets the last node to
 * INT_MIN. Then it calls the heap_increase_key on the created
 * node i.e. the last node.
 */
void heap_max_heap_insert(IntegerHeap *heap, int key) {
    heap->size++;
    heap->keys[heap->size - 1] = INT_MIN;
    heap_increase_key(heap, heap->size - 1, key);
}

/**
 * heap_max_heap_delete - deletes a node from the max heap.
 *
 * This exchanges the key at given node with the key stored in
 * last node, decreases the heap size and then calls max_heapify 
 * on the current node.
 */
void heap_max_heap_delete(IntegerHeap *heap, int i) {
    if (i >= heap->size) {
        return;
    }
    heap->keys[i] = heap->keys[heap->size - 1];
    heap->size--;
    _heap_max_heapify(heap, i);
}



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
void heap_build_min_heap(IntegerHeap *heap, int *source, int size) {
    heap->size = size;
    heap->keys = source;
    for (int i = size / 2; i >= 0; i--) {
        _heap_min_heapify(heap, i);
    }
}

/**
 * _heap_min_heapify - min heapify subroutine. This will traverse
 * the subtree rooted at index and fix any nodes which are
 * voilating the min heap property.
 *
 * This starts at the given node and checks if it violates the min
 * heap property by compairing it with its children. If it does
 * then the node is exchanged with the child with minimum key and
 * process is repeated on the new node.
 */
void _heap_min_heapify(IntegerHeap *heap, int index) {
    int i = index;
    
    while (1) {
        int smallest = i;
        int l = heap_get_left(heap, i);
        int r = heap_get_right(heap, i);
        
        if (l < heap->size && heap->keys[l] < heap->keys[i]) {
            smallest = l;
        }
        if (r < heap->size && heap->keys[r] < heap->keys[smallest]) {
            smallest = r;
        }
        if (i != smallest) {
            int tmp = heap->keys[i];
            heap->keys[i] = heap->keys[smallest];
            heap->keys[smallest] = tmp;
            i = smallest;
        } else {
            break;
        }
    }
}

/**
 * heap_minimum - returns the minimum key stored in this heap. It is
 * assumed that the heap is a min heap.
 */
int heap_minimum(IntegerHeap *heap) {
    return heap->keys[0];
}

/**
 * heap_extract_min - removes the minimum key from this heap and
 * returns it. It is assumed that the heap is a min heap.
 *
 * This exchanges the root element(which has the minimum key)
 * with the last node, decreases the heap size and calls
 * min_heapify on the root node.
 */
int heap_extract_min(IntegerHeap *heap) {
    if (heap->size < 1) {
        return -1;
    }
    int min = heap->keys[0];
    heap->keys[0] = heap->keys[heap->size - 1];
    heap->size--;
    _heap_min_heapify(heap, 0);
    return min;
}

/**
 * heap_decrease_key - decreases the key stored at a given node in
 * the heap. It is assumed that this is a min heap. If the new key
 * is greater than the current key store in the node this function
 * will return without making any change.
 *
 * If the new key is smaller than the one currently stored then it
 * is set to the new value. After decrement all nodes follow the
 * max heap property except may be the parent of node whose key
 * was decreased. Hence we traverse the heap upwards (towards the
 * root) exchanging the node with its parent if min heap property
 * is being violated.
 */
void heap_decrease_key(IntegerHeap *heap, int i, int key) {
    if(key > heap->keys[i]) {
        return;
    }
    if (i >= heap->size) {
        return;
    }
    
    heap->keys[i] = key;
    
    int j = i;
    while (heap->keys[i] < heap->keys[heap_get_parent(heap, j)]) {
        int p = heap_get_parent(heap, j);
        heap->keys[j] = heap->keys[p];
        j = p;
    }
    
    heap->keys[j] = heap->keys[i];
}

/**
 * heap_min_heap_insert - inserts a key into the min heap. There
 * are no error checks here heap should have enough capacity to
 * store the key.
 *
 * This increases the heap size by 1 and sets the last node to
 * INT_MAX. Then it calls the heap_decrease_key on the created
 * node i.e. the last node.
 */
void heap_in_heap_insert(IntegerHeap *heap, int key) {
    heap->size++;
    heap->keys[heap->size - 1] = INT_MAX;
    heap_decrease_key(heap, heap->size - 1, key);
}

/**
 * heap_min_heap_delete - deletes a node from the min heap.
 *
 * This exchanges the key at given node with the key stored in
 * last node, decreases the heap size and then calls min_heapify
 * on the current node.
 */
void heap_min_heap_delete(IntegerHeap *heap, int i) {
    if (i >= heap->size) {
        return;
    }
    heap->keys[i] = heap->keys[heap->size - 1];
    heap->size--;
    _heap_min_heapify(heap, i);
}



///////////////////////////////////////////////////////////////////////
//////////////////////// TRAVERSE FUNCTIONS ///////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * heap_get_parent - get the index ofparent of a node in the
 * heap. This will not check if the given node is present in the
 * heap and will simply return the index of parent assuming that
 * it is there.
 */
int heap_get_parent(IntegerHeap *heap, int index) {
    return index >> 1;
}

/**
 * heap_get_left - get the index of left child of a node in the
 * heap. This will not check if the given node is present in the
 * heap and will simply return the index of left child assuming
 * that it is there.
 */
int heap_get_left(IntegerHeap *heap, int index) {
    return (index << 1) + 1;
}

/**
 * heap_get_right - get the index ofright child of a node in the
 * heap. This will not check if the given node is present in the
 * heap and will simply return the index of right child assuming
 * that it is there.
 */
int heap_get_right(IntegerHeap * heap, int index) {
    return (index << 1) + 2;
}


///////////////////////////////////////////////////////////////////////
/////////////////////////////// MISC //////////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * _heap_pring_heap - prints the parent child relationships in this
 * heap to the console.
 */
void _heap_print_heap(IntegerHeap *heap) {
    for (int i = 0; i < heap->size / 2; i++) {
        printf("node: %d %d, right: %d %d, left: %d %d, parent: %d %d\n",
               i, heap->keys[i],
               heap_get_right(heap, i), heap->keys[heap_get_right(heap, i)],
               heap_get_left(heap, i), heap->keys[heap_get_left(heap, i)],
               heap_get_parent(heap, i), heap->keys[heap_get_parent(heap, i)]);
    }
}
