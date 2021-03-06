#### {% title "Zadania Extra", false %}

# Rocco

<blockquote>
{%= image_tag "/images/edsger_wybe_dijkstra.jpg", :alt => "[Edsger Dijkstra]" %}
<p>
  If debugging is the process of removing software bugs,
  then programming must be the process of putting them in.
</p>
<p class="author">— Edsger Dijkstra</p>
</blockquote>

Na Sigmie zainstalowałem program *rocco*.
Można go użyć do wygenerowania strony html
z kodem programu i dokumentacją.
Dokumentację piszemy w notacji markdown, dla przykładu:

    :::c
    // w *stdio.h* zadeklarowano funkcję *puts*
    #include <stdio.h>

    //### Program „hello world”

    // każdy program w C zawiera funkcję main
    int main (int argc, char *argv[]) {
      puts("hello world");
      return 0;
    }

    // i to by było tyle

Program ten po wpisaniu do pliku *hello.c* zamieniamy na
*hello.html* wykonując polecenie:

    rocco -lc -c// hello.c

**Lektura obowiązkowa** –
[Library (computing)](http://en.wikipedia.org/wiki/Library_%28computing%29),
[Anatomy of Linux dynamic libraries](http://www.ibm.com/developerworks/linux/library/l-dynamic-libraries/).


# Zadania extra-dodatkowe

<blockquote>
<p><b>Kroić słonia</b> Należy nauczyć się dzielić wielkie zadania na małe
  kroczki i odczuwać przyjemność z małych zwycięstw na krótkich odcinkach,
  bez czekania na wielką nagrodę.
</p>
<p class="author">[z metody pracy z perfekcjonistami]</p>
</blockquote>


**Czas**.
Napisz zestaw funkcji do obróbki „czasu” zawierających informację o
godzinie, minucie, sekundzie w obrębie jednej doby. Informacje te
zapamiętaj w strukturze:

    :::c
    struct czas {
      int godzina;
      int minuta;
      int sekunda;
    };

Korzystając z napisanych funkcji, napisz program:

* do określanie odstępu czasowego pomiędzy dwoma czasami,
  czyli ile jest godzin, minut i sekund,
  na przykład pomiędzy 10:15 a 15:10
* wyliczający jaka cyfra pojawia się najczęściej w ciągu
  dnia na wyświetlaczu zegarka elektronicznego z sekundnikiem
* wypisujący ile jest pojawień się poszczególnych cyfr


## Biblioteka funkcji do obróbki tabel

* Mateusz Pikora
* Wojtek Przebieracz

Biblioteka funkcji do obróbki tabel zawierających zarówno tekst jak
i liczby:
[tabele.h](http://sigma.ug.edu.pl/~mpikora/projekt/tabele.h)

Programy:

* prosty organizer z funkcjami:
  - dodawania nowych rekordów w postaci krótkiej wiadomości
  - przypisanie rekordowi daty, czasu i priorytetu
  - edytowanie i usuwanie rekordów
  - usuwanie nieaktualnych rekordów
  - zapisywanie/odczytywanie rekordów do/z pliku
  - filtrowanie wyświetlania rekordów (wszystkie, z określonego dnia, o
    określonym priorytecie itp.)

* **brak drugiego programu**


## Szyfrowanie

- Michał Mroczkowski
- Maciek Stanik

Biblioteka funkcji do szyfrowania, deszyfrowania szyfrem cezara, szyfrem
liniowym, zamiany tekstu na ascii i na odwrót oraz zliczania częstości
liter w podanym tekście:
[szyfrowanie.h](http://sigma.ug.edu.pl/~mmroczkowski/szyfrowanie.h)

Programy:

- Program do szyfrowania szyfrem cezara wraz z odszyfrowaniem
- Program do szyfrowania szyfrem liniowym wraz z odszyfrowaniem przez sam
  program (bez podawania czegokolwiek przez użytkownika


## Xstdio

* Maciej Jażdżewski
* Kamil Karwowski

Biblioteka funkcji do wczytywania, zapisywania i edycji danych z pliku
zewnetrznego:
[txt.h](http://sigma.ug.edu.pl/~mjazdzewski/projekt/txt.h)

Programy:

* Baza danych warsztatu samochodowego umożliwiająca dodawanie,
  usuwanie oraz wyświetlanie rekordów. Baza będzie zawierać informacje
  o klientach, ich pojazdach oraz uwagi pracowników zapisane w
  odrębnym pliku.
* Program będzie zapisywał datę uruchomienia
  programu w odrębnym pliku, a następnie obliczał czas od ostatniego
  uruchomienia.


## [Szachownica Polibiusza](http://pl.wikipedia.org/wiki/Szachownica_Polibiusza)

* Michał Piaskowski
* Adam Łukaszewicz

Biblioteka funkcji do szyfrowania i rozszyfrowywania
przy pomocą Szachownicy Polibiusza
oraz zamiany tekstu na kod ASCII i na odwrót:
[szyfr.h](http://sigma.ug.edu.pl/~alukaszewicz2/projekt/szyfr.h)

Programy:

* Program do szyfrowania i rozszyfrowywania przy pomocy Szachownicy Polibiusza
* Program do zamiany tekstu na kod ASCII i na odwróŧ.


## Funkcja liniowa

* Tomasz Januszewski
* Krzysztof Kaczmarczyk
* Paweł Maciejewski

Biblioteka będzie zawierać funkcje służące do wyznaczania własności
funkcji liniowej:
[linia.h](http://github.com/pmaciejewski/Linear/blob/master/linear.h)

Programy:

* rysowanie wykresu: program będzie rysował na terminalu
wykres funkcji liniowej o zadanych, całkowitych współczynnikach
* wypisanie własności: program wypisuje własności funkcji
liniowej podanej przez użytkownika, znajduje punkty przecięcia
wykresów


## ETBD — Edytor Tekstowej Bazy Danych

* Georges Liadis
* Jakub Letniowski

Biblioteka do tworzenia i obróbki prostej bazy danych powstałej na
plikach tekstowych:
[ksiazka.h](http://sigma.ug.edu.pl/~gliadis/jp/projekt/ksiazka.h)

Programy:

* Prosta książka telefoniczna. Funkcjonalność:
  dodawanie nowych rekordów w postaci plików
  z imieniem nazwiskiem i nr telefonu,
  edytowanie i usuwanie plików,
  zapisywanie i wyświetlanie zawartości plików,
  możliwość przeszukiwania plików,
  nadawanie unikalnego numeru każdemu plikowi.
* Program testujący funkcje biblioteczne.


## Miny

* Zbigniew Kisły
* Dorian Dobkowski

[mines.h](http://sigma.inf.ug.edu.pl/~zkisly/3.0/mines.h)
