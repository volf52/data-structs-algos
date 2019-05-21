#include <stdio.h>
#include "sorting.h"
#include "adt/stack.h"
#include "strings.h"

int main()
{

  int n = 10;
  dType arr[] = {1, 8, 9, 2, 3, 0, 18, 90, 13, 11};
  char *str = "AABAACAADAABAAABAA";
  char *pat = "AABA";

  print_array(arr, n);
  bubbleSort(arr, n);
  print_array(arr, n);

  // bayerMoore(pat, str);
  // printf("============\n");
  // robinKarp(pat, str, 101);

  return 0;
}
