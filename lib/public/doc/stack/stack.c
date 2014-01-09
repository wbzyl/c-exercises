/*
 * Plik: stack.c
 * Implementacja interfejsu `stack.h' wykorzystująca tablice.
 * W tej implementacji usuwamy ograniczenie na rozmiar stosu.
 */

#include <stdio.h>
#include "genlib.h"
#include "stack.h"

#define InitialStackSize 2

/* Reprezentacja ADT -- niedostępna dla klientów */

struct stackCDT {
  stackElementT *elements;
  int count;
  int size;
};

static void ExpandStack(stackADT);

/* Eksportowane funkcje */

stackADT NewStack(void) {
  stackADT stack;

  stack=New(stackADT);
  stack->elements=NewArray(InitialStackSize, stackElementT);
  stack->count=0;
  stack->size=InitialStackSize;
  return stack;
}

void FreeStack(stackADT stack) {
  FreeBlock(stack->elements);
  FreeBlock(stack);
}

void Push(stackADT stack, stackElementT element) {
  if (stack->count==stack->size) ExpandStack(stack);
  stack->elements[stack->count++]=element;
}

static void ExpandStack(stackADT stack) {
  stackElementT *array;
  int i, newSize;

  newSize=stack->size * 2;
  array=NewArray(newSize, stackElementT);
  for (i=0; i<stack->size; i++)
    array[i]=stack->elements[i];
  FreeBlock(stack->elements);
  stack->elements=array;
  stack->size=newSize;
}

stackElementT Pop(stackADT stack) {
  if (StackIsEmpty(stack)) Error("Stos jest pusty");
  return stack->elements[--stack->count];
}

bool StackIsEmpty(stackADT stack) {
  return stack->count==0;
}

bool StackIsFull(stackADT stack) {
  return FALSE;
}

int StackDepth(stackADT stack) {
  return stack->count;
}

stackElementT GetStackElement(stackADT stack, int index) {
  if (index<0 || index>=stack->count)
    Error("Nie istniejący elemnt stosu");
  return stack->elements[stack->count-index-1];
}
