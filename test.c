#include <stdio.h>
#include "sorting.h"
#include "adt/stack.h"

int main()
{

  int n = 10;
  dType arr[] = {1, 8, 9, 2, 3, 0, 18, 90, 13, 11};

  print_array(arr, n);
  mergesort(arr, 0, n - 1);
  print_array(arr, n);

  return 0;
}
