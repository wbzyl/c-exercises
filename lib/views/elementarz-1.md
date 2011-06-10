#### {% title "Elementarz 1" %}

1\. Napisz program obliczający wartość każdego z poniższych wyrażeń:

<ol class="lower-alpha">
<li>n1=5+3*8/2-3</li>
<li>n2=2%2+2*2-2/2</li>
<li>n3=2*4*(5+9/2)</li>
</ol>

2\. W miejsce kropek „`...`” wpisz kod, tak aby powstały działające
programy.

    :::c
    /* Program ten wypisuje liczby z tablicy tabela[]
       w odwrotnej kolejności: 12, 6, 4, 2, 1 */
    #include <stdio.h>
    int main() {
       int tabela[] = {1, 2, 4, 6, 12};
       for (...)
          ...
       return 0;
    }

3\. Napisać program, który robi to co poprzedni program, ale tym razem
zamiast pętli „for” należy użyć pętli „while”.

4\. Napisać program obliczający silnię z podanej, niezbyt dużej,
   liczby naturalnej.

5\. Student G. Apa dostał od kolegi na kartce kod
programu zliczającego znaki odstępu, tabulacji i nowego wiersza.
Niestety jego młodszy brat pociął kartkę na kawałki
zawierające po jednym wierszu kodu,
a następnie kawałki te wymieszał.
Uporządkuj te kawałki, tak aby powstał działający program.

    :::c
    /* zlicz znaki odstępu, tabulacji
    {
    }
    #include &lt;stdio.h>
    i nowego wiersza */
    else if (c == '\t')
    int main ()
    int c;
    nt = 0;
    nl = 0;
    while ((c=getchar()) != EOF)
    ++nl;
    if (c == ' ')
    ++nb;
    nb = 0;
    return 0;
    ++nt;
    int nb, nt, nl;
    printf("%d %d %d\n", nb, nt, nl);
    else if (c == '\n')
