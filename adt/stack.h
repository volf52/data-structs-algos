#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100

typedef int StackUnit;

typedef struct
{
    int index;
    StackUnit data[STACK_SIZE];
} STACK;

STACK *initStack();
int stackEmpty(STACK *);
int stackFull(STACK *);
int push(StackUnit, STACK *);
int pop(StackUnit *, STACK *);
int peek(StackUnit *, STACK *);
void print_stack(int, STACK *);

#endif
