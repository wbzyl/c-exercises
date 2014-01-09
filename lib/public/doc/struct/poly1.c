/* 
 * Obliczanie pierwiastków równania pierwszego stopnia
 * przekazywanie argumentów przez referencje
 */

#include <stdio.h>
#include <stdlib.h> /* exit, EXIT_SUCCESS */
#include "genlib.h" /* biblioteka CSLIB: GetReal */
#include "simpio.h"

void GetCoefficients(double *pa, double *pb);
void Solve(double a, double b, double *px);
void Display(double x);

int main() {
  double a, b, x;
  GetCoefficients(&a,&b);
  Solve(a,b,&x);
  Display(x);
  return EXIT_SUCCESS;
}

void GetCoefficients(double *pa, double *pb) {
  printf("Ten program oblicza pierwiastek równania a*x=b\n");
  printf("Podaj a: ");
  *pa = GetReal();
  printf("Podaj b: ");
  *pb = GetReal();
  if (*pa==0) Error("wspólczynnik `a' powinien być różny od 0");
}
void Solve(double a, double b, double *px) {
  *px=b/a;
}
void Display(double x) {
  printf("Pierwiastkiem równania jest x=%g\n",x);
}
