#### {% title "Wyszukiwanie" %}

**TODO** Dokończyć, dodać wyszukiwanie.

Cel: który program będzie najszybszy.

Przykładowe dane:

* 10 liczb losowych z przedziału [0, 1000)    LINK
* 1000 liczb losowych z przedziału [0, 1000)  LINK


[Program](LINK) do generowania takich zbiorów:

    :::c
    #include <stdio.h>
    #include <stdlib.h>  /* tutaj jest zdefiniowane RAND_MAX */
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



[Szablon programu](LINK) do mierzenia czasu wykonania fragmentu kodu:

    :::c
    #include <stdio.h>
    #include <math.h>

    #include <time.h>  /* co zawiera stała CLOCKS_PER_SEC ? */

    /* high resolution time */
    clock_t startclick, clicks;
    #define START startclick=clock()
    #define STOP(co) clicks=clock()-startclick; printf("czas wykonania %s = %ld\n",co,clicks)

    int main()
    {
      int i, wynik, pierwiastek;

      START;

      wynik = 0;
      for (i = 0; i < 2000000; i++) {  /* 2*10^6 */
        wynik = wynik + i ;
        pierwiastek = sqrt(wynik);
      }

      STOP("pętli");

      return 0;
    }


## Liczba największa i najmniejsza

1\. Liczba największa

2\. Liczba największa i najmniejsza

Programy w wersji opisowej (użyć *rocco*).


## Podpowiedzi: imiona kobiet

1\. Działanie:

    imiona ma
    mariola
    małgorzata
    marysia
    ...

Jak to ma działać?

* utworzyć w pamięci strukturę danych umożliwiającą
  takie wyszukiwanie
* użyć jej do znalezienia imion o podanym prefiksie
* …
