#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxlines 20
#define maxlen 80

char text[maxlines][maxlen];   /* marnujemy pamięć? */

int lines_cmp(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

int main() {
  int i=0, total;
  printf("Przed sortowaniem:\n");
  while (fgets(text[i++], maxlen, stdin)!=NULL) {
    if (i>=maxlines) {
      fprintf(stderr,"! Za dużo linii do sortowania.\n");
      break;
    }
    printf("%d:\t%s", i-1, text[i-1]);
  }
  total=i-1;

  qsort(text, total, sizeof(text[0]), lines_cmp);

  printf("Po sortowaniu:\n");
  for (i=0; i<total; i++)
    printf("%d:\t%s", i, text[i]);
}
