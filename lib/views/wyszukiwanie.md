#### {% title "Wyszukiwanie" %}

1\. Wyszukać liczbę największą w podanej tablicy liczb.

2\. Wyszukać liczbę największą i najmniejszą w podanej tablicy liczb.

Potrzebne tablice:

* 10 liczb losowych z przedziału [0, 1000)   – do testowania
* 10000 liczb losowych z przedziału [0, 1000) – na zawody

Liczby zapisujemy do pliku. Program powinien najpierw wczytać liczby
z pliku do tablicy, a następnie wyszukać największą liczbę
(zad. 1), największą i najmniejsą liczbę (zad. 2).
Mierzymy tylko czas wyszukiwania.

A to przykładowy program do generowania takich tablic:

    :::c
    #include <stdio.h>
    #include <stdlib.h>  /* tutaj jest zdefiniowane RAND_MAX */

    int RandomInteger(int low, int high);

    int main(int argc, char *argv[]) {
      int i, n, low, high;

      n = atoi(argv[1]);
      low = atoi(argv[2]);
      high = atoi(argv[3]);

      for(i = 0; i < n; i++) {
        printf("%d\n", RandomInteger(low, high));
      }

      return 0;
    }

    int RandomInteger(int low, int high) {
      int k;
      double d;

      d = (double) rand() / ((double) RAND_MAX + 1);
      k = (int) (d * (high - low + 1));
      return (low + k);
    }



## Jak zmierzyć czas wykonania fragmentu kodu

Należy skorzystać z poniższego kodu, wstawiając między
START/STOP odpowiedni fragment kodu:

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


## Jakieś pomysły na zadania…

1\. Wypisz wszystkie imiona kobiet o podanym prefiksie.

    imiona zaczynające się od: MA

    MAriola
    MAłgorzata
    MArysia
    ...

W sieci można znaleźć plik z listą imion dla kobiet.
W rozwiązaniu skorzystać z takiego pliku.

2\. **Piszemy „po chińsku”**. W chińskim tekście słowa
nie są w żaden sposób oddzielone od siebie, na przykład
takie zdanie:

    jeśli krowie dasz kakao nie wydoisz czekolady

chińczyk zapisze tak:

    jeślikrowiedaszkakaoniewydoiszczekolady

Może się nam to wydawać dziwne. Ale tak nie jest
ponieważ średnia długość słowa w języku chińskim to ok. 2,4 znaki.
Wyobraźmy sobie jaka to rozzrzutność białych znaków.

Oczywiście, przy tak krótkich słowach, nie mielibyśmy
problemu z podzaiałem tekstu na słowa.

Podziału „chińskiego tekstu” na słowa znany jest jako
*word tokenization (segmentation)*.

Najprostszy algorytm (który sprawnie działa na prawdziwym
chiński tekście) nazywa się
*Maximum Matching Word Segmentation Algorithm*:

Dana jest lista słów (słownik) i napis.

1. ustawiamy wskaźnik na początek napisu
2. w słowniku wyszukujemy najdłuższe słowo,
   którego początek wskazuje wskaźnik
3. przesuwamy wskaźnik ponad znalezionym słowem
4. wracamy do 2.

Napisać program realizujący ten algorytm dla powyższego zdania i listy
słów (na początek, bez polskich literek):

    :::c
    char *dict[] = {"czekolady", "dasz", "jesli", "kakao", "krowie", "nie", "wydoisz"};

Przyjmujemy, że słowa są porządku alfabetycznym.
Tak jak to jest w słownikach.
