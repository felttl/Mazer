/* ChainedNode.c */
#include "../../../include/utils/Graphs/ChainedNode.h"
#include "../../../include/utils/err_manager.h"
#include <stdlib.h>

ChainedNode* cn_create(void* data){
    ChainedNode* cn = malloc(sizeof(ChainedNode));
    if(!cn) ERR_TERROR("malloc didn't worked the memory is maybe full");
    cn->cn_data = data;
    cn->cn_next = NULL;
    return cn;
}

void cn_destroy(ChainedNode* node){
    if(!node) return;
    free(node->cn_data);
    free(node); // both link "next" and "node" are free
}

/* end page */
