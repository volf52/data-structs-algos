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
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j + 1] < arr[j])
        swap(&arr[j], &arr[j + 1]);
    }
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

void print_array(dType arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}
