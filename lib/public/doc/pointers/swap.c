#include <stdio.h>

void swap_bad(int a, int b);
void swap_ok(int *a, int *b);

int main() {
  int m=1, n=1001;

  printf("\tPrzed swap_bad:");
  printf("\tm=%d, n=%d\n", m, n);
  swap_bad(m,n);
  printf("\tPo swap_bad:");
  printf("\tm=%d, n=%d\n", m, n);

  printf("\tPrzed swap_ok:");
  printf("\tm=%d, n=%d\n", m, n);
  swap_ok(&m,&n);
  printf("\tPo swap_ok:");
  printf("\tm=%d, n=%d\n", m, n);
}

void swap_bad(int a, int b) {
  int temp;
  temp=a; 
  a=b; 
  b=temp;
}
void swap_ok(int *a, int *b) {
  int temp;
  temp=*a; 
  *a=*b; 
  *b=temp;
}
