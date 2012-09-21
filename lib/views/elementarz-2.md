#### {% title "Elementarz 2" %}

<blockquote>
  {%= image_tag "/images/algorithm.png", :alt => "[Algorithm]" %}
  <p>Remember, good code is like a good joke: It needs no explanation.</p>
  <p class="author">[old school programming wisdom]</p>
</blockquote>

1\. Poniższy – zawierający wiele błędów – program dla podanej
z klawiatury liczby *M* ma obliczyć najmniejszą liczbę *n*, taką że

    1 + 2 + 3 +...+ n >= M

Popraw wszystkie błędy w tym programie tak, aby poprawiony program
prawidłowo obliczał liczbę *n*.

    :::c
    #include <stdio.h>
    int main() {
      int M;
      suma = 0;
      i = 1;
      print("Podaj liczbe M: ");
      scanf("%f\n", %M)
      while (suma < M) {
         suma=suma+i;
         i=i+1;
      }
      n=i+1;
      printf("Szukane n to: ", n);
      return 0;
    }

Na konsoli, działanie programu, może wyglądać tak:

    Podaj liczbę M: 11
    Szukane n to: 5

Szukane *n* to 5, ponieważ:

    1 + 2 + 3 + 4 < 10
    1 + 2 + 3 + 4 + 5 >= 10


2\. Zamiast komentarzy `/* ... */` w programie poniżej wpisz kod tak,
aby powstał program, który sprawdza czy podana liczba całkowita jest
pierwsza.

    :::c
    #include <stdio.h>
    int main() {
      /* deklaracje zmiennych */
      printf("Podaj liczbe calkowita: ");
      /* wczytaj tę liczbę do zmiennej n */
      /* sprawdź czy n jest liczbą pierwszą */
      printf("Podana liczba '%d' jest %s\n",
        n, jest_pierwsza ? "pierwsza" : "złożona");
      return 0;
    }


<blockquote>
  <p>Rozmawiają dwaj profesorowie matematyki:<br>
  – Dasz mi swój nr telefonu?<br>
  – No pewnie. Trzecia cyfra jest trzykrotnością pierwszej.
  Czwarta i szósta są takie same.
  Druga jest większa o jeden od piątej.
  Suma sześciu cyfr to 23, a iloczyn 2160.<br>
  – W porządku, zapisałem – 256 343.<br>
  – Zgadza się. Nie zapomnisz?<br>
  – Skądże. To kwadrat 16 i sześcian 7.</p>
  <p class="author"><a href="http://dilbert.com/strips/comic/1992-07-18/">Dilbert & Math</a></p>
</blockquote>

{%= image_tag "/images/dilbert-supercomputer-pi.png", :alt => "[Algorithm]" %}

3\. Oblicz wartość π (pi) z nieskończonej sumy

    π = 4 - 4/3 + 4/5 - 4/7 + 4/9 - 4/11 + ...

Wypisz w postaci tabelki przybliżoną wartość π
przez sumę 10, 100, 1000 i 1_000_000 wyrazów tego szeregu.

Ile wyrazów musisz wysumować, zanim po raz pierwszy otrzymasz
kolejne przybliżenia  π: 3.14, 3.141, 3.1415 ?
Wyniki wypisz w postaci tabelki.


4\. Zamiast komentarza `/** ... */` i kropek `...` poniżej wpisz kod,
tak aby powstał program zliczający znaki odstępu, tabulacji i nowego
wiersza tekstu wczytanego z *stdin*.

    :::c
    #include <stdio.h>
    int main() {
       /** deklaracje zmiennych lokalnych */
       nb = 0;  /* liczba znaków odstępu */
       nt = 0;  /* liczba znaków tabulacji */
       nl = 0;  /* liczba znaków nowego wiersza */
       while ((c=getchar()) != EOF) {
          /** zliczaj białe znaki */
       }
       printf("liczba znaków odstępu = %d, \
          tabulacji = %d, nowego wiersza = %d\n", ... );
       return 0;
    }
