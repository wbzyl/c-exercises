/* 
 * Plik: stack1.c
 * Implementacja interfejsu `stack.h' korzystająca z tablic.
 */

#include <stdio.h>
#include "genlib.h"
#include "stack.h"

#define MaxStackSize 100

/* Reprezentacja ADT -- niedostępna dla klientów */

struct stackCDT {
  stackElementT elements[MaxStackSize];
  int count;
};

/* Eksportowane funkcje */

stackADT NewStack(void) {
  stackADT stack;

  stack=New(stackADT);
  stack->count=0;
  return stack;
}

void FreeStack(stackADT stack) {
  FreeBlock(stack);
}

void Push(stackADT stack, stackElementT element) {
  if (StackIsFull(stack)) Error("Przekroczono rozmiar stosu");
  stack->elements[stack->count++]=element;
}

stackElementT Pop(stackADT stack) {
  if (StackIsEmpty(stack)) Error("Stos jest pusty");
  return stack->elements[--stack->count];
}

bool StackIsEmpty(stackADT stack) {
  return stack->count==0;
}

bool StackIsFull(stackADT stack) {
  return stack->count==MaxStackSize;
}

int StackDepth(stackADT stack) {
  return stack->count;
}

stackElementT GetStackElement(stackADT stack, int index) {
  if (index<0 || index>=stack->count) 
    Error("Nie istniejący element stosu");
  return stack->elements[stack->count-index-1];
}
