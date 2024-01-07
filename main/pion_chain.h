#include "./add_lib.h"
#include "./tools.h"

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
    Pion*temp=head;
    Pion*last=head;
    // et pas temp->null car il manque le dernier
    while(temp != NULL){ 
        last=temp;        
        temp=temp->suivant;
        free(last);
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
    Pion*cursor=head;
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
 * @return renvoie la chaine pour pouvoir faire un free dessus 
 * (sinon la chaine n'est pas visible depuis le programme principale)
*/
Pion*add_path(Pion*head, char**matr){
    Pion*cursor=head;
    // parcours des points
    while(cursor != NULL){
        matr[cursor->line][cursor->column]='5';
        cursor=cursor->suivant;
    }
    return head;
}


/**
 * @brief permet d'avancer un pion en fonction des cases qui sont autour
 * et de l'orientation du pion
 * 
 * rappel : (1 N, 2 E, 3 S, 4 W)
 * 
 * verification des cases vides toujours dans le sens inverse des 
 * aiguilles d'une montre
 * 
 * @param matr la matrice contenant les données
 * @param x la position du pion horizontale
 * @param x la position du pion verticale
 * @param heading l'orientation du pion avant modification par la fonction
 * @param lenx longueur de la matrice en horizontal
 * @param leny largeur de la matrice
 * 
 * @return renvoie le heading mis a jour
*/
int move_Pion_right_heading(char**matr, int x, int y, int heading, int lenx, int leny, int etape, Pion*last){
    int res=heading;
    if (heading == 1){
        // on regarde a l'est et au nord 
        if (y+1<leny&&*(*(matr+x)+y+1)!='1'){
            y++;res=2;
        } else if (x-1>=0&&*(*(matr+x-1)+y)!='1'){
            x--; 
        // on regarde a l'west              
        } else if (y-1>=0&&*(*(matr+x)+y-1)!='1'){
            y--;res=4;             
        // on regarde au sud
        } else if (x+1<lenx&&*(*(matr+x+1)+y)!='1'){
            x++;res=3;                 
        // on est bloqué
        } else {
            printf("\n\non est cerné dans 4 murs a la position (%d,%d) ou alors bloqué autrement!\n\n", x, y);
            exit(EXIT_FAILURE);
        }
        last->suivant=create_Pion(x, y, etape);
        last=last->suivant;            
    } else if (heading == 2){// sens de verification : sud, est, nord west (mêmes if pas dans le même ordre)
        if (x+1<lenx&&*(*(matr+x+1)+y)!='1'){x++;res=3;          
        } else if (y+1<leny&&*(*(matr+x)+y+1)!='1'){y++;
        } else if (x-1>=0&&*(*(matr+x-1)+y)!='1'){x--;res=1;            
        } else if (y-1<leny&&*(*(matr+x)+y-1)!='1'){y--;res=4;           
        } else {
            printf("\n\non est cerné dans 4 murs a la position (%d,%d) ou alors bloqué autrement!\n\n", x, y);
            exit(EXIT_FAILURE);
        }
        last->suivant=create_Pion(x, y, etape);last=last->suivant;
    } else if (heading == 3) {// west sud est nord
        if (y-1<leny&&*(*(matr+x)+y-1)!='1'){y--;res=4;   
        } else if (x+1<lenx&&*(*(matr+x+1)+y)!='1'){x++;        
        } else if (y+1<leny&&*(*(matr+x)+y+1)!='1'){y++;res=2;
        } else if (x-1>=0&&*(*(matr+x-1)+y)!='1'){x--;res=1;            
        } else {
            printf("\n\non est cerné dans 4 murs a la position (%d,%d) ou alors bloqué autrement!\n\n", x, y);
            exit(EXIT_FAILURE);            
        }
        last->suivant=create_Pion(x, y, etape);last=last->suivant;        
    } else if (heading == 4){// sud est nord west
        if (x+1<lenx&&*(*(matr+x+1)+y)!='1'){x++;res=3;     
        } else if (y+1<leny&&*(*(matr+x)+y+1)!='1'){y++;res=2;
        } else if (x-1>=0&&*(*(matr+x-1)+y)!='1'){x--;res=1;            
        } else if (y-1<leny&&*(*(matr+x)+y-1)!='1'){y--;   
        } else{printf("\n\non est cerné dans 4 murs a la position (%d,%d) ou alors bloqué autrement!\n\n", x, y);
            exit(EXIT_FAILURE);              
        }
        last->suivant=create_Pion(x, y, etape);last=last->suivant;        
    } else {// pas possible
        printf("l'orientation donné est impossible (%d)\n", heading);
    }
    return res;
}


/**
 * @brief permet de déplacer le pion dans la matrice en utilisant
 * sa position de départ en longeant le coté droit du mur auquel 
 * il se trouve (priorité au déplacement a droit puis devant etc...)
 * 
 * créer une chaine de pion menant a la sortie
 * 
 * - si le pion revient a une de ses positions précédentes
 *  il y a une erreur (sauf si c'est une impasse)
 * 
 * 3 dirrections possibles 1 pour reculer
 * 
 * les positions de départ sont données en paramètre
 * @param matr la matrice contenant les données
 * @param ex coordonnées x de l'entree
 * @param ey coordonnées y de l'entree
 * @param longx nombre de lignes de la matrice
 * @param longy nombre de colonnes de la matrice
 * 
 * @return renvoie l'entete de la chaine créé (pour la resolution du labyrinthe)
*/
Pion * forward_right(char ** matr, int ex, int ey, int longx, int longy){
    // position de départ du pion puis des coordonnées
    // au fur et a mesure de l'avancement
    int y=0,x=0;
    Pion*head_pion;
    int heading=0; // orientation du pion (1 N, 2 E, 3 S, 4 W)
    int etape=1;  
    // limite le nombrre de déplacement (au cas ou le pion tournerait en rond)
    int maxoccur=longx*longy-get_number_borders(longx, longy)+4;

    // calcul de la position du pion + orientation avec l'entree 
    if (ex == 0){
        heading=3;
        x=ex+1;
    } else if (ex == longx-1){
        heading=1;
        x=longx-2;
    } else {x=ex;}
    if (ey == 0){
        heading=2;
        y=1;
    } else if (ey == longy-1){
        heading=4;
        y=longy-2;
    } else {y=ey;}
    Pion * step_pion=create_Pion(x, y, 0); 
    head_pion=step_pion;// entete de la chaine des pion
    int carry = 1; 

    // on continue tant que l'on trouve pas le point de sortie 
    // (on ne met le dernier pion sur la sortie et on écrase la variable dans la matrice)
    while (carry == 1){
        // en fonction du heading on regarde pas au même endroit
        heading=move_Pion_right_heading(matr, x, y, heading, longx, longy, etape, step_pion);
        etape++;
        maxoccur--;
        // on s'arréte quand on est sur la sortie
        if (matr[x][y] == '3'){
            carry=0;
        }
        if (maxoccur == 0){
            carry=0;
            printf("\nnombre d'iterations maximum dépassées\n\n");
        }

    }
   // free memo
   return head_pion;
}



// end page