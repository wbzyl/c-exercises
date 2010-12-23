#include <stdio.h>
#include <math.h>

#include <time.h>

/* high resolution time */
clock_t startclick, clicks;
#define START startclick = clock()
#define STOP(co) clicks = clock() - startclick; printf("czas wykonania %s = %ld\n", co, clicks)

int main()
{
  long int i, wynik, pierwiastek;

  /*
    printf("na moim komputerze CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);
    na moim komputerze CLOCKS_PER_SEC = 10^6
  */
 
  START;

  wynik = 0;
  for (i = 0; i < 2000000; i++) {  /* 2*10^6 */
    wynik = wynik + i ;
    pierwiastek = sqrt(wynik);
    /* 
      a tak jest dużo szybciej:
        pierwiastek = sqrt(i);
      dlaczego?
    */
  }

  STOP("pętli");

  return 0;
}
