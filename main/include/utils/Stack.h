/* Stack.h */
#ifndef STACK_H
#define STACK_H

/**
 * @author Félix TTL
 * @date 23/12/2025
 * @version V2
 * @project_name : Mazer
 */

/**
 * @brief classical Stack Structure
 * 
 * - index `unsigned int` : index of a stack (internally managed by funct"s)
 * 
 * - data `void*` : data stored inside a Stack Object
 * 
 * - last `Stack*` : last Stack structure on the Stack (internally managed)
 * 
 * data example : 
 * 
 * names :    NULL<-a<-b<-c<-d<-e<-f
 * 
 * indexes :  NULL<-0<-1<-2<-3<-4<-5
 * 
 * data :     can be anything (cba)
 * 
 * data :     NULL<-cba<-cba<-cba<-cba<-cba<-cba
 * 
 */
typedef struct Stack Stack;
struct Stack {
    unsigned int index;
    void* data;
    Stack* last;
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
 * @param add_to Stack* : is the item to add on top
 * 
 * @enered (moved to en lang)
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
void sk_push(Stack* top_stack, Stack* add_to);

/**
 * @short permet de dépiler une pile
 * @param top le sommet de la pile
 * @return renvoie les données contenu dans le niveau de pile supprimé
*/
void* sk_pop(Stack* top);

/**
 * @brief permet de supprimer une pile entièrement
 * @param top_stack est le haut de la pile (top/head)
*/
void sk_remove(Stack* top_stack);

#endif

// end page
