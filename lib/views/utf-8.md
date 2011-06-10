#### {% title "ASCII v. UTF-8" %}

Poniższe programy kompilujemy tak:

    cc -std=c99 -Wall FILENAME

Polecenia *locales* używamy do sprawdzenia zainstalowanych
w systemie locales, na przykład:

    locale -a | egrep -i pl
      csb_PL
      csb_PL.utf8
      pl_PL
      pl_PL.iso88592
      pl_PL.utf8

W programach korzystajacych z „wide charactters” nie używamy
jednocześnie funkcji *char* i *wchar*, na przykład
*printf* i *wprintf*.

0\. Przeczytać strony manuala *wchar.h* oraz *wctype.h*.

1\. Poniższy program zamienia małe litery na duże. Uruchomić go.

    :::c
    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>

    #include <locale.h>

    #include <wchar.h>
    #include <wctype.h>

    void set_locale(void) {
      char *lc_type_name;
      if (!(lc_type_name = setlocale(LC_CTYPE, ""))) {
        fwprintf(stderr, L"Can't set the specified locale!");
        fwprintf(stderr, L"Check LANG, LC_CTYPE, LC_ALL.\n");
        exit(1);
      }
      fwprintf(stderr, L"Convert stdin to uppercase\n\u00AE 2011-2011 Włodek Bzyl\n");
      fwprintf(stderr, L"Current locale LC_CTYPE: %s\n\n", lc_type_name);
    }

    int main(int argc, char *argv[]) {
      wint_t c;

      set_locale();

      while ((c = getwchar()) != WEOF)
        putwchar(towupper(c));

      return EXIT_SUCCESS;
    }

2\. Poniższy program przepisuje literki z napisu na *stdout*. Uruchomić go.

    :::c
    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <errno.h>

    #include <locale.h>

    #include <wchar.h>
    #include <wctype.h>

    int main()
    {
      wchar_t *wcs = L"żyźny żywił\n";
      int      i;

      setlocale(LC_CTYPE, "");

      for (i = 0; wcs[i] != L'\0'; i++) {
        errno = 0;
        if (WEOF == putwchar(wcs[i])) {
          wprintf(L"Unable to putwchar() the wide character.\n");
          if (EILSEQ == errno)
            wprintf(L"An invalid wide character was encountered.\n");
          exit(EXIT_FAILURE);
        }
      }
      return 0;
    }


## Drabinki słów

Poniższe pliki zawierają słowa pięcioliterowe, po jednym w wierszu:

* {%= link_to "words.dat", "/doc/words.txt" %} - 5757 słów angielskich
* {%= link_to "plwords.dat", "/doc/plwords.txt" %} – 5308 słów polskich w kodowaniu UTF-8

Ze słów możemy utworzyć graf nieskierowany w którym wierzchołkami są
słowa pięcioliterowe; dwa słowa są połączone krawędzią, gdy różnią się
dokładnie jedną literą.

W wypadku angielskich słówek graf ma 5757 wierzchołków i 14135
krawędzi.  Oznacza to średnio 4.9 krawędzi (2\*14135/5757) na jeden
wierzchołek grafu.  Jeśli słowami byłyby losowe napisy pięcioliterowe,
wtedy taki graf miałby średnio 174,3 krawędzi. Oznacza to 0.06
krawędzi na jeden wierzchołek. Dlatego angielskie słowa łączą się
często w nieoczekiwany sposób – powstają drabinki słów
(ang. *word links*, *doublets*, *word ladders*).

(Wszystkie informacje za D. E. Knuth, *The Stanford GraphBase*,
str. 3 + programy przykładowe [SGB](http://www-cs-faculty.stanford.edu/~uno/sgb.html).)

3\. Napisać program zliczający ile krawędzi ma graf polskich
słówek?  Zliczaniem krawędzi powinna zająć się funkcja *plwords*,
którą należy samemu zaimplementować. Czy polskie słowa, podobnie do
angielskich, też łączą się w nieoczekiwany sposób?

4\. Zmierzyć czas wykonania funkcji *plwords*.
Skorzystać z gotowych makr z rozdziału *Wyszukiwanie*.



<!--

10\. Napisz program, który pyta o Twoje imię, a następnie o nazwisko,
po czym, wypisuje je w układzie: nazwisko, imię.

11\. Napisz program, który pyta o Twoje imię, a następnie:

* wypisuje je w polu o szerokości 20 znaków, przy prawym brzegu pola
* wypisuje je w polu o szerokości 20 znaków, przy lewym brzegu pola
* wypisuje je w polu o dwa znaki dłuższym niż imię

-->
