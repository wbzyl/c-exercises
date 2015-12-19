#### {% title "Elementarz 3" %}

1\. W poniższym programie, który kopiując
wejście na wyjście zastępuje każdy znak tabulacji przez
\t oraz każdy znak \ przez dwa takie znaki, zostały
przestawione wiersze. Uporzadkuj je, tak aby powstał
działający program.</p>

    :::c
    #include <stdio.h>
    while ((c=getchar())!=EOF)
    }
    printf("\\t");
    else if (c=='\\')
    printf("\\\\");
    if (c=='\t')
    else
    int c;
    putchar(c);
    int main() {
    return 0;

2\. Napisz program, wypisujący w postaci tabelki pierwiastki
z pierwszych 20 liczb naturalnych.

Uwaga: Jeśli korzystamy z funkcji z biblioteki
matematycznej języka C, to na początku programu piszemy
`#include <math.h>`, a program kompilujemy
z dodatkową opcją *-lm*. Zazwyczaj opcje wpisujemy
w pliku *Makefile*:

    CFLAGS = -Wall -std=c11
    LDLIBS = -lm

3\. Trójkąt pitagorejski to trójkąt prostokątny,
w którym długość każdego boku jest liczbą całkowitą.
Napisz program wypisujący wszystkie trójkąty pitagorejskie,
których obwód nie przekracza 1000.

4\. Napisz program tworzący histogram częstości
występowania różnych znaków podanych na *stdin*.
Uwaga: łatwiej rysuje się histogram z wykresami
poziomymi; pionowa orientacja jest bardziej wymagająca.

Wynik działania programu (wersja pozioma)
na tekście tego akapitu może wyglądać tak:

    znak    liczba znaków
    -----------------------
    \n       6   ******
    a        4   ****
    c       10   **********
    e        3   ***
    h        5   *****
    y       10   **********
    z        2   **
    ...    ...   ...
