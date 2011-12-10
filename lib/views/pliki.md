#### {% title "Pliki" %}

0\. Uruchomić i przenalizować poniższy program:

    :::c
    #include <stdio.h>

    /* kopiowanie zawartości pliku */

    int main (int argc, char *argv[]) {
      FILE *fin;   /* uchwyt do pliku wejściowego */
      FILE *fout;  /* uchwyt do pliku wyjściowego */
      int c;

      if (argc != 3) {
        printf("Użycie: %s SOURCE DEST\n", argv[0]);
        return 3;
      }
      if ((fin = fopen(argv[1], "r")) == NULL) {
        printf("Nie mogę otworzyć pliku do czytania '%s'\n", argv[1]);
        return 1;
      }
      if ((fout = fopen(argv[2], "w")) == NULL) {
        printf("Nie mogę otworzyć pliku do zapisu '%s'\n", argv[2]);
        return 2;
      }

      printf("Kopiowanie pliku: %s -> %s\n", argv[1], argv[2]);

      while ((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
      }

      fclose(fin);
      fclose(fout);

      return 0;
    }


1\. Napisz program, zapisujący do pliku o nazwie *dane.dat*
dwie kolumny liczb:

    0.0   0.0   0.24
    0.1   0.01  0.08
    0.2   0.04  0.95
    ...   ...
    1.0   1.00  0.34

W drugiej kolumnie mają być kwadraty liczb z pierwszej kolumny,
a w trzeciej liczby losowe z przedziału 0..1.
Do generowania liczb losowych wykorzystaj funkcję *random*
z biblioteki *stdlib.h*.

Do zapisywania danych w pliku użyj funkcji *fprintf*.

Plik *dane.dat* ten mozna wykorzystać do narysowania wykresu za pomocą
programu *gnuplot*. Aby narysować wykres, uruchamiamy program
*gnuplot* i wpisujemy po znaku zachęty:

    > plot 'dane.dat' using 1:2 with lines
    > plot 'dane.dat' using 1:3 with lines
    > quit

2\. Poniższy program czyta argumenty z linii poleceń:

    :::c
    #include <stdio.h>
    #include <stdlib.h>
    int main(int argc, char *argv[]) {
      int i;
      printf("  Liczba argumentów:  %d\n", argc);
      printf("          Argumenty: ");
      for(i=0; i<argc; i++) {
        printf(" [%d => %s]", i, argv[i]);
      }
      printf("\n");
      return EXIT_SUCCESS;
    }

Korzystając z tego programu, napisz jeszcze raz program z zadania 1,
ale tym razem nazwę pliku na dane program ma czytać z linii poleceń.

3\. Wygeneruj 1000 liczb losowych za pomocą funcji *rand()* z
bibioteki *stdlib.h*. Podczas generowania ciągu liczb na bieżąco
obliczaj ich średnią, a wyniki zapisuj do pliku.

Na koniec, obejrzyj wykres uśredniania w gnuplocie.

4\. Napisz program zliczający ilości wystąpień liter w każdym z plików:

    ulysses.txt   =>  http://www.gutenberg.org/files/4300/4300.txt
    da-vinci.txt  =>  http://www.gutenberg.org/dirs/etext04/7ldv110.txt

Wyniki zapisać do pliku w postaci:

    numer_znaku liczba_wystąpień

Na koniec narysować wykres w gnuplocie.

Ciekawe będzie też porównanie liczebności znaków
w tekstach angielskich i w programach w języku C, Rubym itd.

Aby wyniki można było porównywać, należy je oczywiście znormalizować!
Oznacza to, że liczbę wystąpień każdego ze znaków należy
podzielić przez liczbę wszystkich zliczonych znaków.

Do pobrania plików wykorzystaj program *curl* lub *wget*:

    wget http://www.gutenberg.org/files/4300/4300.txt
    wget http://www.gutenberg.org/dirs/etext04/7ldv110.txt

5\. Napisz program, który wczytuje plik tekstowy w formacie:
pierwszy wiersz aktualny format danych w pliku,
drugi wiersz nowy format danych, na przykład:

    %10d %12.4f
    %d %f

W pozostałych wierszach znajdują się dane w podanym formacie,
na przykład

            16      3.1415
    ...
