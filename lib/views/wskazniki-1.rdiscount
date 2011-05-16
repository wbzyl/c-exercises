#### {% title "Rekurencja" %}

# Wskaźniki

<blockquote><a href="http://www.ariel.com.au/jokes/The_Evolution_of_a_Programmer.html">The
  Evolution of a Programmer</a>
</blockquote>

1\. Uzupełnij kod funkcji *podnies_do_kwadratu* oraz *wczytaj_liczbe*
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


2\. Napisz program, który korzysta z dwóch tablic. Jedna to tablica
4 liczb całkowitych, druga to tablica wskaźników na liczby całkowite.

Przeprowadź proste przeszukiwanie tablicy liczb w celu odszukania
najmniejszej i zapamiętaj jej wskaźnik w tablicy wskaźników pod indeksem 0.
Potem poszukaj kolejnej i ponownie zapamiętaj jej wskaźnik na
następnym miejscu w tablicy wskaźników. W ten sposób utwórz całą
tablicę wskaźników. Zwróć uwagę na to, że takim sposobem możesz
posortować nieduże tablice liczb całkowitych bez konieczności
zmiany w nich kolejności danych. Wypisz na ekran zawartość obu
tablic.

**Wskazówka:** Skorzystaj z programu *cdecl*;
uruchom program *cdecl* i wpisz:

    declare a as array 4 of pointer to int

Przeczytaj stronę manuala programu *cdecl*.

3\. Zadeklaruj w programie tablicę
dziesięcioelementową wskaźników do tablic pięcioelementowych
wskaźników na liczby rzeczywiste. Następnie wczytaj do tej tablicy
kilka liczb. Wypisz na wyjście te liczby.

**Wskazówka:** Skorzystaj z programu *cdecl*.

4\. Napisz program *xtail* wypisujący
*n* ostatnich wierszy tekstu podanego na wejściu.

Domyślną wartością *n* jest 10, ale wartość tę można
zmienić za pomocą opcjonalnego argumentu wywołania programu.
Na przykład, każde z poleceń:

    xtail  -n 5
    xtail  --lines 5

spowoduje wypisanie 5 ostatnich wierszy.

Program powinien działać sensownie niezależnie od tego,
jak nierozsądne są dane wejściowe lub wartość *n*.
Przygotować zestaw testów pokazujących
„rozsądne zachowanie” programu.

Uwaga 1: Wiersze powinny być gromadzone w tablicy
wskaźników do char.

Uwaga 2: Do programu
dodać dodatkowe opcje: `author', `help' i `version';
do obsługi opcji wykorzystać funkcję
*getopt_long* albo skorzystać z biblioteki *popt*
(przykłady użycia można znaleźć na stronach manuala).
