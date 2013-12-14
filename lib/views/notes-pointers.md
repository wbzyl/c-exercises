#### {% title "C Pointers" %}

<blockquote>
  {%= image_tag "/images/john-long.jpg", :alt => "[John W. Long]" %}
  <p>Programmers have almost made code simplicity an art form while
  designers are known for spending vast amounts of time doing very
  tedious and repetitive work to get the effect that they want.</p>
  <p class="author">— John W. Long</p>
</blockquote>

1\. Wskaźniki i adresy:

* deklarowanie zmiennych wskaźnikowych
* operator adresu `&`
* operator wyłuskania (adresowania pośredniego, odwołania pośredniego) `*`
* wskaźnik `NULL`
* operator rozmiaru `sizeof`

2\. Wskaźniki i argumenty funkcji:

* przekazywanie argumentów przez wartość i przez adres: 
* funkcja {%= link_to "swap.c", "/pointers/swap.c" %}
