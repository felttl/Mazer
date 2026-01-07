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
    Node* node = malloc(sizeof(Node));
    if(!node)
        ERR_TERROR("malloc didn't worked for `Node` mem alloc\n");
    node->n_data = data;
    node->n_next = NULL;
    stack->sk_last = node;
    stack->sk_size = 1;
    return stack;
}

void sk_push(Stack* stack, void* data) {
    if (!stack)
        ERR_TERROR("\"stack\" is NULL");
    Node* node = malloc(sizeof(Node));
    if (!node)
        ERR_TERROR("malloc for Node failed");
    node->n_data = data;
    node->n_next = stack->sk_last;
    stack->sk_last = node;
    stack->sk_size++;
}


void* sk_pop(Stack* stack){
    // stack item stored before removing
    if (!stack || !stack->sk_last) 
        ERR_TERROR("la pile \"stack\" est vide\n");
    Node* node = stack->sk_last;
    void* res = node->n_data;
    stack->sk_last = node->n_next;
    stack->sk_size--;
    free(node);
    return res;
}

void sk_remove(Stack* stack){
    if (!stack) return;
    Node* node;
    while (stack->sk_last){
        node=stack->sk_last;
        stack->sk_last=node->n_next;
        free(node);
    }
}



// end page