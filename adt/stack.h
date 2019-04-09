#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100

typedef int StackUnit;

typedef struct {
  int index;
  StackUnit data[STACK_SIZE];
} STACK ;

STACK * initStack();
StackUnit isEmpty(STACK *);
StackUnit isFull(STACK *);
StackUnit push(StackUnit, STACK *);
StackUnit pop(StackUnit *, STACK *);
StackUnit peek(StackUnit *, STACK *);
void print_stack(int, STACK *);

#endif
