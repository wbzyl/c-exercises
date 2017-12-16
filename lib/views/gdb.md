#### {% title "GDB", false %}

Podstawowe polecenia debuggera gdb:

Argumenty wywołania programu ARGUMENTY wpisujemy tak:

    :::bash
    set args ARGUMENTY

albo tak:

    :::bash
    set args ARGUMENTY < input.txt

albo tak:

    :::bash
    run ARGUMENTY < input.txt

Najczęściej wykonywane polecenia:

* **b main** – ustawiamy punkt przerwania (pułapkę) na funkcji main albo **b 13** – w linii 13
* **run** – teraz uruchamiamy program
* **n** – wykonaj następną linię programu
* **s** – j.w. ale przejdź do funkcji wywoływanych
* **p WYRAŻENIE** – wypisz wartość wyrażenia
* watch ZMIENNA – śledź zmiany wartości zmiennej
* **bt** – pokaż stos programu
* **quit** – zakończ pracę
* **c** – kontynuuj
* **u** – zakończ wykonywanie pętli
* **return WYRAŻENIE** – anuluj wywołanie funkcji (zwróć WYRAŻENIE)
* **finish** – zakończ wykonywanie funkcję; wypisz zwracaną wartość
