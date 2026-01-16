/* Stack.h */
#ifndef STACK_H
#define STACK_H

#include "Graphs/ChainedNode.h"

/**
 * @author Félix TTL
 * @date 23/12/2025
 * @version V2
 * @project_name : Mazer
 */

/**
 * @brief classical Stack Structure
 * 
 * - size `unsigned int` : `explicit`
 * 
 * - top `Node*` : top node of the stack
 *
 * data example : 
 * 
 * names :    NULL<-a<-b<-c<-d<-e<-f
 * (f is top)
 */
typedef struct Stack Stack;
struct Stack {
    unsigned int sk_size;
    ChainedNode* sk_last;
};


/**
 * @brief create/initialize a level of stack (only one)
 * @param data `void*` store a data in a Stack level
 * @return `Stack*` the new stack created
 */
Stack* sk_create(void* data);

/**
 * @brief add an Stack item on top of a Stack item
 * (add only 1 item on a stack)
 * @param top_stack Stack* : is the item on the top of a stack (on right on the scheme)
 * @param data void* : data to add on the stack
 *
 * exemple :
 * 
 * from :   NULL<-a
 * 
 * to   :   NULL<-a<-b
 * 
 * -------------------
 * 
 * from :   NULL<-a<-b
 * 
 * to   :   NULL<-a<-b<-c
 * 
*/
void sk_push(Stack* stack, void* data);

/**
 * @short permet de dépiler une pile
 * @param stack `explicit`
 * @return renvoie les données contenu dans le niveau de pile supprimé
*/
void* sk_pop(Stack* stack);

/**
 * @brief permet de supprimer une pile entièrement 
 * et de manière sécurisé (mémoire) (free la Stack et son contenu)
 * @param stack `explicit`
*/
void sk_destroy(Stack* stack);

#endif

// end page
