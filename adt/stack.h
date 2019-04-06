#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100

typedef struct {
  int index;
  int data[STACK_SIZE];
} STACK ;

STACK * initStack();
int isEmpty(STACK *);
int isFull(STACK *);
int push(int, STACK *);
int pop(int *, STACK *);
int peek(int *, STACK *);
void print_stack(int, STACK *);

#endif
