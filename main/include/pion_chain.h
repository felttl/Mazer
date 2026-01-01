/* pion_chain.h */
#ifndef PION_CHAIN_H
#define PION_CHAIN_H

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
*/


/**
 * @brief structure pour déplacement du pion
 * @param line int : num position pour la ligne
 * @param column int : num position pour la ligne
 * @param num_step int : numero de l'etape
 * @param suivant Pion* : pointeur vers l'etape suivante
 * @info pn (used in front of functions that use Pion)
 */
typedef struct Pion Pion;
struct Pion {
    int line;
    int column;
    int num_step;
    Pion* suivant;
};


/**
 * @brief permet de creer un pion complet (toutes les instanciations)
*/
Pion * pn_create(int x, int y, int num);

/**
 * libere la mémoire dont l'entete est donné en paramètres
 * 
 * on libere chaque element tant qu'il y en as encore un 
 * mais si l'entete n'est pas suivie de variable alors 
 * on doit la liberer elle
*/
void pn_free_chain(Pion * head);

/**
 * @brief permet de supprimer un maillon de la chaine de pion
 * 
 * ex avec les indexes des maillons:
 * 
 * - 0->1->2->3->4->NULL
 * 
 * - 0->1->2->4->NULL
 * 
*/
void pn_remove_at(Pion * head, int index);

/**
 * @brief
 * 
 * 
 * 

 * 
 * @warning
 *  pas d'insertions "append" c'est a dire que l'on ne peut
 *  pas ajouter de pion a la fin d'une chaine de pion
 *  la fonction n'est pas adaptée pour faire ça
 * 
*/


/**
 * @brief permet d'insérer un maillon entre deux maillons
 * 
 * exemple avec les indexes des maillons :
 * @verbatim
 * 
 *      0->1->2->3->4->NULL
 *      0   />1->2->3->4->NULL
 *       \ /
 *        1'
 *      0->1->2->3->4->5->NULL
 * 
 * @endverbatim
 * 
 * @param head Pion : pion de départ
 * @param inser Pion : pion a insérer
 * @param index int : position de l'insertion
 */
void pn_insert(Pion* head, Pion * inser, int index);

/**
 * @brief permet de parcourir la chaine de pions pour placer les coordonnées
 * dans la matrice
 * @return renvoie la chaine pour pouvoir faire un free dessus 
 * (sinon la chaine n'est pas visible depuis le programme principale)
 * @warning attention sur la gestion des erreurs absentes
*/
Pion * pn_add_path(Pion*head, char**matr);


/**
 * @brief affiche la chaine pion par pion
*/
Pion * pn_display_chain(Pion * head);

/**
 * @brief trouve la sortie en utilisant ses coordonnées d'entrée
 * avec l'algorithme de parcours en tournant a droite dans un labyrinthe
 * 
 * @param matrix la matrice contenant tout les caractères
 * @param ex coordonnées d'entrée en x
 * @param ey coordonnées d'entrée en y 
 * @param sx coordonnées de sortie en x 
 * @param sy coordonnées de sortie en y 
 * on aurait aussi pu donner le caractère qui correspond a la sortie 
 * (qui doit être unique dans le labyrinthe && présent)
 * @param lenx taille verticale de la matrice (attention inversé par rapport aux maths)
 * @param leny taille horizontale de la matrice
 * @param heading est "l'orientation" du pion (pour connaitre la "droite")
 * @note idée/idea: utiliser une structure "Scann" avec 5 
 * points pour voir a chaque étape la progression du parcours du maze
 * @note optimisation: tester de faire passer la variable heading 
 * par référence pour avoir une meilleures vitesse d'exec
 * @note on peut séparer le test d'overflow (lenx leny et ex ey) 
 * (et le faire au début) pour réduire l'impact de toutes les réccursions
 * 
*/
void forward_right(char***matrix, int ex, int ey, int sx,int sy,int lenx,int leny, int heading);

/**
 * @brief permet de calculer la distance entre deux points d'une matrice
 * 
 * @param currentx explicit
 * @param currenty explicit
 * @param sx ?
 * @param sy ?
 * @return int : renvoie la distance entière
 */
int short_vec_point(int currentx,int currenty,int sx,int sy);

/**
 * @brief renvoie l'index d'une liste dont l'élément est le plus élevé
*/
int min(int*list, int size);

/**
 * @brief trouver la sortie en utilisant le point le plus proche
 * 
 * @param ex entrée en x
 * @param ey entrée en y
 * @param sx sortie en x
 * @param sy sortie en y
 * @param lenx longueur de la matrice verticale
 * @param leny longueur de la matrice horizontale
 * @warning l'algorithm n'est pas trés puissant car il ne mémorise pas
 * les points (marquage) qu'il a déja parcouru donc il peut tourner en rond
 * @return le pointeur de la chaine de Point a libérer avec free_pion_chain()
*/
Pion* pn_shortest_way(char**matrix,int ex,int ey,int sx, int sy, int lenx,int leny);

#endif

// end page