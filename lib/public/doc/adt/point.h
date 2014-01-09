#ifndef POINT_INCLUDED
#define POINT_INCLUDED

typedef struct pointCDT *pointADT;

pointADT new_point(int x, int y);

void set_point(pointADT p, int x, int y);
int get_x(pointADT p);
int get_y(pointADT p);

#endif
