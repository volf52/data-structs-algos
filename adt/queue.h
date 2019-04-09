#ifndef QUEUE_H
#define QUEUE_H

#define MAXQUEUE 10

typedef int QueueUnit;

typedef struct queue{
  int count;
  int front;
  int rear;
  QueueUnit entry[MAXQUEUE];
} Queue;

Queue * initQueue();
void append(QueueUnit, Queue *);
void serve(QueueUnit *, Queue *);
int queueSize(Queue *);
int queueEmpty(Queue *);
int queueFull(Queue *);

#endif
