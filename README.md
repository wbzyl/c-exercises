# Środowisko Programisty

Gem zawierający zadania do wykładu „Języki Programowania”.

Zobacz też:

* [Clarifying the Roles of the .gemspec and Gemfile](http://yehudakatz.com/2010/12/16/clarifying-the-roles-of-the-gemspec-and-gemfile/) (TL;DR – Too long; didn't read)


## Instalacja

Wykonać polecenie:

    gem install c-exercises


## Uruchamianie

Sprawdzamy gdzie w systemie został zainstalowany gem *c-exercises*:

    gem which c-exercises

Aplikację uruchamiamy w taki sposób:

<pre>rackup /«<i>ścieżka do katalogu z gemem</i>»/lib/config.ru -p «<i>numer portu</i>»
</pre>

Na przykład:

    rackup rackup /usr/lib/ruby/gems/1.8/gems/c-exercises-0.0.0.0/lib/config.ru -p 8098

Po uruchomieniu aplikacja jest dostępna z URL:

    http://localhost:8098/
