#### {% title "Struktury i Abstrakcyjne Typy Danych" %}

<blockquote>
  {%= image_tag "/images/you-only-live-once.jpg", :alt => "[The Strokes]" %}
  <p>Oh no<br>
    29 different attributes<br>
    And only seven that you like, uh oh<br>
    20 ways to see the world, oh oh<br>
    Or 20 ways to start a fight</p>
  <p class="author">The Strokes, <a href="http://www.youtube.com/watch?v=pT68FS3YbQ4">“You Only Live Once”</a></p>
</blockquote>

Linki:

* [Abstract Data Type](http://en.wikipedia.org/wiki/Abstract_data_structure)
* [GLib](http://pl.wikipedia.org/wiki/GLib) [API](https://developer.gnome.org/glib/unstable/)
  - [Hash Tables](https://developer.gnome.org/glib/unstable/glib-Hash-Tables.html) –
  associations between keys and values so that given a key the value can be found quickly
  - Tom Copeland,
  [Manage C data using the GLib collections](http://www.ibm.com/developerworks/linux/tutorials/l-glib/)

* [GSL](http://www.gnu.org/software/gsl/) – GNU Scientific Library
* David R. Hanson,
  [C Interfaces and Implementations](https://sites.google.com/site/cinterfacesimplementations/)


## Struktury

Jak definiujemy i korzystamy z struktur?

    :::c
    struct point { /* „point” to tzw. etykietka struktury */
      int x;
      int y;
    };             /* ważny średnik */

    struct point maxpt = { 8, 16 };
    struct point minpt;
    minpt.x = 0;  minpt.y = 2;

Zagnieżdżone struktury:

    :::c
    struct rect {
      struct point ll;
      struct point ur;
    }

    struct rect screen;
    screen.ll.x = 16;

Czasami definując strukturę korzystamy z *typedef*:

    :::c
    typedef struct point {
      int x;
      int y;
    } point_t;

    point_t maxpt;
    maxpt.x = 32; maxpt.y = 64;

Ale częściej definujemy **wskaźnik** na strukturę:

    :::c
    typedef struct point {
      int x;
      int y;
    } *point_t;

    point_t maxpt;
    maxpt = malloc(sizeof(struct point));
    maxpt->x = 128; maxpt->y = 256;

{%= link_to "Przykład", "/struct/struct1.c" %}
w którym użyto powyższych konstrukcji.

Czasami potrzebujemy tablic struktur. Można je zdefiniować na kilka
sposobów:

    :::c
    struct key {
      char *word;
      int count;
    } keytab[NKEYS];

    struct key {
      char *word;
      int count;
    };
    struct key keytab[NKEYS];

    typedef struct key {
      char *word;
      int count;
    } key_t;
    key_t keytab[NKEYS];

Ciekawy przykład zastosowania tablic struktur –
{%= link_to "tablica łącznikowa", "/struct/dtable.c" %}.

Struktury i funkcje – pierwiastki wielomianów:

* {%= link_to "poly1.c", "/struct/poly1.c" %}
* {%= link_to "poly2.c", "/struct/poly2.c" %}
* {%= link_to "poly3.c", "/struct/poly3.c" %}


### Better Structures in C99

Funkcje napisane w języku Python, Ruby
mogą zwracać wiele wartości, a w języku C tylko jedną.
Ale w C możemy zwrócić strukturę, która może składać się
z tylu elementów ile potrzebujemy.

Zilustrujemy to za pomocą tego {%= link_to "przykładu", "/struct/papersize.c" %}.
Kompilujemy go tak:

    :::bash
    cc -std=c99 -Wall papersize.c


<blockquote>
 {%= image_tag "/images/ants2.png", :alt => "[Ants 2]" %}
 <p>Misunderstandings can arise when an author is thinking in a
 broader context than the reader. A reader might be thinking
 tactically:<br>
 <b>How can I do a better job today?</b><br>
 while the author is thinking strategically:
 <b>How can we make a better tomorrow?</b?<br>
 The misunderstanding becomes especially acute when real progress
 requires abandoning today's world and starting over.
 </p>
 <p class="author">— B. Victor, <a href="http://worrydream.com/Links2013/">Reading Tip #3</a></p>
</blockquote>

## Abstrakcyjne Type Danych (ADT)

[Abstract Data Type](http://en.wikipedia.org/wiki/Abstract_data_structure) (w skrócie ADT).
Implementacja *stosu* jako ADT.

Abstrakcyjne Typy Danych służą do oddzielenia interfejsu od implementacji
(ang. *information hiding*).

To oddzielenie osiągamy w C korzystając z nieprzezroczystych struktur danych
(ang. *opaque data structures*).

W pliku nagłówkowym (*.h*) wpisujemy:

    :::c
    typedef struct structCDT *structADT;

albo

    :::c
    struct structCDT;

W pliku implementującym ADT (*.c*) wpisujemy:

    :::c
    struct structCDT {
      /* definicje pól */
    }

Dlaczego powyższe definicje nie powodują błędów w trakcie kompilacji?

Dlaczego pozwalają oddzielić interfejs od implementacji?
Jak to „oddzielenie” działa?

Przykład ADT – punkt na płaszczyźnie:

* {%= link_to "definicja", "/adt/point.h" %}
* {%= link_to "implementacja", "/adt/point.c" %}
* {%= link_to "przykład użycia", "/adt/struct3.c" %}

Stos (Stack) to klasyczny przykład, który implementujemy jako ADT:

* {%= link_to "interfejs", "/stack/stack.h" %}
* {%= link_to "implementacja korzystająca z tablic", "/stack/stack1.c" %}
* {%= link_to "j.w. ale bez ograniczenia na wielkość użytej tablicy", "/stack/stack.c" %}
* {%= link_to "implementacja korzystająca z listy łączonej", "/stack/stack2.c" %}
* {%= link_to "symulacja kalkulatora RPN", "/stack/rpn-simulation.c" %} –
  *Reverse Polish Notation*

(W kodzie powyżej korzystamy z CSLib.)


### Jeszcze jeden program przykładowy

Struktury odwołujące się do samych siebie – zliczanie wystąpień
wszystkich słów podanych na wejściu

    :::c
    struct tnode {         /* węzeł drzewa */
      char *word;          /* wskaźnik do tekstu słowa */
      int count;           /* licznik wystąpień */
      struct tnode *left;  /* lewy potomek */
      struct tnode *right; /* prawy potomek */
    };

Uwaga: C nie dopuszcza, aby struktura zawierała w sobie swoje
własne wcielenie. Ale struktura może zawierać wskaźnik do samej siebie.

Wersja opisowa programu zliczającego słowa *fw.pdf*
(zob. rozdział 6.5 w K&R).

Po kompilacji *fw.w*:

    :::bash
    ctangle fw.w
    cc -Wall fw.c -o fw

program *fw* uruchamiamy tak:

    :::bash
    ./fw < fw.w | sort -nr -k1 | head -n 10


## GLib & paths

Biblioteki mogą być zainastalowane w kilku miejscach. Jakich?

Aby się przekonać, gdzie została zainstalowana konkretna biblioteka
możemy skorzystać z programu *pkg-config*, np. jeśli

    :::bash
    pkg-config --libs glib gsl
    pkg-config --cflags glib gsl
    pkg-config --cflags --libs glib gsl

Tak wygląda kompletny przykład:

    :::bash
    gcc `pkg-config --cflags --libs glib` -o specific specific.c

Dwa przykłady:

* {%= link_to "hello.c", "/glib/hello.c" %}
* {%= link_to "hash.c", "/glib/hash.c" %}
