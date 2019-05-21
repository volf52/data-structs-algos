#ifndef HEAP_H
#define HEAP_H

#define HEAPSIZE 64

typedef int heapD;

typedef struct
{
    heapD data[HEAPSIZE];
    int n;
} Heap;

void maxHeapify(heapD *, int, int);
void deleteNode(Heap *, int);

#endif