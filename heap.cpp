#include <cstdint>
#include <iostream>
#include "heap.h"

min_heap::min_heap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Inserts a new key 'data'
void min_heap::insert_key(int data) {
    if (heap_size == capacity) {
        std::cout << "Overflow could not insert key\n";
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = data;
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

void min_heap::decrease_key(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

// Method to remove minimum element from min heap
int min_heap::extract_min() {
    if (heap_size <= 0) {
        return INT32_MAX;
    }
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    min_heapify(0);
  
    return root;
}

void min_heap::delete_key(int data) {
    decrease_key(data, INT32_MIN);
    extract_min();
}

void min_heap::min_heapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        min_heapify(smallest);
    }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Inserting a key - min_heap::insert_key(int data);
// Deleting a key - min_heap::delete_key(int data);
// Extracting min = min_heap::extract_min();
