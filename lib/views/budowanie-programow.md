#### {% title "Budowanie programów w języku C" %}

<blockquote>
  {%= image_tag "/images/pike-rob.jpg", :alt => "[Rob Pike]" %}
  <p>
   <b>Rob Pike</b> claims to have never written a program
   that uses cursor addressing.
  </p>
</blockquote>

1\. Dokonać kompilacji (opcja kompilatora *-c*) *biblioteka.c* oraz
*glowny.c* Jakie pliki powstaną po wykonaniu tych poleceń?

    :::c
    /* plik glowny.c */
    main() {
      printf("hello world\n");
    }

    /* plik biblioteka.c */
    /* cały plik to te dwa wiersze komentarza */

2\. Czy do kompilacji *glowny.c* konieczne jest istnienie pliku
*biblioteka.c*? Przekopiować plik *glowny.c* do osobnego katalogu i
wykonać eksperyment.

    :::c
    /* plik glowny.c */
    int main() {
      hej();
      return 0;
    }

    /* plik biblioteka.c */
    #include <stdio.h>
    void hej(void) {
      printf("hello world\n");
    }

3\. Zaobserwować komunikaty kompilatora po włączeniu opcji *-Wall*.  Do
pliku *glowny.c* dodać dyrektywę include dołączającą plik *defincje.h*.
Czy komunikaty kompilatora zmieniły się?

    :::c
    /* plik definicje.h */
    void hej(void);

4\. Dokonać konsolidacji (łączenia) plików obiektowych do programu
wykonywalnego. Jaki plik powstaje domyślnie podczas łączenia? Zmienić
nazwę pliku wykonywalnego (opcja *-o*). Czy pliki ze źródłami są
konieczne do konsolidacji? Wykonać eksperyment.

5\. Funkcja *scanf* jest bardzo podobna do
funkcji *printf* z tym, że czyta dane z *stdin*
zamiast zapisywać wyniki na *stdout*. Najprościej mówiąc, użycie
*scanf* polega na podaniu formatu wprowadzanych danych i adresu
zmiennej, pod którą chcemy je zapisać. Oto przykłady:

Wczytaj liczbę całkowitą i zapisz jej wartość do zmiennej *a*:

    :::c
    scanf("%d",&a)

Wczytaj liczbę zmiennopozycyjną i zapisz jej wartość do zmiennej *b*:

    :::c
    scanf("%f",&b)

Wczytaj dwie liczby całkowite odzielone spacją i zapisz ich wartości
do zmiennych *c* oraz *d*:

    :::c
    scanf("%d %d", &c, &d)

W miejsce `...` poniżej wpisz kod, tak aby powstały działające programy.

Pierwszy program:

    :::c
    /* Program ten wykonuje konwersję ze stopni na radiany
       według wzoru: rad = 2 * PI * deg / 360    */
    #include <stdio.h>
    #include <math.h>
    int main() {
       double deg, rad;
       printf("Podaj kat w stopniach : ");
       scanf("...", &deg);
       rad = ... ;  /* grep PI /usr/include/math.h */
       printf("%lf deg = %lf rad\n", ... , ...);
       return 0;
    }

Drugi program:

    :::c
    /* Program ten dla dwóch liczb wczytanych z klawiatury
       wypisuje, która z nich jest większa. */
    #include <stdio.h>
    int main()
    {
       int ..., ... ;

       printf("Podaj pierwsza liczbe: ");
       scanf(..., &licz1);
       printf("...");
       scanf(..., &licz2);
       if (...)
         ...
       return 0;
    }

6\. Napisz program, który wczyta liczbę rzeczywistą i
wypisze jej pierwiastek kwadratowy. W wypadku podania liczby
ujemnej, program powinien wypisać komunikat o błędzie oraz
zakończyć działanie.

7\. Napisz program, który wczyta liczbę rzeczywistą i
wypisze jej odwrotność oraz jej pierwiastek kwadratowy.
Program nie powinien obliczać odwrotności liczby 0
oraz pierwiastka z liczby ujemnej. W takiej
sytuacji zamiast obliczeń program powinien wypisać
odpowiedni komunikat.

8\. Napisz program, który prosi użytkownika
o wprowadzenie trzech liczb z klawiatury, a następnie
wypisze sumę, iloczyn, najmniejszą i największą z
wprowadzonych liczb.

Dialog na terminalu powinien wyglądać tak:

    Wprowadź trzy liczby całkowite: 1 2 3
    Suma wynosi: 6
    Iloczyn wynosi: 6
    Najmniejsza liczba to: 1
    Największa liczba to: 3

9\. Napisać program, który wypisze tabelkę wartości pierwiastka
kwadratowego. Program ma pytać o

* wartość poczatkową
* wartość końcową
* krok dla argumentu

i wypisywać tabelkę w podanym zakresie.
Liczby powinny być wypisywane z dokładnością czterech miejsc po
przecinku.
Na przykład, jeżeli podamy 1 jako
wartość poczatkową, 2 jako końcową i 0.5 jako krok,
powinismy dostać:

    1.0000  1.0000
    1.5000  1.2247
    2.0000  1.4142

## Program make

Kompilowanie programów ułatwia program *make*.
Program *make* korzysta z instrukcji wpisanych
w pliku *Makefile*.


### Program make bez Makefile

ale tylko dla programów składających się z jednego pliku.

Zaczynamy od wykonania poniższego polecenia na terminalu:

    :::bash Terminal
    export CFLAGS='-g -Wall --std=gnu99'
    export LDLIBS='-lm'

Teraz aby przetłumaczyć *hello.c* z C na *hello* wykonujemy:

    :::bash
    make hello


### Przykładowy plik Makefile

Dla programów składających się z jednego pliku, wystarczy utworzyć
plik *Makefile* o takiej zawartości:

    :::text
    CFLAGS=-g -Wall --std=gnu99
    LDLIBS=-lm

    clean:
        rm -f *.o *~

gdzie wiersz z `rm` zaczyna się od znaku **tabulacji**.

Po skopiowaniu pliku *Makefile* do katalogu z programami,
wystarczy wykonać:

    :::bash
    make hello

aby przetłumaczyć program *hello.c* do *hello*.

Z kolei polecenie:

    :::bash
    make clean

spowoduje usunięcie plików z rozszerzeniem *.o*
oraz plików tymczasowych edytorów *vi* i *emacs*.

Dokumentacja programu *make* dostępna jest online:

* [GNU make](http://www.gnu.org/software/make/manual/make.html)
  (HTML, jedna strona)
* [GNU make](http://www.gnu.org/software/make/manual/make.pdf)
  (PDF)
