#include <stdio.h>
#include <stdlib.h>  /* malloc */
#include <ctype.h>

int main(int argc, char *argv[]) {
  unsigned int n;

  if (argc < 2 || (n = atoi(argv[1])) < 4)
    n = 4;

#ifdef C99
  double td[n];
#else
  double *td;

  td = malloc(n*sizeof(double));
  if (td == NULL)
    fprintf(stderr, "error: Zabrakło pamięci");
#endif

  td[2] = 2.71;
  td[3] = 3.14;

  printf("dt[2] = %.2f; dt[3] = %.2f;\n", td[2], td[3]);

  return 0;
}
