#include "./Stack.h"
#include <stdlib.h> // exit(), EXIT_FAILURE
#include <stdio.h> // perror()

struct Stack{
    // data
    int line;
    int column;
    int num_step;
    int index; 
    char character; // gestion des erreurs pour matrice
    // structure
    Stack* last;
};

Stack* Sk_create(int line, int column, int num_step){
    Stack* stack=malloc(sizeof(Stack));
    if (stack == NULL){
        perror("malloc didn't worked for `Stack` mem alloc\n");
        exit(EXIT_FAILURE);
    }
    stack->character='\0';
    stack->column=column;
    stack->line=line;
    stack->num_step=num_step;
    stack->last=NULL;
    return stack;
}

void Sk_push(Stack* top_main_stack, Stack* add_to_main) {
    if (top_main_stack != NULL && add_to_main != NULL && top_main_stack->last != NULL){
        add_to_main->last=top_main_stack;
        // déplacement de l'entete
        top_main_stack=add_to_main;
    } else {
        perror("les données saisies doivent être correctes\n");
        exit(EXIT_FAILURE);
    }
}


int sk_pop(Stack* top){
    // top item stored before removing
    int res=top->num_step;
    if (top == NULL) {
        printf("error: la pile est vide\n");
        exit(EXIT_FAILURE);
    }
    // A VERIFIER (cmportement étrange si l'élément reste seul et qu'il y en as 1)
    if (top->last == NULL){
        printf("error: impossible de libérer la pile elle ne contient pas d'éléments\n");
        exit(EXIT_FAILURE);   
    }
    Stack* tmp=top;
    top=top->last;
    free(tmp);
    return res;
}

void Sk_remove(Stack* top_stack){
    if (top_stack != NULL && top_stack->last == NULL){
        do {
            Stack*lastS=top_stack;        
            top_stack=top_stack->last;
            free(lastS);
        }while (top_stack != NULL);        
    } else {
        printf("ce n'est pas le haut de la pile\nil est nécessaire ");
        printf("de dépiler avant(index=%d)\n", top_stack->num_step);
        exit(EXIT_FAILURE);
    }
}



// end page