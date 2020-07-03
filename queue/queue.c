#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1;
#define FAILURE 0;

typedef struct queue_element_{
    struct queue_element_ *next;
    struct queue_element_ *prev;
} queue_element_t;

typedef struct queue_{
    queue_element_t *front;
    queue_element_t *rear;
    int size;
}queue_t;

/*
queue_element_t * initialize_queue_element();

queue_element_t * initialize_queue_element() {
    queue_element_t *element
}
*/

queue_t * init_queue(){
    queue_t *queue = calloc(1, sizeof(queue_t));

    if(queue == NULL) {
        perror("Queue initialization failed!");
        return NULL;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;
}

/*
int destroy_queue(queue_t *queue){

}
*/

int enqueue(queue_t *queue, queue_element_t *element){
    if(!queue) {
        perror("Queue is initialized. Use 'init_queue()' to initialise your queue\n");
        return FAILURE;
    }

    if(is_empty(queue)){
        queue->front = element;
        queue->rear = element;
        queue->size++;
        return SUCCESS; 
    }

    element->next = queue->rear;
    element->prev = NULL;
    queue->rear->prev = element;
    queue->rear = element;
    queue->size++;
    return SUCCESS;
}

queue_element_t * dequeue(queue_t *queue){
    if(is_empty(queue)){
        perror("dequeue operation attempted on an empty queue\n");
        return FAILURE;
    }

    queue_element_t *front = queue->front;
    queue->front = front->prev;
    queue->size--;
    return front;
}

int is_empty(queue_t *queue){
    if(queue->size > 0){
        return 0;
    }
    return 1;
}

queue_element_t * peek(queue_t *queue){
    if(is_empty(queue)){
        perror("empty queue\n");
        return FAILURE;
    }

    return queue->front;
}