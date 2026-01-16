/* ChainedNode.h */
#ifndef CHAINED_NODE_H
#define CHAINED_NODE_H


/**
 * a Node for the whole Queue, Stack, etc... 
 * structures that require lower level type
 * 
 * - nd_data `void*` : data stored inside a stack level (step)
 * 
 * - nd_next `Node*` : next item in the chain on Nodes
 */
typedef struct ChainedNode ChainedNode;
struct ChainedNode {
    void* cn_data;
    ChainedNode* cn_next;
};

/**
 * @brief initialize a simple node
 * 
 * @param data 
 * @return Node* 
 */
ChainedNode* cn_create(void* data);

/**
 * @brief remove safely all the data stored
 * inside of a ChainedNode
 * @param node to be free
 */
void cn_destroy(ChainedNode* node); 

#endif

/* end page */
