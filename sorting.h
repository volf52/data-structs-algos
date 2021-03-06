#ifndef SORTING_H
#define SORTING_H

typedef int dType;

void swap(dType *, dType *);
void print_array(dType *, int);
void selectionSort(dType *, int);
void bubbleSort(dType *, int);
void insertionSort(dType *, int);
void shellsort(dType *, int);
void mergesort(dType *, int, int);
void merge(dType *, int, int, int);
void quicksort(dType *, int, int);
int partition(dType *, int, int);
void heapsort(dType *, int);
void heapify(dType *, int, int);

#endif
