/* GNode.h */
#ifndef GNode_H
#define GNode_H


/**
 * Graph Node
 * structures that require lower level type
 * 
 * - gn_data `void*` : data stored inside
 * 
 * - gn_name `char*` : name of the node
 */
typedef struct GNode GNode;
struct GNode {
    void* n_data;
    char* name;
};

/**
 * @brief initialize a node
 * 
 * @param data 
 * @return Node* 
 */
GNode* nd_create(void* data);

#endif 

/* end page */
