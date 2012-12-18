#### {% title "Wskaźniki 1" %}

1\. Co wypisuje następujący program:

    :::c
    #include <stdio.h>

    int main () {
      int ref[] = {8, 4, 0, 2};
      int *wsk;
      int indeks;

      for (indeks = 0, wsk = ref; indeks < 4; indeks++, wsk++)
        printf("%d %d\n", ref[indeks], *wsk);
    }

Ile elementów ma tablica `ref`?
Czego adresem jest `ref`? a `ref+1`?

2\. Jaka jest wartość `*wsk` oraz `*(wsk+2)` w każdym przypadku:

(a)
    :::c
    int *wsk;
    int tab[2][2] = {{12, 14}, {16};
    wsk = tab[0];

(b)
    :::c
    int *wsk;
    int tab[2][2] = { {12}, {14, 16} };
    wsk = tab[0];

Napisz prosty program, który sprawdzi twoje odpowiedzi.

Ile wynosi `**wsk` oraz `**(wsk+1)` w każdym przypadku?

3\. Uzupełnij kod funkcji *podnies_do_kwadratu* oraz *wczytaj_liczbe*
tak aby powstał działający program:

    :::c
    void podnies_do_kwadratu(int *n) {

    }

    void wczytaj_liczbe(int *n) {
      printf("Wpisz liczbę naturalną: ");

    }

    int main() {
       int liczba;
       wczytaj_liczbe(&liczba);
       podnies_do_kwadratu(&liczba);
       printf("Kwadrtat wczytanej liczby to %d\n", liczba);
       return 0;
    }

4\. Napisz funkcję, która zwraca różnicę między największym i najmniejszym
elementem tablicy podanej jako argument funkcji.
Przetestuj ją w prostym programie.

5\. Napisz program, używajacy wskaźników do nadania wartości 128
każdemu elementowi tablicy `int tab[512]`.
Przetestuj ją w prostym programie. Jak inaczej można zainicjalizować
tablicę w C?


6\. Napisz funkcję, której argumentem jest napis i która zwraca
wskaźnik do pierwszego znaku nie będącego znakiem odstępu
(*nonwhite character*) w podanym napisie.
Przetestuj ją w prostym programie.

7\. Napisać program znajdujący sumy roczne, roczne średnie oraz
średnie miesięczne dla danych o opadach z kilku lat.
W tym celu uzupełnij poniższy kod:

    :::c
    #include <stdio.h>

    #define MIESIACE 12
    #define LATA 4

    int main () {
      int deszcz[LATA][MIESIACE] = { // dane o opadach są wyrażone w mm
        {29, 34, 34, 39, 34, 47, 35, 27, 29, 28, 32, 38},  // 2008
        {24, 25, 30, 36, 29, 34, 30, 27, 27, 23, 28, 27},  // 2009
        {31, 36, 41, 42, 35, 43, 35, 30, 34, 31, 33, 37},  // 2010
        {39, 32, 50, 53, 39, 38, 50, 43, 36, 35, 54, 40}   // 2011
      };

      ...

    }

tak aby po skompilowaniu wypisywał wyniki w takim formacie:

    Opady w kolejnych latach (w mm)
      457
      800
      300
      252

    Roczna średnia wynosi 545 mm.

    Średnie miesięczne:
     I   II  III ... XII
    --------------------
    20   25   35 ...  45