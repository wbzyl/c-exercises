#include <stdio.h>
#include <stdlib.h>

struct point {
  int x;
  int y;
};

typedef struct point_t {
  int x;
  int y;
} point_t;

typedef struct point *point_p;

int main() {
  struct point pt1;
  point_t pt2;
  point_p pt3;  /* pt3 – wskaźnik */

  /* inicjalizacja */
  pt1.x = 1; pt1.y = 2;
  pt2.x = 3; pt2.y = 4;

  pt3 = malloc(sizeof(struct point));
  /* pt3 = malloc(sizeof(*pt3)); */
  pt3->x = 5; pt3->y = 6;

  printf("pt1 = %d %d\n", pt1.x,  pt1.y);
  printf("pt2 = %d %d\n", pt2.x,  pt2.y);
  printf("pt3 = %d %d\n", pt3->x, pt3->y);

  return 0;
}

/*  2in1: deklaracja i inicjalizacja

    struct point pt1 = { 320, 200 };
    point_t pt2 = { 99, 101 };
*/
