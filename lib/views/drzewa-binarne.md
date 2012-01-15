#### {% title "Drzewa binarne" %}

**Problem:** Napisz program zliczający liczbę wystąpień wszystkich słów
tekstu czytanego ze standardowego wejścia. Po zliczeniu liczby wystąpień
słów, program powinien je wypisać w porządku alfabetycznym.

**Jakieś własne propozycje rozwiązań?**

Poniższe rozwiązanie pochodzi z książki K&R, rozdział 6.
Jest ono przykładem programu sterowanego strukturą danych.

Rozwiązanie to działa o ile tekst nie zawiera polskich znaków
diakrytycznych, tj. znaków „ąĄćĆęĘłŁńŃóÓśŚźŹżŻ”.

W poniższym rozwiązaniu strukturą danych będzie drzewo binarne.

    :::c
    struct tnode {
      char *word;
      int count;
      struct tnode *left;
      struct tnode *right;
    };

Funkcja główna:

    :::c
    #define MAXWORD 100

    struct tnode *addtree(struct tnode *, char *);
    void treeprint(struct tnode *);
    int getword(char *, int);

    /* zliczanie wystąpień słów */
    int main() {
      struct tnode *root; /* korzeń drzewa */
      char word[MAXWORD];

      root = NULL; /* zaczynamy od pustego drzewa */
      while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
          root = addtree(root, word);
        }
      }
      treeprint(root);

      return 0;
    }

Funkcje pomocnicze:

    :::c
    /* addtree: dodaj węzeł dla w; szukaj słowa w w p lub poniżej p */
    struct tnode *addtree(struct tnode *p, char *w) {
      int cond;

      if (p == NULL) {
        p = malloc(sizeof(struct tnode));
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
      } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
      } else if (cond < 0) {
        p->left = addtree(p->left, w);
      } else {
        p->right = addtree(p->right, w);
      }
      return p;
    }

    /* treeprint: wypisz uporządkowane drzewo */
    void treeprint(struct tnode *p) {
      if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
      }
    }

    /* getword: weź następne słowo ze standardowego wejścia */
    int getword(char *word, int lim) {
      int c;
      char *w = word;

      while (isspace(c = getc(stdin)))
        ;
      if (c != EOF) {
        *w++ = c;
      }
      if (!isalpha(c)) {
        *w = '\0';
        return c;
      }
      for ( ; --lim > 0; w++) {
        if (!isalnum(*w = getc(stdin))) {
          ungetc(*w, stdin);
          break;
        }
      }
      *w = '\0';
      return word[0];
    }

1\. Połącz powyższe kawałki kodu i dodaj brakujące pliki nagłówkowe,
tak aby powstał działający program.

2\. Napisz program, który czyta tekst programu w C i wypisuje
w porządku alfabetycznym wszystkie grupy nazw zmiennych o identycznych
pierwszych sześciu znakach i różniących się którymkolwiek z dalszych
znaków. Nie bierz pod uwagę słów występujących w stałych napisowych
i w komentarzach. Niech liczba 6 będzie parametrem, który można
zmienić w wierszu wywołania programu. *(K&R, 6.2)*

3\. Napisz program tworzący skorowidz, tj. wypisujący listę
wszystkich słów dokumentu i dla każdego słow listę numerów wierszy,
w których to słowo wystąpiło. Ze skorowidza usuń słowa-ozdobniki
w rodzaju „ten”, „lub” itp. *(K&R, 6.3)*

4\. Napisz program, który zlicza różne słowa podane na standardowym
wejściu i wypisuje je uporządkowane według malejącej krotności
ich wystąpień. Każde słowo poprzedź jego krotnością. *(K&R, 6.4)*

Na koniec polecam lekturę dokumentacji+kodu programu
{%= link_to "Zliczanie słów", "/doc/fw.pdf" %}.
