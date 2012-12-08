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
Na co wskazuje `++ref`?

2\. Jaka jest wartość `*wsk` oraz `*(wsk+2)` w każdym przypadku:

(a)
    :::c
    int *wsk;
    int tab[2][2] = {12, 14, 16};
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

5\. Napisz program, używajacy wskaźników do nadania wartości 0
każdemu elementowi tablicy `int tab[10]`.
Przetestuj ją w prostym programie.

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
        {10, 20, 10, 30, 10, 15, 50, 60, 25,  5, 80, 30},  // 2008
        {10, 20,  5, 35, 15, 15, 60, 60, 25, 10, 80, 35},  // 2009
        {10,  8, 15, 30, 10, 15, 70, 70, 45,  5, 85, 40},  // 2010
        { 5, 20, 15, 35, 15, 15, 50, 65, 45, 20, 90, 30}   // 2011
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
