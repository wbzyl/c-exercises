<blockquote>
  {%= image_tag "/images/hemingway-ernest.jpg", :alt => "[Ernest Hemingway]" %}
  <p>
   The best way is always to stop when you are going good and when you
   know what will happen next. If you do that every day […] you will
   never be stuck. Always stop while you are going good and don’t
   think about it or worry about it until you start to write the next
   day. That way your subconscious will work on it all the time. But
   if you think about it consciously or worry about it you will kill
   it and your brain will be tired before you start.
  </p>
</blockquote>

## Ważne informacje!

**[2011.04.11]** Dwie uwagi do zadania domowego:

(1) W repozytorium *sgb* umieściłem plik z 16650 pięcioliterowymi słowami:

    git clone git://sigma.ug.edu.pl/~wbzyl/sgb.git

W trakcie linkowania programu, należy użyć *gb_plwords.o*.

(3) Suma kontrolna dla pliku *plwords.dat* jest wyliczana
i sprawdzana w pliku *gb_io.w*.

<!--

Dopisujemy pliki *gb_plwords.w*, *plladders.w*
(kopie oryginałów, których nie ruszamy) do *Makefile*.

Zmieniamy nazwy funkcjom publicznym:

    words -> plwords
    find_word -> find_plword

W implementacji *plwords* podmieniamy plik *words.dat*
na *plwords.dat*. Teraz powinno działać:

    make tests
    make plladders

-->

## Laboratoria

1. {%= link_to "Budowanie programów w języku C", "/budowanie-programow" %}
1. {%= link_to "Podstawowe typy danych", "/podstawowe-typy-danych" %}
1. {%= link_to "ASCII v. UTF-8", "/utf-8" %}
1. {%= link_to "Elementarz 1", "/elementarz-1" %}
1. {%= link_to "Pętle", "/petle" %}
1. {%= link_to "Automaty skończone", "/automaty" %}
1. {%= link_to "Funkcje", "/funkcje" %}
1. {%= link_to "Elementarz 2", "/elementarz-2" %}
1. {%= link_to "Operatory", "/operatory" %}
1. {%= link_to "Elementarz 3", "/elementarz-3" %}
1. {%= link_to "Rekurencja", "/rekurencja" %}
1. {%= link_to "Pliki", "/pliki" %}
1. {%= link_to "Wskaźniki 1", "/wskazniki-1" %}
1. {%= link_to "Struktury", "/struktury" %}
1. {%= link_to "Trening czyni misztrza, miszcza, mistrza …", "/tcmmm" %}
1. {%= link_to "Wyszukiwanie różnych rzeczy", "/wyszukiwanie" %}


<!-- zob. też http://edu.i-lo.tarnow.pl/inf/alg/001_search/index.php -->

### Zadania ekstra & rozwiązania

* {%= link_to "Zadania extra", "/extra" %}
* {%= link_to "Odpowiedzi do niektórych zadań", "/answers" %}


## Literatura

<blockquote>
  <p>When human beings acquired language, we learned not just how to
  listen but how to speak. When we gained literacy, we learned not
  just how to read but how to write. And as we move into an
  increasingly digital reality, we must learn not just how to use
  programs but how to <b>make</b> them.</p>
  <p class="author">— Douglas Rushkoff</p>
</blockquote>

1. [FreeBSD Man Pages] [freebsd]
1. [Online IDE & Debugging Tool] [ideone]
1. [Thinking in C Beta 3](http://mindview.net/CDs/ThinkingInC)
1. Kernighan Brian W., Ritchie Dennis M.
   [Język ANSI C](http://wnt.pl/product.php?action=0&prod_id=481&hot=1)
1. Stephen Prata. [Język C. Szkoła programowania](http://helion.pl/)
1. [Learn C The Hard Way](http://learncodethehardway.org/) –
   a clear & direct guide to modern C programming


## Biblioteki C, kompilatory...

1. {%= link_to "CSLib", "/doc/cslib-wb.tar.bz2" %} — biblioteka
   początkującego programisty C.
1. [A C language family frontend for LLVM](http://clang.llvm.org/index.html) —
   fast compiles and low memory use, **expressive diagnostics**,
   GCC compatibility
1. [Introduction to programming and computer science](http://www.youtube.com/view_play_list?p=36E7A2B75028A3D6),
   [The Khan Academy](http://www.youtube.com/user/khanacademy)
1. Neal H. Walfield. [Lambdas in C](http://walfield.org/blog/2010/08/25/lambdas-in-c.html)


## Różności

1. [6.087 Practical Programming in C](http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-087-practical-programming-in-c-january-iap-2010/) – MIT Open Courseware
1. Krzysztof Diks.
   [Wstęp do programowania w języku C](http://mediawiki.ilab.pl/index.php/Wst%C4%99p_do_programowania_w_j%C4%99zyku_C)
1. David Turnbull.
   [How to Get the Most out of Programming Books](http://idebuggedababoon.com/how-to-get-the-most-out-of-programming-books/).
1. Joe Armstrong.
   [Ways to get started](http://erlang.org/pipermail/erlang-questions/2011-July/059966.html)


#### Linki

[freebsd]: http://www.freebsd.org/cgi/man.cgi "FreeBSD Man Pages: Index Page"
[ideone]: http://ideone.com/ "Online IDE & Debugging Tool"
