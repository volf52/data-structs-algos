#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "sorting.h"

void maxHeapify(heapD arr[], int n, int i)
{
    int largest, l, r;
    largest = i;

    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void deleteNode(Heap *heap, int idx)
{
    heap->data[idx] = heap->data[--(heap->n)];
    maxHeapify(heap->data, heap->n, 0);
}