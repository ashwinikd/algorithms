/*
Functions for sorting integers.

Ashwini Kumar Dhekane<ashwini@ashwinidhekane.com>

*/

#ifndef __AKD_SORT_H__
#define __AKD_SORT_H__ 1

void sort_insertion(int *input, int size);
void sort_merge(int *input, int size);
void _merge_sort(int *input, int start, int end);
void _merge(int *input, int p, int q, int r);
int search_binary(int *input, int key, int size);
int _search_binary(int *input, int key, int start, int end);
void sort_bubble(int *input, int size);
int count_inversion(int *input, int size);
int _count_inversion(int *input, int start, int end);
int _count_inversion_merge(int *input, int p, int q, int r);

#endif
