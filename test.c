#include <stdio.h>
#include "sorting.h"

int main(){

  int n = 10;
  int arr[] = { 1, 8, 9, 2, 3, 0, 18, 90, 13, 11};

  print_array(arr, n);
  insertionSort(arr, n);
  print_array(arr, n);

  return 0;
  }
