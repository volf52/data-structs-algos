#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK * initStack(){
  STACK *s = (STACK *) malloc(sizeof(STACK));
  if (s == NULL){
    printf("Memory could not be allocated for the stack.");
    exit(-1);
  }
  s -> index = 0;
  return s;
}

int isEmpty(STACK *s){
  if(s -> index == 0)
    return 1;
  else
    return 0;
}

int isFull(STACK *s){
  if(s -> index == 0)
    return 1;
  else
    return 0;
}

int push(int x, STACK *s){
  if(isFull(s)){
    printf("Stack is full...Can't push item.\n");
    return 0;
  }
  else{
    s -> data[s -> index++] = x;
    return 1;
  }
}

int pop(int *x, STACK *s){
  if(isEmpty(s))
    return 0;
  else{
    *x = s -> data[-- s -> index];
    return 1;
  }
}

int peek(int *x, STACK *s){
  int adr;
  if(isEmpty(s))
    return 0;
  else{
    adr = s -> index - 1;
   *x  = s -> data[adr];
    return 1;
  }
}

void print_stack(int type, STACK *s){
  int i = 0;
  if(s == NULL){
    printf("NULL pointer exception. Attempting to print an uninitialized stack");
    exit(-1);
  }
  if(s -> index == 0){
    printf("Empty stack...nothing to print\n");
    return;
  }

  while( i < s -> index){
    if(type == 11) // op stack
      printf("%c\t", s -> data[i]);
    i++;
  }
  printf("\n End of stack\n");
}
