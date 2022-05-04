#ifndef HEAPWINDOW_H
#define HEAPWINDOW_H

#include <QMainWindow>

//https://www.geeksforgeeks.org/binary-heap/
class min_heap {
private:
    int* harr;// pointer to array of elements in heap.
    int capacity;    
    int heap_size;

public:
    min_heap(int capacity);
    void min_heapify(int);
    
    int parent(int i) { return (i-1)/2; }
  
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
  
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }   

    // Returns the minimum key (key at root) from min heap
    int get_min() { return harr[0]; }

    void insert_key(int data);

    void delete_key(int data);

    int extract_min();
};

namespace Ui {
class HeapWindow;
}

#endif //HEAPWINDOW_H
