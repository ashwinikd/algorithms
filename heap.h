//
//  heap.h
//  algo
//
//  Created by Ashwini Dhekane on 22/05/14.
//  Copyright (c) 2014 ___ASHWINIKD___. All rights reserved.
//

#ifndef algo_heap_h
#define algo_heap_h

typedef struct {
    int *keys;
    int size;
} IntegerHeap;

void heap_build_max_heap(IntegerHeap *heap, int *source, int size);
void heap_build_min_heap(IntegerHeap *heap, int *source, int size);
int heap_get_parent(IntegerHeap *heap, int index);
int heap_get_left(IntegerHeap *heap, int index);
int heap_get_right(IntegerHeap *heap, int index);
void _heap_max_heapify(IntegerHeap *heap, int index);
void _heap_min_heapify(IntegerHeap *heap, int index);
void heap_sort_asc(int *array, int size);
void heap_sort_desc(int *array, int size);
void _heap_print_heap(IntegerHeap *heap);
int heap_maximum(IntegerHeap *heap);
int heap_extract_max(IntegerHeap *heap);
void heap_increase_key(IntegerHeap *heap, int i, int key);
void heap_max_heap_insert(IntegerHeap *heap, int key);
void heap_max_heap_delete(IntegerHeap *heap, int i);
int heap_minimum(IntegerHeap *heap);
int heap_extract_min(IntegerHeap *heap);
void heap_decrease_key(IntegerHeap *heap, int i, int key);
void heap_min_heap_insert(IntegerHeap *heap, int key);
void heap_min_heap_delete(IntegerHeap *heap, int i);

#endif
