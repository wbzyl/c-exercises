#include <stdio.h>
#include <stdlib.h>

double numbers[] = { 3.14, 1.67, 2.72, 0.62 };

#define total sizeof(numbers)/sizeof(double)

int double_cmp(const void *a, const void *b) {
  double result;
  result = *(double *)a - *(double *)b;
  if (result<0)
    return -1;
  else if (result>0)
    return 1;
  else 
    return 0;
}

int main() {
  int i;

  printf("Elementy tablicy numbers[]:\n");
  for (i=0; i<total; i++)
    printf("\t%6.4f ", numbers[i]);
  printf("\n");
  printf("Elementy tablicy numbers[] po wywołaniu qsort:\n");

  qsort(numbers, total, sizeof(double), double_cmp);

  for (i=0; i<total; i++)
    printf("\t%6.4f ", numbers[i]);
  printf("\n");
}
