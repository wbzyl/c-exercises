#include <stdio.h>
#include <stdlib.h>

/*  str_len: oblicz długość napisu s */
int str_len(char s[]);

int main() {
  char *str = "ala ma kota";

  printf("\tstr_len(\"%s\") = %d\n", str, str_len(str));
}

int str_len(char s[]) {
  int n;

  for (n=0; *s != '\0'; s++)
    n++;
  return n;
}
