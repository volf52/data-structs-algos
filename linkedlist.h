#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef int listunit;

typedef struct snode
{
  listunit val;
  struct snode *next;
} SNode;

typedef struct dnode
{
  listunit val;
  struct dnode *next;
  struct dnode *prev;
} DNode;

#endif
