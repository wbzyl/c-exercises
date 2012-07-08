/* Wykonać refaktoryzację kodu: dodać funkcję intersect dla odcinków */

#include <stdio.h>
#include <stdlib.h>

static int int_cmp(const void *a, const void *b);

struct point {
  int x;
  int y;
};

struct rect {
  struct point ll;  /* lower left */
  struct point ur;  /* upper right */
};

struct rect intersect(struct rect r1, struct rect r2);

int area(struct rect r);

int main (int argc, char *argv[]) {
  struct rect r1 = { {0, 0}, {4, 4} };
  struct rect r2 = { {1, -1}, {2, 8} };

  struct rect rr = intersect(r1, r2);
  int a = area(rr);

  printf("rr = ll[%d,%d], ul[%d,%d]\n", rr.ll.x, rr.ll.y, rr.ur.x, rr.ur.y);
  printf("area = %d\n", a);

  return 0;
}

int area(struct rect r) {
  return (r.ur.x - r.ll.x) * (r.ur.y - r.ll.y);
}

/*
   FAKT: Dane są przedziały: [x11, x12], [x21, x22]. Wtedy
         [x11, x12] ∩ [x21, x22] ≠ ∅  wtw  x11 ≤ x21 ≤ x12  albo  x21 ≤ x11 ≤ x22
*/

struct rect intersect(struct rect r1, struct rect r2) {
  struct rect r;

  int x[4] = { r1.ll.x, r1.ur.x, r2.ll.x, r2.ur.x };
  int y[4] = { r1.ll.y, r1.ur.y, r2.ll.y, r2.ur.y };

  qsort(x, 4, sizeof(int), int_cmp);
  qsort(y, 4, sizeof(int), int_cmp);

  if (r1.ll.x <= r2.ll.x && r2.ll.x <= r1.ur.x) {
    r.ll.x = x[1]; r.ur.x = x[2];
  } else if (r2.ll.x <= r1.ll.x && r1.ll.x <= r2.ur.x) {
    r.ll.x = x[1]; r.ur.x = x[2];
  } else {
    r.ll.x = r.ur.x = 0;
  }

  if (r1.ll.y <= r2.ll.y && r2.ll.y <= r1.ur.y) {
    r.ll.y = y[1]; r.ur.y = y[2];
  } else if (r2.ll.y <= r1.ll.y && r1.ll.y <= r2.ur.y) {
    r.ll.y = y[1]; r.ur.y = y[2];
  } else {
    r.ll.y = r.ur.y = 0;
  }

  return r;
}

static int int_cmp(const void *a, const void *b) {
  int result;
  result = *(int *)a - *(int *)b;
  if (result<0)
    return -1;
  else if (result > 0)
    return 1;
  else
    return 0;
}
