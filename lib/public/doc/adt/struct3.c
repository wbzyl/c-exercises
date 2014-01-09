#include <stdio.h>
#include "point.h"

/* nieprzezroczyste typy danych:

typedef struct structCDT *structADT;

struct structCDT {
   .. definicje pól struktury ..
}

*/

int main() {
  pointADT pt4, pt5;

  pt4 = new_point(7, 8);
  printf("pt4 = %d %d\n", get_x(pt4), get_y(pt4));

  pt5 = new_point(9, 10);
  set_point(pt5, 11, 12);
  printf("pt5 = %d %d\n", get_x(pt5), get_y(pt5));

  return 0;
}
