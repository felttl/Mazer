/* queue.h */
#ifndef QUEUE_H
#define QUEUE_H

#include "Graphs/Node.h"

/**k
 * @brief Queue system
 * 
 * - head QueueNode* : last element (added most recently)
 * 
 * - tail QueueNode* : first element on the left of the queue (see repr bellow)
 * 
 * - index unsigned int : index of a Queue in the chain of queues
 * 
 * a is head e is tail :
 * 
 * a->b->c->d->e->NULL
 */
typedef struct {
    Node* qu_head;
    Node* qu_tail;
    unsigned int qu_size;
} Queue ;

/**
 * @brief initialize a Queue with one level (1 step)
 * @warning need a free on it later (using `qu_destroy()`)
 * 
 * @param data void* : bloc of data in the link of Queue
 * @return Queue* : fully built Queue
 */
Queue* qu_create(void* data);

/**
 * @brief add a node in the queue (clean way)
 * abstract all others things that happens
 * @param q Queue* : the queue where adding the "chain" link 
 * @param to_add QueueNode* : the "chain" link to add
 */
void qu_push(Queue* q, Node* to_add);

/**
 * @brief remove the last (tail) element and send his data content
 * 
 * @param q Queue* : a Queue to process removal
 * @return void* : data that have been stored
 */
void* qu_pop(Queue* q);

/**
 * @brief remove everything allocated and related to the Queue input
 * 
 * @param q Queue* : a Queue to process `free()` cleanly
 */
void qu_destroy(Queue* q);


#endif

// end page 
