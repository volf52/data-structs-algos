#ifndef QUEUE_H
#define QUEUE_H

#define MAXQUEUE 10

typedef int QueueUnit;

typedef struct queue
{
    int count;
    int front;
    int rear;
    QueueUnit data[MAXQUEUE];
} Queue;

Queue *initQueue();
void enqueue(QueueUnit, Queue *);
void dequeue(QueueUnit *, Queue *);
int queueSize(Queue *);
int queueEmpty(Queue *);
int queueFull(Queue *);

#endif
