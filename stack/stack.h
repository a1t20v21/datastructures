#ifndef __STACK__
#define __STACK__

/*Opaque pointer implementation*/
typedef struct stack_element_ *stack_element_t;
typedef struct stack_ *stack_t;

stack_t * init();
stack_element_t init_stack_element();
int push(stack_t *stack, stack_element_t *element);
stack_element_t * pop(stack_t *stack); 

#define init_stack_element(element) \
    element->next = NULL;
#endif