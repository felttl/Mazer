/* queue.h */
#ifndef QUEUE_H
#define QUEUE_H

/**
 * a Queue Node for the whole Queue structure configuration
 * 
 * - qn_data void* : data stored inside a stack level (step)
 * 
 * - qn_next QueueNode* : next item in the stack
 * 
 * system : 
 * a->b->c->d->e->NULL
 * 
 * a is first element and e is last (<- represents the next)
 * to dequeue, a is removed. To enqueue, f is added after e like :
 * 
 * dequeue a : 
 * b->c->d->e->NULL
 * enqueue f :
 * b->c->d->e->f->NULL
 * 
 */
typedef struct QueueNode QueueNode;
struct QueueNode {
    void* qn_data;
    QueueNode* qn_next;
};

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
    QueueNode* qu_head;
    QueueNode* qu_tail;
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
void qu_push(Queue* q, QueueNode* to_add);

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
