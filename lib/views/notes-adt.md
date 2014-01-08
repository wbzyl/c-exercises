#### {% title "Struktury i Abstrakcyjne Typy Danych" %}

<blockquote>
  {%= image_tag "/images/you-only-live-once.jpg", :alt => "[The Strokes]" %}
  <p>Oh no<br>
    29 different attributes<br>
    And only seven that you like, uh oh<br>
    20 ways to see the world, oh oh<br>
    Or 20 ways to start a fight</p>
  <p class="author">— The Strokes, “You Only Live Once”</p>
</blockquote>

Linki:

* [Abstract Data Type](http://en.wikipedia.org/wiki/Abstract_data_structure)
* [GLib](http://pl.wikipedia.org/wiki/GLib) [API](https://developer.gnome.org/glib/unstable/)
  - [Hash Tables](https://developer.gnome.org/glib/unstable/glib-Hash-Tables.html) –
  associations between keys and values so that given a key the value can be found quickly
* [GSL](http://www.gnu.org/software/gsl/) – GNU Scientific Library
* David R. Hanson,
  [C Interfaces and Implementations](https://sites.google.com/site/cinterfacesimplementations/)


## Struktury

Jak definiujemy struktury?

    :::c
    struct point { /* tutaj `point' to tzw. etykietka struktury */
      int x;
      int y;
    };             /* ważny średnik */

    struct point maxpt = { 8, 16 };
    struct point minpt;
    minpt.x=0;  minpt.y=2;

Zagnieżdżone struktury:

    :::c
    struct rect {
      struct point ll;
      struct point ur;
    }

    struct rect screen;
    screen.ll.x = 16;

Czasami warto skorzystać z *typedef*



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

Wikipedia: Abstrakcyjne Type Danych.
Zob. tamże definicję stosu (ang. Abstract Data Type; w skrócie ADT)
Abstrakcyjne Typy Danych służą do oddzielenia interfejsu od implementacji
(ang. *information hiding*).
To oddzielenie osiągamy w C korzystając z nieprzezroczystych struktur danych
(ang. opaque data structures). W pliku nagłówkowym (.h) wpisujemy:

    typedef struct structCDT *structADT;

albo tak

    struct structCDT;

 w pliku implementującym ATD (.c) wpisujemy:

    struct structCDT {
      .. definicje pól struktury ..
    }

Dlaczego powyższe definicje pozwalają oddzielić interfejs od implementacji?
Jak to „oddzielenie” działa?



Przykład: {%= link_to "obliczanie długości napisu", "/pointers/str_len.c" %}.
