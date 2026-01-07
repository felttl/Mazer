/* Node.h */
#ifndef Node_H
#define Node_H


/**
 * a Node for the whole Queue, Stack, etc... 
 * structures that require lower level type
 * 
 * - n_data void* : data stored inside a stack level (step)
 * 
 * - n_next QueueNode* : next item in the stack
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
typedef struct Node Node;
struct Node {
    void* n_data;
    Node* n_next;
};

#endif 

/* end page */
