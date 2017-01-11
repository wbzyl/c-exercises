#### {% title "Struktury" %}


W rozdziale 6.2 podręcznika K&R zaprezentowano kilka funkcji
manipulujących punktami i prostokątami.

Punkt:

    :::c
    struct point {
      int x;
      int y;
    };

Prostokąt:

    :::c
    struct rect {
      struct point ll;  /* lower left */
      struct point ur;  /* upper right */
    };

Funkcja, *makepoint*, z podanych współrzędnych
tworzy strukturę *point*:

    :::c
    struct point makepoint(int x, int y) {
      struct point tmp;
      tmp.x = x;
      tmp.y = y;
      return tmp;
    }

Funkcja *ptinrect* sprawdza, czy punkt leży
wewnątrz prostokąta:

    :::c
    /* ptinrect: zwróć 1 jeśli p należy do r, 0 jeśli nie należy */
    int ptinrect(struct point p, struct rect r) {
      return p.x >= r.ll.x && p.x < r.ur.x
          && p.y >= r.ll.y && p.y < r.ur.y;
    }

Powyżej przyjmujemy konwencję, że prostokąt zawiera swoje
krawędzie lewą i dolną, a nie zawiera pozostałych.

Do każdej z funkcji przedstawionych poniżej napisać program
sprawdzający poprawność implementacji.

1\. Napisać funkcję *rectinrect* sprawdzającą, czy prostokąt jest
zawarty wewnątrz prostokąta:

    :::c
    /* rectinrect: zwróć 1 jeśli r1 jest zawarty w r2, 0
       — w przeciwnym przypadku */
    int rectinrect(struct rect r1, struct rect r);

2\. Napisać funkcję *disjointrect* sprawdzającą, czy prostokąty
są rozłączne:

    :::c
    /* disjointrect: zwróć 1 jeśli r1 jest rozłączny z r2,
       0 — w przeciwnym przypadku */
    int disjointrect(struct rect r1, struct rect r2);

3\. Napisać funkcję *ptinrectangles* sprawdzającą, czy
punkt należy do jednego z prostokątów przekazanych w argumentach:

    :::c
    /* ptinrectangles: zwróć 1 jeśli p należy do jednego z prostokątów r1...,
       0 — w przeciwnym przypadku */
    int ptinrectangles(struct point p, struct rect r1, ...);

Wskazówka: skorzystać z przykładu ze strony manuala do
[stdarg.h](http://www.freebsd.org/cgi/man.cgi?query=stdarg&apropos=0&sektion=0&manpath=FreeBSD+8.1-RELEASE&format=html) —
listy zmiennych argumentów.
Do testowania przykładu można użyć takiej funkcji głównej:

    :::c
    int main() {
      foo("s", "napis");
      foo("d", 1234);
      foo("sdc", "napis", 1234, 'x');

      return 0;
    }

4\. Napisać program obliczający pole figury składającej się
z prostokątów:

    :::c
    /* area: zwróć pole figury składającej się z prostokątów r1... */
    int area(struct rect r1, ...);

Na początek napisz uproszczoną wersję:

    :::c
    /* area: zwróć pole figury składającej się z prostokątów r1 i r2 */
    int area(struct rect r1, struct rect r2);


## Lepsze struktury w ISO C99

Trzy nowe rzeczy w składni C: _compound literals_, _variable-length macros_,
and _designated initializers_.

Przykład z _designated initializers_:

    :::c
    person_struct p = {
      .name = "Joe",
      .age = 22,
      .weight_kg = 75,
      .education_years = 20
    };

Przykład z _compound literal_:

    :::c
    #include <math.h> // NAN
    #include <stdio.h>

    double sum(double in[]){
      double out = 0;

      for (int i = 0; !isnan(in[i]); i++)
        out += in[i];
      return out;
    }

    int main() {
      // use intermediate variable
      double list[] = {1.1, 2.2, 3.3, NAN};
      printf("sum: %g\n", sum(list));

      // use a compound literal to create an array; do not use intermediate variable
      printf("sum: %g\n", sum((double[]){1.1, 2.2, 3.3, NAN}));
    }


## Nowe zadania

5\. Napisać program, który dla podanych dwóch prostokątów wylicza
najmniejszy prostokąt je zawierający:

    :::c
    /* minspan: zwróć najmniejszy prostokąt zawierający r1 i r2 */
    struct rect minspan(struct rect r1, struct rect r2);

Dla przykładu, poniższe wywołania powinny zwrócić:

    :::c
    struct rect r1 = { {0, 0}, {2, 2} };
    struct rect r2 = { {1, 1}, {3, 3} };
    struct rect rr;
    rr = minspan(r1, r2);  //=> rr == { {0, 0}, {3, 3} }

Szablon programu testującego:

    :::c
    #include <stdio.h>
    struct point {
      int x;
      int y;
    };
    struct rect {
      struct point ll;  /* lower left */
      struct point ur;  /* upper right */
    };
    struct rect minspan(struct rect r1, struct rect r2) {
      return r1; /* wkleić kod obliczający minspan */
    };
    /* dodać kilka testów */
    int main (int argc, char *argv[]) {
      struct rect r1 = { {0, 0}, {2, 2} };
      struct rect r2 = { {1, 1}, {3, 3} };
      struct rect rr;
      rr = minspan(r1, r2);
      printf("rr = ll[%d,%d], ul[%d,%d]\n", rr.ll.x, rr.ll.y, rr.ur.x, rr.ur.y);

      return 0;
    }
