#### {% title "Automaty skończone" %}

# Automaty skończone

<blockquote>
  <p>Are there any programming languages you don’t enjoy using?
  </p>
  <p><b>Rob Pike</b>: I'm not comfortable thinking about types before data and
   functions, so I don't enjoy languages like Java and C++ but I respect
   them and can be effective in them. <b>But their bureaucracy</b> – the need to
   tell computer even the simplest things it should be able to figure out for itself 
   – can wear me down. My OSCON keynote on this topic last year, called 
   <a href="http://www.youtube.com/watch?v=5kj5ApnhPAE">Public Static Void</a> 
   seemed to strike a chord with people.
  </p>
</blockquote>

1\. Napisz program, który – przepisując wejście na wyjście
– będzie zastępować jednym znakiem odstępu
każdy ciąg złożony z jednego lub kilku znaków
odstępu lub tabulacji.

Na przykład, następujący ciąg:

    1[spacja][spacja]2[tab][tab]3[tab][tab][spacja]4

powinien zostać przepisany na wyjście jako:
    1[spacja]2[spacja]3[spacja][spacja]4

Przykładowy automat skończony do tego zadania:

{%= image_tag "/images/duplicate_ws.png", :alt => "[Automat skończony]" %}

2\. Napisać program usuwający komentarze z tekstu
programu napisanego w C.
