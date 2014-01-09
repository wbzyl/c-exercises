#include "point.h"
#include <stdlib.h>

struct pointCDT {
  int x;
  int y;
};

pointADT new_point(int x, int y) {
  pointADT p = malloc(sizeof(struct pointCDT));
  p->x = x;
  p->y = y;
  return p;
}

void set_point(pointADT p, int x, int y) {
  p->x=x;
  p->y=y;
}

int get_x(pointADT p) {
  return p->x;
}

int get_y(pointADT p) {
  return p->y;
}
