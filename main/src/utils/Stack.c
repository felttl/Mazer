/* Stack.c */
// internal librairies
#include "../../include/utils/Stack.h"
#include "../../include/utils/err_manager.h"
// external librairies
#include <stdlib.h> // exit(), EXIT_FAILURE
#include <stdio.h> // terror()
#include <limits.h>


Stack* sk_create(void* data){
    Stack* stack=malloc(sizeof(Stack));
    if (stack == NULL){
        terror("malloc didn't worked for `Stack` mem alloc\n");
    }
    stack->data=data;
    stack->index=0;
    stack->last=NULL;
    return stack;
}

void sk_push(Stack* top_stack, Stack* add_to) {
    if (top_stack == NULL){
        terror("empty top stack, must be initialized first");
    }
    if (add_to == NULL){
        terror("empty add_to stack");
    }
    if (add_to->last != NULL){
        terror("top Stack is not alone (not a single element)");
    }
    // we suppose that "top_stack->index" exists as uint (is not null)
    if(top_stack->index+1 > UINT_MAX){ // limit case
        terror("max items counts on the stack reached (index count overflow)");
    }
    add_to->index=top_stack->index+1;
    add_to->last=top_stack;
    // move the head
    top_stack=add_to;
}


int sk_pop(Stack* top){
    // top item stored before removing
    if (top == NULL) {
        terror("la pile est nulle\n");
    }
    int res=top->index;    
    // A VERIFIER (cmportement étrange si l'élément reste seul et qu'il y en as 1)
    if (top->last == NULL){
        terror("impossible de libérer la pile elle ne contient pas d'éléments\n");
    }
    Stack* tmp=top;
    top=top->last;
    free(tmp);
    return res;
}

void sk_remove(Stack* top_stack){
    if (top_stack == NULL)
        terror("sommet de la pile nulle, opération `sk_remove() impossible`");
    if (top_stack->last == NULL){
        free(top_stack);
        return;
    }
    do {
        Stack* lastS=top_stack;
        top_stack=top_stack->last;
        free(lastS);
    } while (top_stack != NULL);
}



// end page