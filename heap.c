//
//  heap.c
//  algo
//
//  Created by Ashwini Dhekane on 22/05/14.
//  Copyright (c) 2014 ___ASHWINIKD___. All rights reserved.
//

#include <stdio.h>
#include "heap.h"
#include <limits.h>

void heap_build_max_heap(IntegerHeap *heap, int *source, int size) {
    heap->size = size;
    heap->keys = source;
    for (int i = size / 2; i >= 0; i--) {
        _heap_max_heapify(heap, i);
    }
}

void heap_build_min_heap(IntegerHeap *heap, int *source, int size) {
    heap->size = size;
    heap->keys = source;
    for (int i = size / 2; i >= 0; i--) {
        _heap_min_heapify(heap, i);
    }
}

int heap_get_parent(IntegerHeap *heap, int index) {
    return index >> 1;
}

int heap_get_left(IntegerHeap *heap, int index) {
    return (index << 1) + 1;
}

int heap_get_right(IntegerHeap * heap, int index) {
    return (index << 1) + 2;
}

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

void _heap_print_heap(IntegerHeap *heap) {
    for (int i = 0; i < heap->size / 2; i++) {
        printf("node: %d %d, right: %d %d, left: %d %d, parent: %d %d\n",
               i, heap->keys[i],
               heap_get_right(heap, i), heap->keys[heap_get_right(heap, i)],
               heap_get_left(heap, i), heap->keys[heap_get_left(heap, i)],
               heap_get_parent(heap, i), heap->keys[heap_get_parent(heap, i)]);
    }
}

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

int heap_maximum(IntegerHeap *heap) {
    return heap->keys[0];
}

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

void heap_increase_key(IntegerHeap *heap, int i, int key) {
    if(key < heap->keys[i]) {
        return;
    }
    if (i >= heap->size) {
        return;
    }
    
    heap->keys[i] = key;
    
    int j = i;
    while (heap->keys[j] > heap->keys[heap_get_parent(heap, j)]) {
        int p = heap_get_parent(heap, j);
        int tmp = heap->keys[j];
        heap->keys[j] = heap->keys[p];
        heap->keys[p] = tmp;
        j = p;
    }
}

void heap_max_heap_insert(IntegerHeap *heap, int key) {
    heap->size++;
    heap->keys[heap->size - 1] = INT_MIN;
    heap_increase_key(heap, heap->size - 1, key);
}

int heap_minimum(IntegerHeap *heap) {
    return heap->keys[0];
}

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

void heap_decrease_key(IntegerHeap *heap, int i, int key) {
    if(key > heap->keys[i]) {
        return;
    }
    if (i >= heap->size) {
        return;
    }
    
    heap->keys[i] = key;
    
    int j = i;
    while (heap->keys[j] < heap->keys[heap_get_parent(heap, j)]) {
        int p = heap_get_parent(heap, j);
        int tmp = heap->keys[j];
        heap->keys[j] = heap->keys[p];
        heap->keys[p] = tmp;
        j = p;
    }
}

void heap_in_heap_insert(IntegerHeap *heap, int key) {
    heap->size++;
    heap->keys[heap->size - 1] = INT_MAX;
    heap_decrease_key(heap, heap->size - 1, key);
}








