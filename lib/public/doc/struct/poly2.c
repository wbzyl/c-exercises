/*
 * Obliczanie pierwiastków równania pierwszego stopnia
 * struktury, typedef
 * przekazywanie argumentów przez referencje
 */

#include <stdio.h>
#include <stdlib.h> /* exit, EXIT_SUCCESS */
#include "genlib.h"
#include "simpio.h"

struct poly1
{
  double a, b; /* współczynniki */
  double x;    /* pierwiastek */
};

typedef struct poly1 poly1T;

void GetCoefficients(poly1T *);
void Solve(poly1T *);
void Display(poly1T);

int main() {
  poly1T polynomial;
  GetCoefficients(&polynomial);
  Solve(&polynomial);
  Display(polynomial);
  return EXIT_SUCCESS;
}

void GetCoefficients(poly1T *p) {
  printf("Ten program oblicza pierwiastek równania a*x=b\n");
  printf("Podaj a: ");
  p->a = GetReal();
  printf("Podaj b: ");
  p->b = GetReal();
  if (p->a==0) Error("wspólczynnik `a' powinien być różny od 0");
}
void Solve(poly1T *p) {
  p->x=p->b/p->a;
}
void Display(poly1T p) {
  printf("Rozwiązaniem równania %g*x=%g jest x=%g\n",p.a,p.b,p.x);
}
