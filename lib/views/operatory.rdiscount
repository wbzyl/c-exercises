#### {% title "Laboratorium 4" %}

# Operatory

1\. Użyj pętli *while* do przeliczania czasu w minutach
na godziny i minuty. Utwórz stałą symboliczną dla liczby
60 przy pomocy *#define* lub *const*.

2\. Napisz program, który prosi o podanie liczby dni, a następnie
zamienia je na tygodnie i dni. Dla przykładu, program powinien
zamienić 16 dni na:

    16 dni to 2 tygodnie i 2 dni.

W programie wykorzystaj pętlę *while*, aby użytkownik
użytkownik mógł wielokrotnie wpisywać liczbę dni.
Koniec programu powinien nastąpić po wprowadzeniu liczby 0
lub liczby ujemnej.

3\. Napisz program, który prosi użytkownika o podanie
dwóch liczb całkowitych, a następnie sumuje wszystkie
liczby całkowite pomiędzy podanymi liczbami (włącznie)
i wypisuje wynik. Dla przykładu po podaniu liczb 2 i 6
program powinien wypisywać:

    Suma kolejnych liczb całkowitych od 2 do 6 wynosi 20.

4\. Zmodyfikuj powyższy program tak, aby obliczał
sumę kwadratów liczb całkowitych z podanego zakresu.

5\. Napisać funkcję *scisnij(s1,s2)* która z tekstu w argumencie
*s1* usuwa każdy znak występujący w **tekście** argumentu *s2*.
Kod funkcji wpisz wpliku *scisnij.c*.

Do przetestowania implementacji skorzystaj z poniższego kodu.
Kod ten wklej do pliku *main.c*:

    :::c
    int main() {
      char src[] = "abrakadabra";
      char dst[] = "ad";
      scisnij(src, dst);
      printf("%s\n", src);
      return 0;
    }

Program kompiluj tak:

    cc -Wall main.c scisnij.c -o zadanie1

Uwaga: kod w pliku *main.c* nie jet kompletny. 
Należy go uzupełnić tak aby kompilacja przebiegła bez błędów.

Wskazówka: funkcja *usun* robi **prawie** to co ma robić funkcja
*scisnij*. Oto jej kod:

    :::c
    /* usun: usuń wszystkie znaki c z s */
    void usun(char s[], int c) {
      int i, j;
      for(i=j=0; s[i]!='\0'; i++)
        if (s[i]!=c)
          s[j++]=s[i];
      s[j]='\0';
    }
