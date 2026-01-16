/* Stack.c */
// internal librairies
#include "../../include/utils/Stack.h"
#include "../../include/utils/err_manager.h"
// external librairies
#include <stdlib.h> // exit(), EXIT_FAILURE
#include <stdio.h> // ERR_TERROR()
#include <limits.h>


Stack* sk_create(void* data){
    Stack* stack=malloc(sizeof(Stack));
    if (!stack) // eq to : "stack == NULL"
        ERR_TERROR("malloc didn't worked for `Stack` mem alloc\n");    
    ChainedNode* node = malloc(sizeof(ChainedNode));
    if(!node)
        ERR_TERROR("malloc didn't worked for `Node` mem alloc\n");
    node->cn_data = data;
    node->cn_next = NULL;
    stack->sk_last = node;
    stack->sk_size = 1;
    return stack;
}

void sk_push(Stack* stack, void* data) {
    if (!stack)
        ERR_TERROR("\"stack\" is NULL");
    ChainedNode* node = malloc(sizeof(ChainedNode));
    if (!node)
        ERR_TERROR("malloc for Node failed");
    node->cn_data = data;
    node->cn_next = stack->sk_last;
    stack->sk_last = node;
    stack->sk_size++;
}


void* sk_pop(Stack* stack){
    // stack item stored before removing
    if (!stack || !stack->sk_last) 
        ERR_TERROR("la pile \"stack\" est vide\n");
    ChainedNode* node = stack->sk_last;
    void* res = node->cn_data;
    stack->sk_last = node->cn_next;
    stack->sk_size--;
    free(node);
    return res;
}

void sk_destroy(Stack* stack){
    if (!stack) return;
    ChainedNode* node;
    while (stack->sk_last){
        node=stack->sk_last;
        stack->sk_last=node->cn_next;
        free(node->cn_data);        
        free(node);
    }
    free(stack);
}



// end page