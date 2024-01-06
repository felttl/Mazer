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
 * on doit la liberer elle
*/
void free_pion_chain(Pion * head){
    Pion*temp=head, last=head;
    // et pas temp->null car il manque le dernier
    while(temp != NULL){ 
        temp=temp->next;
        free(last);
        last=temp;
    }
}

/**
 * @brief permet de supprimer un maillon de la chaine de pion
 * 
 * ex avec les indexes des maillons:
 * 
 *      0->1->2->3->4->NULL
 *      0->1->2->4->NULL
 * 
*/
void remove_at(Pion * head, int index){
    int i=0;
    Pion * cursor = head;
    if (index > 1){
        while(i != index-1 && cursor != NULL){
            cursor=cursor->suivant;
            i++;
        }
        cursor->suivant = cursor->suivant->suivant;
        free(cursor->suivant);        
    } else {
        printf("impossible de supprimer un maillon qui n'est pas entre deux maillon\n");
        exit(EXIT_FAILURE);
    }
}
/**
 * @brief permet d'insérer un maillon entre deux maillons
 * 
 * exemple avec les indexes des maillons :
 * 
 *      0->1->2->3->4->NULL
 *      0   />1->2->3->4->NULL
 *       \ /
 *        1'
 *      0->1->2->3->4->5->NULL
 * 
 * @warning
 *  pas d'insertions "append" c'est a dire que l'on ne peut
 *  pas ajouter de pion a la fin d'une chaine de pion
 *  la fonction n'est pas adaptée pour faire ça
 * 
*/
void insert(Pion * head, Pion * inser, int index){
    int i=0;
    Pion * cursor = head;
    Pion * tmp;
    if (index >= 1){
        while(i != index-1 && cursor != NULL){
            cursor=cursor->suivant;
            i++;
        }     
        if (cursor != NULL){
            inser->suivant = cursor->suivant;
            cursor->suivant = inser;            
        } else {
            printf("\nla longueur de la chaine n'est pas suffisante pour une insertion\n");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("\nimpossible de d'ajouter un maillon qui n'est pas entre deux maillons (nb maillons inférieur a 2)\n");
        exit(EXIT_FAILURE);
    }    

}
/**
 * @brief permet de parcourir la chaine de pions pour placer les coordonnées
 * dans la matrice
*/
void add_path(Pion*head, char**matr){
    Pion*cursor=head;
    // parcours des points
    while(cursor != NULL){
        matr[cursor->line][cursor->column]='5';
        cursor=cursor->suivant;
    }
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
 * les positions de départ sont données en paramètre
 * @param posx coordonnées x du pion
 * @param posy coordonnées y du pion
*/
void forward_right(char ** matr){

    Pion * step_pion=create_Pion(posx, posy, 0); // entete de al chaine des pisotions du pion
    int carry = 1; 

    // position de départ du pion puis des coordonnées
    // au fur et a mesure de l'avancement
    int y;
    int y;
    Pion * head_pion = step_pion;
    int heading; // orientation du pion (1 N, 2 E, 3 S, 4 W)


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
