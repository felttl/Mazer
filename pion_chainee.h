#include "./add_lib.h"


/**
 * 
 * la ou le pion se déplacera il y aura le numéro 5 sur la grille
 * pour indiquer a la fonction affichage que la case est parcourue par
 * la pion
 * 
 * le pion ne devra que avancer (sauf cas contraire) 
 * 
 * 
 * 
 * 
*/


// structure pour déplacement du pion
typedef struct Pion{
    int line, column, num_step;
    struct Pion * suivant;
} Pion ;




/**
 * creer pion
*/
Pion * create_Pion(int x, int y, int num){
    Pion * res;
    res = (Pion*)malloc(sizeof(Pion));
    res->line = x;
    res->column = y;
    res->num_step = num;
    res->suivant = NULL;
    return res;
}

/**
 * libere la mémoire dont l'entete est donné en paramètres
 * 
 * on libere chaque element tant qu'il y en as encore un 
 * mais si l'entete n'est pas suivie de variable alors 
 * on doit le liberer elle
*/
void free_chain(Pion * head_Pion){
    Pion * temp;
    Pion * last=head_Pion;
    while(temp->suivant != NULL || temp->num_step != 0){
        first = head_Pion->suivant;
        free(temp);
    }
    free(temp);
}

/**
 * @brief permet de déplacer le pion dans la matrice en utilisant
 * sa position de départ en longeant le coté droit du mur auquel 
 * il se trouve
 * 
 * - si le pion revient a une de ses positions précédentes
 *  il y a une erreur (sauf si c'est une impasse)
 * 
 * 3 dirrections possibles 1 pour reculer
 * 
 * less positions de départ sont données en paramètre
 * @param posx coordonnées x du pion
 * @param posy coordonnées y du pion
*/
void forward_right(int posx, int posy){

    Pion * step_pion=create_Pion(posx, posy, 0); // entete de al chaine des pisotions du pion
    int carry = 1; 


    Pion * head_pion = step_pion;
    int headingx; // orientation du pion x
    int headingy; // orientation du pion y


    // on continue tant que l'on trouve pas le point de sortie
    while (carry == 1){
        if(){// si pas de mur a droite

        } else if {// si pas de mur a gauche

        } else if (){// si pas de mur devant

        } else {// si mur devant droite et gauche on recule et on sert de l'impasse

        }
                
        
        
    }

    // programme terminé 'relacement de mémoire'

    
}





// end page
