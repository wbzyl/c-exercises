/* 
 * Plik: rpn-simulation.c
 * Kalkulator używający odwrotnej notacji polskiej
 * (RPN -- reverse Polish notation).
 */

#include <stdio.h>
#include <ctype.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "stack.h"

static void ApplyOperator(char op, stackADT stack);
static void HelpCommand(void);
static void ClearStack(stackADT stack);
static void DisplayStack(stackADT stack);

int main () 
{
  stackADT operandStack;
  string line;
  char ch;

  printf("RPN kalkulator -- symulacja (napisz H aby otrzymać pomoc)\n");
  operandStack=NewStack();
  while (TRUE) {
    printf("> ");
    line=GetLine();
    ch=toupper(line[0]);
    switch (ch) {
      case 'Q': exit(0);
      case 'H': HelpCommand(); break;
      case 'C': ClearStack(operandStack); break;
      case 'D': DisplayStack(operandStack); break;
      default: if (isdigit(ch))
          Push(operandStack, StringToReal(line));
        else
          ApplyOperator(ch, operandStack);
        break;
    }
  }
}

static void ApplyOperator(char op, stackADT stack) 
{
  double lhs, rhs, result;
  rhs=Pop(stack);
  lhs=Pop(stack);
  switch (op) {
    case '+': result=lhs+rhs; break;
    case '-': result=lhs-rhs; break;
    case '*': result=lhs*rhs; break;
    case '/': result=lhs/rhs; break;
    default: Error("Niedozwolony operator %c", op);
  }
  printf("# %g\n", result);
  Push(stack, result);
}

static void HelpCommand(void) 
{
  printf("\n");
  printf("Q -- wyjście z programu\n");
  printf("H -- wyświetl tę pomoc\n");
  printf("C -- wyczyść stos kalkulatora\n");
  printf("D -- pokaż wszystkie elementy stosu\n");
}

static void ClearStack(stackADT stack) 
{
  while (!StackIsEmpty(stack)) Pop(stack);
}

static void DisplayStack(stackADT stack) 
{
  int i, depth;
  printf("Stos: ");
  depth=StackDepth(stack);
  if (depth==0) {
    printf("pusty\n");
  } else {
    for (i=depth-1;i>=0; i--) {
      if (i<depth-1) printf(" ");
      printf("%g", GetStackElement(stack,i));
    }
    printf("\n");
  }
}
