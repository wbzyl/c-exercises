#### {% title "C Pointers" %}

<blockquote>
  {%= image_tag "/images/john-long.jpg", :alt => "[John W. Long]" %}
  <p>Programmers have almost made code simplicity an art form while
  designers are known for spending vast amounts of time doing very
  tedious and repetitive work to get the effect that they want.</p>
  <p class="author">— John W. Long</p>
</blockquote>

* [Binky Pointer Fun Video](http://www.youtube.com/watch?v=5VnDaHBi8dM)


1\. Wskaźniki i adresy:

* deklarowanie zmiennych wskaźnikowych
* operator adresu `&`
* operator wyłuskania (adresowania pośredniego, odwołania pośredniego) `*`
* wskaźnik `NULL`
* operator rozmiaru `sizeof`

2\. Wskaźniki i argumenty funkcji:

* przekazywanie argumentów przez wartość i przez adres:
* funkcja {%= link_to "swap.c", "/pointers/swap.c" %}

3\. Wskaźniki i tablice:

    :::c
    int a[10];
    int *pa;
    pa = &a[0];

Teraz `pa==a` oraz `a[0]==*pa`, `a[1]==*(pa+1)`, `a[2]==*(pa+2)`, itd.

Przykład: {%= link_to "obliczanie długości napisu", "/pointers/str_len.c" %}.

Jeśli argumentem funkcji jest nazwa tablicy, to funkcja otrzymuje
położenie początkowego elementu tej tablicy. Wewnątrz funkcji
argumentowi takiemu odpowiada zmienna lokalna będąca wskaźnikiem na
początek tej tablicy.

Uwaga: następujące definicje parametrów funkcji są równoważne:

    :::c
    char s[]
    char *s

Dlatego obie deklaracje

    :::c
    int str_len(char s[])
    int str_len(char *s)

też równoważne. Zwykle używamy `char *s`,
ponieważ taka definicja wyraźnie sugeruje,
że parametr jest wskaźnikiem.

4\. Arytmetyka na adresach:
{%= link_to "obliczanie długości napisu raz jeszcze", "/pointers/str_len2.c" %}.

5\. Wskaźniki znakowe i funkcje. Jaka jest różnica między definicjami:

    :::c
    char t[] = "XXX"
    char *p = "XXX"

(tablica i wskaźnik na stałą napisową).

Przykłady funkcji działających na wskaźnikach:
{%= link_to "pfun.c", "/pointers/pfun.c" %}.

6\. Przydzielanie i zwalnianie pamięci dynamicznej:

    :::c
    typ void *
    malloc
    calloc
    realloc
    free

7\. Przeczytać stronę manuala dotyczącą funkcji `qsort`.
Wskaźniki do funkcji, tablice wskaźników i wskaźniki do wskaźników.

Tworzenie i rozumienie skomplikowanych deklaracji.
Korzystamy z programu *cdecl*:

    :::c
    explain char (*(*x())[])()
    declare x as function returning pointer to array
      of pointer to function returning char

Linki: [cdecl](http://www.cdecl.org/),
{%= link_to "source code", "/doc/cdecl-blocks-2.5.tar.gz" %}.

8\. Sortowanie wierszy tekstu podanych na wejściu:

* {%= link_to "doubles_sort.c", "/pointers/doubles_sort.c" %} – sortowanie liczb
* {%= link_to "sort.c", "/pointers/sort.c" %} – sortowanie napisów
* {%= link_to "psort.c", "/pointers/psort.c" %} – sortowanie wskaźników do napisów

9\. Tablice wielowymiarowe:

    :::c
    char tname[][15] = { "błędny miesiąc","styczeń", ... };
    char *pname[] = { "błędny miesiąc","styczeń", ... };

Przykład,
{%= link_to "podaj dzień roku na podstawie miesiąca i dnia i na odwrót", "/pointers/cdate.c" %}.

10\. Tablice dynamiczne.

ANSI 89:

    :::c
    int n = atoi(argv[1]);

    double *dt;
    dt = malloc(n*sizeof(double));
    if (dt == NULL)
      fprintf(stderr, "error: Zabrakło pamięci");

    dt[2]=2.71; dt[3]=3.14;
    free(dt);

ANSI 99 (sprawdzić!):

    :::C
    int n = atoi(argv[1]);

    double dt[n];

    dt[2]=2.71; dt[3]=3.14;
    free(dt);
