# Środowisko Programisty

Gem zawierający zadania do wykładu „Języki Programowania”.

Zobacz też:

* [Clarifying the Roles of the .gemspec and Gemfile](http://yehudakatz.com/2010/12/16/clarifying-the-roles-of-the-gemspec-and-gemfile/) (TL;DR – Too long; didn't read)
* [Using >= Considered Harmful (or, What’s Wrong With >=)](http://yehudakatz.com/2010/08/21/using-considered-harmful-or-whats-wrong-with/)

Quotes from the above.

Developing gem:
„Do not check your *Gemfile.lock* into version control since it enforces
precision that does not exist in the *gem* command, which is used to
install gems in practice.”

Developing app:
„Check in your *Gemfile.lock*, since you will use the *bundler* tool
across all machines, and the precision enforced by *bundler* is
extremely desirable for applications.”


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


## CodeRay

Lista języków:

    cd coderay/coderay/scanners
    egrep register_for *

    egrep register_for *
    clojure.rb:      register_for :clojure
    cpp.rb:    register_for :cpp
    c.rb:    register_for :c
    css.rb:    register_for :css
    debug.rb:    register_for :debug
    delphi.rb:    register_for :delphi
    diff.rb:    register_for :diff
    groovy.rb:    register_for :groovy
    html.rb:    register_for :html
    java.rb:    register_for :java
    java_script.rb:    register_for :java_script
    json.rb:    register_for :json
    nitro_xhtml.rb:    register_for :nitro_xhtml
    php.rb:    register_for :php
    python.rb:    register_for :python
    raydebug.rb:    register_for :raydebug
    rhtml.rb:    register_for :rhtml
    ruby.rb:    register_for :ruby
    scheme.rb:      register_for :scheme
    sql.rb:    register_for :sql
    text.rb:      register_for :text
    xml.rb:    register_for :xml
    yaml.rb:    register_for :yaml

Aliasy z pliku *_map.rb*:

    map \
      :cplusplus => :cpp,
      :'c++' => :cpp,
      :ecmascript => :java_script,
      :ecma_script => :java_script,
      :irb => :ruby,
      :javascript => :java_script,
      :js => :java_script,
      :nitro => :nitro_xhtml,
      :pascal => :delphi,
      :patch => :diff,
      :plain => :text,
      :plaintext => :text,
      :xhtml => :html,
      :yml => :yaml

    default :text


