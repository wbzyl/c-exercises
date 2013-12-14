#include <stdio.h>

/*  str_len2: oblicz długość napisu s */
int str_len(char *s);

int main() {
  char *str = "ala ma kota";

  printf("\tstr_len(\"%s\") = %d\n", str, str_len(str));
}

int str_len(char *s) {
  char *p = s;  /* to samo co: char *p; p = s; */

  while (*p != '\0')
    p++;
  return p-s;
}
