#### {% title "Abstrakcyjne typy danych" %}

Abstrakcyjne typy danych to po angielsku
[Abstract Data Types](https://en.wikipedia.org/wiki/Abstract_data_type).
Przykładem ADT jest [Stack](https://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29)
co tłumaczymy na język polski jako stos.

Interfejs, *stack.h*:

    :::c
    #ifndef _stack_h
    #define _stack_h

    #include "genlib.h" // definiuje typ bool

    // Typ elementów umieszczanych na stosie.
    // Tutaj zdefiniowany jako `double', ale można go
    // zmienić edytując wiersz poniżej.

    typedef double stackElementT;

    // Poniżej definiujemy nieprzezroczysty typ danych stackADT (opaque type).
    // Oznacza to, że klienci nie mają dostępu do pól struktury.

    typedef struct stackCDT *stackADT;

    // Eksportowane funkcje

    stackADT NewStack(void);
    void FreeStack(stackADT);
    void Push(stackADT, stackElementT);
    stackElementT Pop(stackADT);
    bool StackIsEmpty(stackADT);
    bool StackIsFull(stackADT);
    int StackDepth(stackADT);
    stackElementT GetStackElement(stackADT,int);

    #endif

Implementacje:

1. {%= link_to "stack1.c", "/stack/stack1.c" %} – implementacja korzystająca z tablic
1. {%= link_to "stack.c", "/stack/stack.c" %} – jw. ale bez ograniczenia na rozmiar stosu
1. {%= link_to "stack2.c", "/stack/stack2.c" %} – implementacja korzystająca z list

Zastosowanie ADT:

1. {%= link_to "rpn-simulation.c", "/stack/rpn-simulation.c" %} – kalkulator
  używający odwrotnej notacji polskiej

Plik Makefile do kompilacji wszystkich wersji:

    CFLAGS = -Wall -std=c11
    CC = gccx

    sources = stack.h stack2.c stack1.c stack.c rpn-simulation.c
    programs = rpn2 rpn1 rpn

    all : rpn rpn1 rpn2

    stack2.o : stack2.c stack.h
    stack1.o : stack1.c stack.h
    stack.o : stack.c stack.h
    rpn-simulation.o : rpn-simulation.c

    rpn2 : rpn-simulation.o stack2.o
    	$(CC) -o $@ $^
    rpn1 : rpn-simulation.o stack1.o
    	$(CC) -o $@ $^
    rpn : rpn-simulation.o stack.o
    	$(CC) -o $@ $^

    .PHONY : clean
    clean:
    	rm -f core *.o *~ \#* $(programs)
