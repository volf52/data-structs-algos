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

  // print_array(arr, n);
  // quicksort(arr, 0, n - 1);
  // print_array(arr, n);

  patSearch(pat, str);
  printf("============\n");
  optimPatSearch(pat, str);

  return 0;
}
