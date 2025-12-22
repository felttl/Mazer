/* Stack.h */
#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

/**
 * @brief permet de créer une cellule de pile
 * @param line numero de ligne a inserer dans la pile
 * @param column numero de colonne a inserer dans la pile
 * @param num_step numero a inserer dans la pile
 * 
 * 
*/
Stack* Sk_create(int line, int column, int num_step);

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
 * 4) top = new→NULL
 * 5) ||||→NULL
 * 
 * @param top_main_stack est l'élément qui se sittue tout au dessus de la pile
 * @param add_to_main est l'élément a ajouter a la pile
*/
void Sk_push(Stack* top_main_stack, Stack* add_to_main);

/**
 * @short permet de dépiler une pile
 * @param top le sommet de la pile
 * @return renvoie l'index de l'élément si top est bien le haut de la pile
*/
int sk_pop(Stack* top);

/**
 * @brief permet de supprimer une pile entièrement
 * @param top_stack est le haut de la pile (top/head)
*/
void Sk_remove(Stack* top_stack);

#endif

// end page
