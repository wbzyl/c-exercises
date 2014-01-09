#include <stdio.h>
#include <stdlib.h>  /* atof, exit */
#include <math.h>    /* funkcje trygonometryczne */
#include <string.h>  /* strcmp */

/* Łącznik między nazwą funkcji a nią samą. */
struct table_entry {
  char *nazwa;
  double (*funkcja)(double);  /* wkaźnik do funkcji zwracającej double */
};

typedef struct table_entry lacznik_t;

void pomoc(lacznik_t *tp) {
  printf("\nUżycie: %s FUNKCJA ARGUMENT\n", "dtable");
  printf("\tgdzie ARGUMENT podajemy w radianach,\n");
  printf("\ta FUNKCJA to: ");
  for ( ; tp->nazwa; tp++) printf("%s ", tp->nazwa);
  printf("\n\n");
}

/* Tablica łącznikowa z wartownikiem */
lacznik_t dtable[] = {
  {"sin",sin}, {"cos",cos}, {"tg",tan}, {NULL,NULL}
};

char *output_format = "\t%s %g = %g\n";

int main(int argc, char *argv[]) {
  lacznik_t *tp;
  double argument, odp;

  if (argc!=3) {
    pomoc(dtable);
    exit(-1);
  }
  for (tp=dtable; tp->nazwa && strcmp(tp->nazwa,argv[1]); tp++)
    ;
  if (tp->funkcja==NULL) {
    printf("\n! Nieznana funkcja `%s'.\n", argv[1]);
    pomoc(dtable);
    exit(-1);
  }
  /* oblicz wartość funkcji dla podanego argumentu */
  argument=atof(argv[2]);
  odp=(*tp->funkcja)(argument) ;
  printf(output_format, tp->nazwa, argument, odp);

  return 0;
}
