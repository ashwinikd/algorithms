#include "sort.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void sort_insertion(int *input, int size) {
	if(size < 2) {
		return;
	}

	for(int i = 1; i < size; i++) {
		int key = input[i];
		int j = i -1;
		for(j = i - 1; j >= 0 && input[j] > key; j--) {
			input[j + 1] = input[j];
		}
		input[j + 1] = key;
	}
}

void sort_merge(int *input, int size) {
	_merge_sort(input, 0, size - 1);
}

int search_binary(int *input, int key, int size) {
    if(size == 0) {
        return -1;
    }
    return _search_binary(input, key, 0, size - 1);
}

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

int count_inversion(int *input, int size) {
    return _count_inversion(input, 0, size - 1);
}

void sort_quick(int *input, int size) {
    _sort_quick(input, 0, size - 1);
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

void _merge_sort(int *input, int start, int end) {
	if(start < end) {
		int mid = (start + end) / 2;
		_merge_sort(input, start, mid);
		_merge_sort(input, mid + 1, end);
		_merge(input, start, mid, end);
	}
}

void _merge(int *input, int p, int q, int r) {
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
            input[k] = L[i++];
        }
    }
	free(L);
	free(R);
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

void _sort_quick(int *input, int p, int r) {
    if (p < r) {
        int q = _sort_quick_partition_rand(input, p, r);
        _sort_quick(input, p, q - 1);
        _sort_quick(input, q + 1, r);
    }
}

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

int _rand_between(int lo, int hi) {
    if (lo >= hi) {
        return lo;
    }
    int delta = hi - lo;
    
    return lo + (rand() % delta);
}

