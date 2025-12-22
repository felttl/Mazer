/* queue.h */
#ifndef QUEUE_H
#define QUEUE_H
/**
 * salut c'est queue
 */
typedef struct Queue Queue;

Queue* queue_create(void);
void queue_push(Queue*, int);
int  queue_pop(Queue*);
void queue_destroy(Queue*);

#endif

// end page 
