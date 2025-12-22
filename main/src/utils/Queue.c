/* queue.c */
#include "./Queue.h"
#include <stdlib.h>

struct Queue {
    int *data;
    size_t size;
};

// struct Queue a = {4,1};

Queue* queue_create(void);
void queue_push(Queue*, int);
int  queue_pop(Queue*);
void queue_destroy(Queue*);

// end page
