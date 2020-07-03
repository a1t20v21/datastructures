#ifndef __QUEUE__
#define __QUEUE__

typedef struct queue_element_ *queue_element_t;
typedef struct queue_ *queue_t;

queue_t * init_queue();
int enqueue(queue_t *queue, queue_element_t *element);
queue_element_t * dequeue(queue_t *queue);
int is_empty(queue_t *queue);
queue_element_t * peek(queue_t *queue);
void destroy_queue(queue_t *queue);

#endif