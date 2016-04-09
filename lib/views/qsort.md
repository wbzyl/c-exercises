#### {% title "Funkcja qsort" %}

1\. Sortowanie tablicy liczb rzeczywistych. Liczby do posortowania
wczytywane są z pliku zawierającego po jednej liczbie w wierszu.
Posortowane liczby są zapisywane do pliku. Nazwy plików podajemy w linii poleceń:

    nsort unsorted.txt sorted.txt

Pliki z liczbami może zawierać co najwyżej `NMAX = 100` liczb.

Przykładowy kod:

    :::c
    #include <stdio.h>
    #include <stdlib.h>

    #define NMAX 100

    void read_numbers(char *filename, double *array, int *n);
    void write_numbers(char *filename, double *array, int n);

    int double_cmp(const void *a, const void *b);

    int main(int argc, char *argv[]) {
      int total;
      double numbers[NMAX];

      read_numbers(argv[1], numbers, &total);
      qsort(numbers, total, sizeof(double), double_cmp);
      write_numbers(argv[2], numbers, total);
    }

    int double_cmp(const void *a, const void *b) {
      double result;
      result = *(double *)a - *(double *)b;
      if (result<0)
        return -1;
      else if (result>0)
        return 1;
      else
        return 0;
    }

Kod funkcji pomocniczych:

    :::c
    void read_numbers(char *filename, double *array, int *n) {
      FILE *fin;
      char buffer[50];
      int total = 0;

      if ((fin = fopen(filename, "r")) == NULL) {
        printf("Nie mogę otworzyć pliku do czytania '%s'\n", filename);
        exit(1);
      }

      while (fgets(buffer, 50, fin)) {
        if (sscanf(buffer, "%lf", &array[total]) == 1) {
          total++;
        } else {
          printf("'%s' not a double variable\n", buffer);
        }
      }
      *n = total;
    }

    void write_numbers(char *filename, double *array, int n) {
      FILE *fout;
      if ((fout = fopen(filename, "w")) == NULL) {
        printf("Nie mogę otworzyć pliku do zapisu '%s'\n", filename);
        exit(2);
      }
      for (int i = 0; i < n; i++) {
        fprintf(fout, "%lf\n", array[i]);
      }
    }

2\. Sortowanie tablicy wskaźników do napisów.

    :::c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAXLINES 100
    #define MAXLEN 80

    void read_lines(char *filename, char *array[], int *n);
    void write_lines(char *filename, char *array[], int n);

    int lines_cmp(const void *a, const void *b) {
      return strcmp(*(char **)a, *(char **)b);
    }

    int main(int argc, char *argv[]) {
      char *text[MAXLINES];
      int total;

      read_lines(argv[1], text, &total);
      qsort(text, total, sizeof(char *), lines_cmp);
      write_lines(argv[2], text, total);
    }

Funkcje pomocnicze:

    :::c
    void read_lines(char *filename, char *array[], int *n) {
      FILE *fin;
      char buffer[MAXLEN];
      int total = 0;

      if ((fin = fopen(filename, "r")) == NULL) {
        printf("Nie mogę otworzyć pliku do czytania '%s'.\n", filename);
        exit(1);
      }

      while (fgets(buffer, MAXLEN, fin) != NULL) {
        if (total >= MAXLINES) {
          fprintf(stderr,"Za dużo linii do posortowania.\n");
          break;
        }
        array[total] = malloc(MAXLEN);
        strcpy(array[total], buffer);
        total++;
      }
      *n = total;
    }

    void write_lines(char *filename, char *array[], int n) {
      FILE *fout;

      if ((fout = fopen(filename, "w")) == NULL) {
        printf("Nie mogę otworzyć pliku do zapisu '%s'\n", filename);
        exit(2);
      }

      for (int i = 0; i < n; i++)
        fprintf(fout, "%s", array[i]);
    }
