#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

void swap(dType *a, dType *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(dType arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void selectionSort(dType arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void bubbleSort(dType arr[], int n)
{
    int i, j, xchg;
    i = 0;
    xchg = 1;
    while (i < n - 1 && xchg)
    {
        xchg = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                xchg = 1;
            }
        }
        i++;
    }
}

void insertionSort(dType arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i;
        while (j > 0 && key < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

void shellsort(dType arr[], int n)
{
    int h = 1, outer, inner, val;

    while (h <= n / 3)
        h = h * 3 + 1;

    while (h > 0)
    {
        for (outer = h; outer < n; outer++)
        {
            val = arr[outer];
            inner = outer;
            while ((inner > h - 1) && (arr[inner - h] >= val))
            {
                arr[inner] = arr[inner - h];
                inner = inner - h;
            }
            arr[inner] = val;
        }
        h = (h - 1) / 3;
    }
}

void mergesort(dType arr[], int l, int r)
{
    int m;

    if (l < r)
    {
        m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(dType arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    dType *L, *R;

    L = (dType *)malloc(sizeof(dType) * n1);
    R = (dType *)malloc(sizeof(dType) * n2);
    if ((L == NULL) || (R == NULL))
    {
        printf("MergeSort : Couldn't allocate memory for sub arrays\n");
        exit(-1);
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // initial index of first sub array
    j = 0; // initial index of second sub array
    k = l; // initial index of merged sub array

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void quicksort(dType arr[], int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int partition(dType arr[], int low, int high)
{
    int pivot, i, j;

    pivot = arr[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void heapsort(dType arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(dType arr[], int n, int parent)
{
    int largest, l, r;
    largest = parent;

    l = 2 * parent + 1;
    r = 2 * parent + 2;

    // if left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // if right child is larger than largest
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // if largest is not parent
    if (largest != parent)
    {
        swap(&arr[parent], &arr[largest]);
        heapify(arr, n, largest);
    }
}