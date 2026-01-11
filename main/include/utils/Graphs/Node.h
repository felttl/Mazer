/* Node.h */
#ifndef Node_H
#define Node_H


/**
 * a Node for the whole Queue, Stack, etc... 
 * structures that require lower level type
 * 
 * - n_data `void*` : data stored inside a stack level (step)
 * 
 * - n_next `Node*` : next item in the chain on Nodes
 */
typedef struct Node Node;
struct Node {
    void* n_data;
    Node* n_next;
};

#endif 

/* end page */
