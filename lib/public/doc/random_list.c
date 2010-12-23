#include <stdio.h>
#include <stdlib.h>  /* tutaj jest zdefiniowane RAND_MAX */

/* Uwagi:

   - program po uruchomieniu:

      random_list LICZBA, MIN, MAX

     generuje listę długości N składającą się z liczb przypadkowych 
     z zakresu [MIN, MAX] 

   - program nie sprawdza, czy został poprawnie wywołany

   - the rand() function returns a pseudo-random integer in the range [0, RAND_MAX]. 

*/

/* return a random integer in the range low to high, inclusive. */
int RandomInteger(int low, int high);

int main(int argc, char *argv[])
{
  int i, n, low, high;

  n = atoi(argv[1]);
  low = atoi(argv[2]);
  high = atoi(argv[3]);

  for(i = 0; i < n; i++) {
    printf("%d\n", RandomInteger(low, high));
  }

  return 0;
}

int RandomInteger(int low, int high)
{
    int k;
    double d;

    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low + 1));
    return (low + k);
}
