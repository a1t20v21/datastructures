#ifndef _LLIST_H_
#define _LLIST_H_

typedef struct element_ {
    struct element_ *next;
} element;

typedef struct stack_ {
    element *top;
    int size;
} stack;

#endif
