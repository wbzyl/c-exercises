#### {% title "Trening czyni misztrza, miszcza, mistrza …" %}

<blockquote>
 <p>{%= image_tag "/images/matt-might-marousel.jpg", :alt => "[Matthew Might]" %}</p>
 <p>
  <a href="http://matt.might.net/articles/nine-kinds-of-students/">Classroom Fortress:<br>
    The Nine Kinds of Students</a>
 </p>
</blockquote>

<p><b>Zadanie 1.</b>
Napisać program <kbd>morse.c</kbd> kodujący
podany na wejściu tekst na kod Morsa
i dekodujący podany na wejściu kod Morsa na tekst.
Program powinien dać się uruchomić tak jak pokazano to poniżej
(k — koduj, d — dekoduj):
</p>
<pre>echo SOS   |   ./morse k
... --- ...
echo ... --- ...   |   ./morse d
SOS
</pre>
<p>
Kody Morsa możesz znaleźć na przykład w
<a href="http://en.wikipedia.org/wiki/Morse_code">Wikipedii</a>,
a jak przekazać do uruchamianego programu argumenty wywołania
jest opisane w K&amp;R, 5.10.
</p>

<p><b>Zadanie 2.</b>
Napisać program <kbd>dor.c</kbd> wypisujący wszystkie wyrazy
ze słownika Doroszewskiego występujące w napisie podanym na wejściu.
Innymi słowy program ten ma wypisywać wszystkie słowa
powstające po usunięciu zera lub więcej liter z podanego napisu.
</p>

<p>
Oto przykładowe wywołanie tego programu:
</p>
<pre>cat /usr/local/share/dict/doroszewski.words   |   ./dor olaboga | sort
abo
ba
bo
la
log
...
</pre>
<p>
Listę wyrazów ze słownika znajdziesz na mancie w katalogu
<kbd>/usr/local/share/dict/doroszewski.words</kbd>.
</p>

<p><b>Zadanie 3.</b>
Jednym z częściej używanych sposobów umieszczania
napisów w filmach <a href="http://en.wikipedia.org/wiki/SubRip">SubRip</a>.

Napisy wpisujemy w pliku tekstowym w następujący sposób:
<pre>Kolejny numer
Początek -> Koniec
Napisy, byc może w kilku wierszach
Pusty wiersz
</pre>

<p>Na przykład:</p>
<pre>1
00:00:20,000 --> 00:00:26,500
Wlazł kotek na płotek i mruga,
ładna to piosenka niedługa.

2
00:00:28,000 --> 00:00:33,500
Niedługa, niekrótka, lecz w sam raz,
Zaśpiewaj koteczku jeszcze raz.

...
</pre>

<p>Napisy są numerowane kolejnymi liczbami naturalnymi.
Liczba wpisywana jest pierwsza, dalej, w drugim wierszu
wpisujemy czas trwania w formacie
</p>
<pre>godzina:minuta:sekunda,milisekunda
</pre>
<p>W trzecim i dalszych wierszach wpisujemy tekst.
Napis kończy pusty wiersz.</p>

<p>Czasami musimy przesunąć czas we wszystkich napisach
o kilka sekund do przodu lub do tyłu.</p>

<p>Napisać program, który po podaniu mu w linii poleceń
pliku z napisami i przesunięcia wypisze na standardowe
wyjście napisy z przesuniętym czasem:
</p>
<pre>$ subrip +2.500 kotek.txt
00:00:22,500 --> 00:00:29,000
Wlazł kotek na płotek i mruga,
ładna to piosenka niedługa.

2
00:00:30,500 --> 00:00:36,000
Niedługa, niekrótka, lecz w sam raz,
Zaśpiewaj koteczku jeszcze raz.

...
</pre>

<p>Być może wygodnie będzie skorzystać z usług jakiejś
biblioteki oferującej funkcje na czasie 8->
</p>
