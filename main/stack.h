#include "./add_lib.h"

typedef struct Stack{
    // data
    int line;
    int column;
    int num_step;
    int index; 
    char character; // gestion des erreurs pour matrice
    // structure
    struct Stack * last;
} Stack ;

/**
 * @brief permet de créer une cellule de pile
 * @param line numero de ligne a inserer dans la pile
 * @param column numero de colonne a inserer dans la pile
 * @param num_step numero a inserer dans la pile
 * 
 * 
*/
Stack*create_Stack(int line int column, int num_step){
    Stack*stack=malloc(sizeof(Stack));
    if (stack != NULL){
        stack->character='\0';
        stack->column=column;    
        stack->line=line;    
        stack->num_step=num_step;    
        stack->next=NULL;
        stack->last=NULL;          
    } else {
        printf("malloc n'as pas fonctionné \n");
        exit(EXIT_FAILURE);
    }
      
}

/**
 * @brief permet d'enmpiler une structure pile dans une pile
 * (ajoute 1 élément dans une pile)
 * 
 * 012
 * |||
 * to
 * 0123
 * ||||
 * →↔←
 * étapes détaillées :
 * 1) |||→NULL
 * 2) |||→new
 * 3) |||↔new
 * 4) top = new
 * 5) ||||→NULL
 * 
 * 
 * @param top_main_stack est l'élément qui se sittue tout au dessus de la pile
 * @param add_to_main est l'élément a ajouter a la pile
*/
void push(Stack *top_main_stack, Stack*add_to_main) {
    if (top_main_stack != NULL && add_to_main != NULL){
        add_to_main->last=top_main_stack;
        // déplacement de l'entete
        top_main_stack=add_to_main;
    } else {
        printf("les données saisies doivent être correctes\n");
        exit(EXIT_FAILURE);
    }
}
/**
 * permet de dépiler une pile
 * @param top le sommet de la pile
 * @return renvoie l'index de l'élément si top est bien le haut de la pile
*/
int pop(Stack*top){
    int res=bottom->num_step;
    if (top->last != NULL && top != NULL){
        Stack*tmp=top;
        top=top->last;
        free(tmp);
    } else {
        if (top == NULL) {
            printf("error: la pile est vide\n");
            exit(EXIT_FAILURE);               
        }
        printf("error: impossible de libérer la pile elle ne contient pas d'éléments\n");
        exit(EXIT_FAILURE);            
    }
    return res;
}

/**
 * @brief permet de supprimer une pile entièrement
 * @param top_stack est le haut de la pile (top/head)
*/
void remove_Stack(Stack*top_stack){
    if (top_stack->next == NULL){
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