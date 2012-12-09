#### {% title "Odpowiedzi do niektórych zadań" %}

<blockquote>
 <p>
   After three days without programming, life becomes meaningless.
 </p>
 <p class="author">[The Tao of Programming 2.1]</p>
</blockquote>

## Podstawowe typy danych

Zadanie 2.

    :::c
    #include <stdio.h>
    #include <ctype.h>
    int main() {
      int kod;
      printf("Podaj kod ascii: ");
      scanf("%i", &kod);
      if (isprint(kod)) {
        printf("%c\n", kod);
      } else {
        printf("znak niedrukowalny\n");
      }
      return 0;
    }

Zadanie 3.

    :::c
    #include <stdio.h>
    int main()
    {
      int ROK = 31536000;	  /* liczba sekund w roku */
      int ROK_P = 31622400;   /* liczba sekund w roku przestępnym */
      int ROK_BIEZACY = 2010;

      int w, i, leap;
      int wynik = 0;
      printf("Podaj wiek w latach: ");
      scanf("%d", &w);
      for (i = ROK_BIEZACY-1; i >= ROK_BIEZACY - w; i--) {
        leap = ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0);
        if (leap == 1)
          wynik = wynik + ROK_P;
        else
          wynik = wynik + ROK;
      }
      printf("Przeżyłeś w swoim życiu około %d sekund.\n", wynik);
      return 0;
    }

Zadanie 4.

    :::c
    #include <stdio.h>
    #include <time.h>
    #include <stdlib.h>

    int main() {
      int rok, miesiac, dzien;
      struct tm *data_urodzenia;
      time_t czas_urodzenia, czas_teraz;

      // jak zainicjalizować zmienną data_urodzenia nie korzystając z localtime?
      data_urodzenia = localtime(&czas_urodzenia);
      printf("Podaj swoja date urodzeniaodzenia w formacie rrrr-mm-dd: ");
      scanf("%d-%d-%d", &rok, &miesiac, &dzien);

      data_urodzenia->tm_mday = dzien;
      data_urodzenia->tm_mon = miesiac - 1;
      data_urodzenia->tm_year = rok - 1900;

      czas_urodzenia = mktime(data_urodzenia);
      time(&czas_teraz);
      printf("Do momentu uruchomienia tego programu przezyles:\n");
      printf("\t%.0lf sekund\n", difftime(czas_teraz, czas_urodzenia));

      return 0;
    }

<!--

// struct tm *data_urodzenia = malloc(sizeof(struct tm));

-->

<blockquote>
 <p>To know the road ahead, ask those coming back.</p>
 <p class="author">[ <a href="http://www.cs.unc.edu/~azuma/hitch4.html">Chinese proverb</a> ]</p>
</blockquote>

## Automaty skończone

Zadanie 1.

    :::c
    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
      int c, state;

      c=getchar();
      state=1;

      while (1) {
        switch (state) {

        case 1:
          switch (c) {
          case ' ': putchar(' ');
            c=getchar();
            state=2;
            break;
          case '\t': putchar(' ');
            c=getchar();
            state=3;
            break;
          case EOF:
            exit(EXIT_SUCCESS);
          default: putchar(c);
            c=getchar();
            state=1;
            break;
          }
          break;

        case 2:
          switch (c) {
          case ' ':
            c=getchar();
            state=2;
            break;
          case EOF:
            exit(EXIT_SUCCESS);
          default: putchar(c);
            c=getchar();
            state=1;
            break;
          }
          break;

        case 3:
          switch (c) {
          case '\t':
            c=getchar();
            state=3;
            break;
          case EOF:
            exit(EXIT_SUCCESS);
          default: putchar(c);
            c=getchar();
            state=1;
            break;
          }
          break;


        }
      }

      return EXIT_SUCCESS;
    }


## Pętle

Zadanie 8.

    :::c
    #include <stdio.h>
    int wzor(int x, int y);

    int main() {
      int x = 1, j = 0, i;

      while (j <= 3) {
        int tab[7] = {x, 8-x, 5-x, (x+1)*2, tab[2], tab[1], x};
        i = 0;
        while (i <= 6) {
          wzor(tab[i], i);
          i++;
        }
        printf("\n");
        x++;
        j++;
      }
      return 0;
    }

    int wzor(x, y) {
      int i = 0;

      while(i < x) {
        if (y%2 == 0)
          putchar('*');
        else
          putchar(' ');
        i++;
      }
      return 0;
    }


## Funkcje

Zadanie 3.

    :::c
    #include <stdio.h>
    #include <stdbool.h>

    bool is_perfect_number(int n) {
      int suma = 0;
      for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
          suma += i;
        }
      }
      if (suma == n) {
        return true;
      } else {
        return false;
      }
    }

    int main() {
      for (int i = 1; i < 1000000; ++i) {
        bool wynik = is_perfect_number(i);
        if (wynik)
          printf("liczba %i jest doskonala\n", i);
      }
    }

Piątą liczbą doskonałą jest 33 550 336, a szóstą
‒ 8 589 869 056. Ile czasu zajmie temu programowi
wyliczenie piątej liczby doskonałej?
Czy program ten poradzi sobie z obliczeniem
szóstej liczby doskonałej?


## Wskaźniki 2

Zadanie 1.

    :::c
    #include <stdio.h>

    void swap(int **a, int **b) {
      int *temp;
      temp = *a; *a = *b; *b = temp;
    }

    int main() {
      int t[4] = { 2, 8, 1, 3 }, *a[4];
      int i, j;

      for (i = 0; i < 4; i++)
        printf("%d ", t[i]);
      printf("\n");

      for (i = 0; i < 4; i++)
        a[i] = &t[i];

      for (i = 0; i < 4; i++)
        for (j = i + 1; j < 4; j++)
          if (*a[i] > *a[j])
            swap(&a[i], &a[j]);

      for (i = 0; i < 4; i++)
        printf("%d ", *a[i]);
      printf("\n");

      return 0;
    }


## Struktury

Zadanie 4.

    :::c
    #include <stdio.h>
    #include <stdlib.h>

    struct point {
      int x;
      int y;
    };

    struct rect {
      struct point ll;  /* lower left */
      struct point ur;  /* upper right */
    };

    /* zwróć prostokąt będący przecięciem prostokątów;
       jeśli prostokąty są rozłaczne, to zwróć „odcinek” */
    struct rect intersect(struct rect r1, struct rect r2);

    /* zwróć pole prostokąta */
    int area(struct rect r);

    int main (int argc, char *argv[]) {
      struct rect r1 = { {0, 0}, {4, 4} };
      struct rect r2 = { {1, -1}, {2, 8} };

      struct rect rr = intersect(r1, r2);
      int a = area(rr);

      printf("rr = ll[%d,%d], ul[%d,%d]\n", rr.ll.x, rr.ll.y, rr.ur.x, rr.ur.y);
      printf("area = %d\n", a);

      return 0;
    }

Funkcja pomocnicza:

    :::c
    static int int_cmp(const void *a, const void *b);

Implementacja:

    :::c
    int area(struct rect r) {
      return (r.ur.x - r.ll.x) * (r.ur.y - r.ll.y);
    }

Łatwo sprawdzić, że dla każdych dwóch przedziałów:

    [x11, x12], [x21, x22]

zachodzi:

    [x11, x12] ∩ [x21, x22] ≠ ∅  wtw  x11 ≤ x21 ≤ x12  albo  x21 ≤ x11 ≤ x22

Oznacza to, że odcinki się przecinają
wtw
lewy koniec pierwszego odcinka wpada do drugiego odcinka
albo
lewy koniec drugiego odcinka wpada do pierwszego odcinka.

Skorzystamy z tej własności odcinków w kodzie poniżej.

    :::c
    struct rect intersect(struct rect r1, struct rect r2) {
      struct rect r;

      int x[4] = { r1.ll.x, r1.ur.x, r2.ll.x, r2.ur.x };
      int y[4] = { r1.ll.y, r1.ur.y, r2.ll.y, r2.ur.y };
      qsort(x, 4, sizeof(int), int_cmp);
      qsort(y, 4, sizeof(int), int_cmp);

      if (r1.ll.x <= r2.ll.x && r2.ll.x <= r1.ur.x) {
        r.ll.x = x[1]; r.ur.x = x[2];
      } else if (r2.ll.x <= r1.ll.x && r1.ll.x <= r2.ur.x) {
        r.ll.x = x[1]; r.ur.x = x[2];
      } else {
        r.ll.x = r.ur.x = 0;  // rozłączne prostokąty
      }

      if (r1.ll.y <= r2.ll.y && r2.ll.y <= r1.ur.y) {
        r.ll.y = y[1]; r.ur.y = y[2];
      } else if (r2.ll.y <= r1.ll.y && r1.ll.y <= r2.ur.y) {
        r.ll.y = y[1]; r.ur.y = y[2];
      } else {
        r.ll.y = r.ur.y = 0;  // rozłączne prostokąty
      }

      return r;
    }

    static int int_cmp(const void *a, const void *b) {
      int result;
      result = *(int *)a - *(int *)b;
      if (result < 0)
        return -1;
      else if (result > 0)
        return 1;
      else
        return 0;
    }

Wykonać refaktoryzację kodu:

* dodać funkcję intersect dla odcinków
* uprościć *if*-y w funkcji *intersect*
* korzystając z kodu powyżej zaimplementować funkcję *disjointrect*
