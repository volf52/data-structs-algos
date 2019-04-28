#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *initQueue()
{
    Queue *p;
    p = (Queue *)malloc(sizeof(Queue));
    if (p == NULL)
    {
        printf("Couldn't allocate enough memory for Queue\n");
        printf("Line %d \t File %s\n Exiting...", __LINE__, __FILE__);
        exit(-1);
    }

    p->count = 0;
    p->front = 0;
    p->rear = -1;

    return p;
}

void enqueue(QueueUnit x, Queue *q)
{
    if (queueFull(q))
        printf("Cannot add to full queue.\n");
    else
    {
        q->rear = (q->rear + 1) % MAXQUEUE;
        q->data[q->rear] = x;
        q->count++;
    }
}

void dequeue(QueueUnit *x, Queue *q)
{
    if (queueEmpty(q))
        printf("Cannot serve from an empty queue.\n");
    else
    {
        *x = q->data[q->front];
        q->front = (q->front + 1) % MAXQUEUE;
        q->count--;
    }
}

int queueSize(Queue *q)
{
    return q->count;
}

int queueEmpty(Queue *q)
{
    return q->count <= 0;
}

int queueFull(Queue *q)
{
    return q->count >= MAXQUEUE;
}
