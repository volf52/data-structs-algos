#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

void swap(int *a, int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void selectionSort(int arr[], int n){
  int i, j, min_idx;

  for(i = 0; i < n -1; i++){
    min_idx = i;
    for(j = i+1; j < n; j++){
      if(arr[j] < arr[min_idx])
        min_idx = j;
    }
    swap(&arr[i], &arr[min_idx]);
  }

}

void bubbleSort(int arr[], int n){
  int i, j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n-i-1; j++){
      if(arr[j + 1] < arr[j])
        swap(&arr[j], &arr[j+1]);
    }
  }
}

void insertionSort(int arr[], int n){
  int i, j, key;

  for(i = 1; i < n; i++){
    key = arr[i];
    j = i;
    while(j > 0 && key < arr[j-1]){
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = key;
  }
}

void print_array(int arr[], int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d\t", arr[i]);
  }
  printf("\n");
}
