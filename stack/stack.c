#include <stdlib.h>
#include <stdio.h>

typedef struct stack_element_{
    struct stack_element_ *next;
} stack_element_t;

typedef struct stack_{
    struct stack_element_ *top;
    int size;
}stack_t;

stack_t * init(){
    stack_t *stack = calloc(1, sizeof(stack_t));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int push(stack_t *stack, stack_element_t *element){
    if(!stack) return -1;
    
    if(stack && !stack->top){
        stack->top = element;
        stack->size++;
        return 0;
    }

    element->next = stack->top;
    stack->top = element;
    stack->size++;
    return 0;
}

stack_element_t * pop(stack_t *stack){
    if(!stack || !stack->top) return NULL;

    stack_element_t *top = NULL;
    if(stack->size > 0){
        top = stack->top;    
        stack->top = top->next;
        stack->size--;
    }
    return top;
}