#### {% title "Rekurencja" %}

<blockquote>
 <p>If you need comments in order to able to read my code,
   then you're just a tourist.
 </p>
 <p class="author"><a href="http://exposinggotchas.blogspot.com/2011/01/stop-being-tourist.html">Nick Marden</a></p>
</blockquote>

1\. Napisać rekurencyjną implementację funkcji
obliczającej n^k (n do potęgi k).

2\. Napisać funkcję rekurencyjną *C(n,k)* obliczającą
współczynnik Newtona *n po k*,
czyli liczbę podzbiorów *k*-elementowych zbioru
*n*-elementowego.

3\. Napisać funkcję rekurencyjną odwracającą
kolejność liter w napisie podanym na wejściu.

4\. Korzystając z twierdzenia Euklidesa,
napisać program obliczający rekurencyjnie największy wspólny
dzielnik z liczb podanych na wejściu.

5\. Napisać funkcję rekurencyjną, która wypisuje wszystkie
*n*-wyrazowe ciągi binarne.

6\. Napisać funkcję rekurencyjną, która wypisuje wszystkie podzbiory
zbioru { 1, 2, ..., n }.

7\. L-system (albo system Lindenmayer'a)
to zwięzła notacja do opisu iteracyjnej grafiki.
L-system składa się z symbolu początkowego oraz
z jednej lub kilku reguł przepisywania (produkcji).

Oto przykład:

    F               (symbol początkowy)
    F -> F+F--F+F   (reguła przepisywania)

Zaczynając od symbolu początkowego i dwukrotnie
korzystając z reguły przepisywania otrzymamy:
    F ->
    F+F--F+F ->
    F+F--F+F+F+F--F+F--F+F--F+F+F+F--F+F

<blockquote>
{%= image_tag "/images/koch2.png", :alt => "[bok platka Kocha]" %}
</blockquote>

Jeśli teraz umówimy się, że *F* oznacza polecenie: narysuj odcinek,
*+* oznacza skręć w lewo o 60°, a *-* skręć w prawo o 60°, to
otrzymamy taki rysunek

8\. Więcej przykładów L-systemów znajdziesz np.
<a href="http://mathforum.org/advanced/robertd/lsys2d.html">tutaj</a>.
Narysuj jeden z fraktali przedstawionych na tej stronie. Zaprojektuj
i narysuj własnego fraktala.

Więcej przykładów fraktali znajdziesz w książce Jeffrey’a Ventrella,
[Brainfilling Curves – a Fractal Bestiary](http://archive.org/stream/BrainfillingCurves-AFractalBestiary/BrainFilling#page/n1/mode/2up).


I jeszcze kilka przykładów w Pythonie: Al Sweigart,
[Recursion Explained with the Flood Fill Algorithm (and Zombies and Cats)](http://inventwithpython.com/blog/2011/08/11/recursion-explained-with-the-flood-fill-algorithm-and-zombies-and-cats/).
