#include "./add_lib.h"
#include "./tools.h"
#include <math.h>
/**
 * 
 * la ou le pion se déplacera il y aura le numéro 5 sur la grille
 * pour indiquer a la fonction affichage que la case est parcourue par
 * la pion
 * 
 * le pion ne devra que avancer (sauf cas contraire) 
 * 
 * @warning pas besoin d'importer a nouveau tools.h dans les fichier 
 * qui suivent l'importation de pion_chain.h
 * 
 * 
*/


// structure pour déplacement du pion
typedef struct Pion{
    int line;
    int column;
    int num_step;
    struct Pion * suivant;
} Pion ;


/**
 * @brief permet de creer un pion complet (toutes les instanciations)
*/
Pion * create_Pion(int x, int y, int num){
    Pion * res=(Pion*)malloc(sizeof(Pion));
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
void insert(Pion* head, Pion * inser, int index){
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
Pion * add_path(Pion*head, char**matr){
    Pion*cursor=NULL;
    cursor=(Pion*)malloc(sizeof(Pion));
    cursor=head;
    // parcours des points
    while(cursor != NULL){
        // attention il droit y avoir les coordonées correctes
        // sinon problème de mémoire (pas d'erreurs possible puisqe c'est)
        // uniquement certaines fonctions spécifiques qui peuvent faire 
        // l'oppération
        matr[cursor->line][cursor->column]='5';
        cursor=cursor->suivant;
    }
    return head;
}




/**
 * @brief affiche la chaine pion par pion
*/
Pion * display_chain(Pion * head){
    printf("\naffichage de pions : \n");
    Pion*cursor=NULL;
    cursor=(Pion*)malloc(sizeof(Pion));
    cursor=head;
    // parcours des points
    while(cursor != NULL){
        printf("(%d,%d)\n", cursor->line, cursor->column);
        cursor=cursor->suivant;
    }
    printf("\n");
    return head;
}










/**
 * @brief trouve la sortie en utilisant ses coordonnées d'entrée
 * avec l'algorithme de parcours en tournant a droite
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
void forward_right(char***matrix, int ex, int ey, int sx,int sy,int lenx,int leny, int heading){
    printf("%d %d\n", ex, ey);
    // condition d'arret
    if(ex == sx && ey == sy){// on est sur la sortie
        printf("on est sur la sortie:\n");
    // on cherche a savoir si on est dans la matrice
    // car il n'y a pas de raisons d'être en dehors de la matrice
    }else if (ex-1>=0&&ex+1<lenx&&ey+1<leny&&ey-1>=0){// interdiction de toucher un bord
        display((*matrix), lenx, leny);
        if ((*matrix)[ex][ey]=='0') (*matrix)[ex][ey]='5';// on marque le point visité
        // déplacement en fonction du heading
        if (heading==2){// vue west avancer nord
            if ((*matrix)[ex-1][ey]!='1')
                move_to_out(matrix, --ex, ey, sx,sy,lenx,leny, 1);
            else
                move_to_out(matrix, ex, ey, sx,sy,lenx,leny, 0);
        } else if (heading==3){// vue est avancée sud 
            if ((*matrix)[ex+1][ey]!='1')
                move_to_out(matrix, ++ex, ey, sx,sy,lenx,leny, 0);
            else
                move_to_out(matrix, ex, ey, sx,sy,lenx,leny, 1);
        } else if (heading==0){// vue west avancée 
            if ((*matrix)[ex][ey-1]!='1')
                move_to_out(matrix, ex, --ey, sx,sy,lenx,leny, 2);
            else
                move_to_out(matrix, ex, ey, sx,sy,lenx,leny, 3);
        } else if (heading==1){
            if ((*matrix)[ex][ey+1]!='1')
                move_to_out(matrix, ex, ++ey, sx,sy,lenx,leny, 3);
            else
                move_to_out(matrix, ex, ey, sx,sy,lenx,leny, 2);            
        }
    } else {
        printf("erreur \n");
    }
}

/**
 * @brief permet de calculer la distance entre deux points d'une matrice
 * 
 * 
 * @return renvoie la distance entière
*/
int short_vec_point(int currentx,int currenty,int sx,int sy){
    return (int)(abs(currentx-sx)+abs(currenty-sy));
}

/**
 * @brief renvoie l'index d'une liste dont l'élément est le plus élevé
*/
int min(int*list, int size){
    int index=-1;
    if (size > 0){
        index=0;
        for (int i=1;i<size;i++){
            if (list[i] < list[0]){
                index=i;
            }
        }
    } else {
        printf("la taille ne peut pas être 0 !\n");
        exit(EXIT_FAILURE);
    }
    return index;
}

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
Pion*shortest_point_way(char**matrix,int ex,int ey,int sx, int sy, int lenx,int leny){
    int scanx=ex; // position du scanner central
    int scany=ey;
    Pion*head_pion;
    int step=1;

    int maxoccur=lenx*leny-get_number_borders(lenx, leny)+2;// sécurité
    int nsew[4]={0, 0, 0, 0};// nord sud est west
    int togo=0; // récupérer l'index de la direction pour choisir le déplacement
    // déplacement du pion
    if (ex == 0){
        scanx++;
    } else if (ex == lenx-1){
        scanx=lenx-2;
    } else {scanx=ex;}
    if (ey == 0){
        scany++;
    } else if (ey == leny-1){
        scanx=leny-2;
    } else {scany=ey;}
    Pion*etape=create_Pion(scanx, scany, 0);
    head_pion=etape;    
    do {
        // on va a la case la plus proche de la sortie qui n'est pas un mur
        nsew[0] = scanx-1>=0&&matrix[scanx-1][scany]!='1' ? short_vec_point(scanx-1, scany, sx, sy) : lenx+leny+1;
        nsew[1] = scanx+1<lenx-1&&matrix[scanx+1][scany]!='1' ? short_vec_point(scanx+1, scany, sx, sy) : lenx+leny+1;
        nsew[2] = scany-1>=0&&matrix[scanx][scany-1]!='1' ? short_vec_point(scanx, scany-1, sx, sy) : lenx+leny+1;
        nsew[3] = scany+1<leny-1&&matrix[scanx][scany+1]!='1' ? short_vec_point(scanx, scany+1, sx, sy) : lenx+leny+1;
        // permet d'afficher une croix en cas de problèmes de racactères ou d'overflow
        // if(maxoccur==0){
        //     printf("croix : \n %c\n%c", matrix[scanx-1][scany],matrix[scanx+1][scany]);
        //     printf("%c%c\n %c\n",matrix[scanx][scany-1], matrix[scanx][scany-1], matrix[scanx][scany+1]);
        // }
        // on regarde l'index du min pour se déplacer
        togo=min(nsew, 4);
        if (togo==0){
            scanx--; // on va au nord
        } else if (togo==1){
            scanx++; // on va au sud etc...
        } else if (togo==2){
            scany++;
        } else if (togo==3){
            scany--;
        } else {
            printf("erreur: max n'est pas trouvé case : (%d,%d)", scanx, scany);
            exit(EXIT_FAILURE);
        }    
        // en dehors de la matrice pb de caractère
        if ((scanx == 0||scanx==lenx-1||scany==0||scany==leny-1)&&step>2){
            printf("le point est en dehors du labyrinthe il ya  un problème de caractère\n");
            if (maxoccur<4) maxoccur--;
            maxoccur=3;            
        }
        etape->suivant=create_Pion(scanx, scany, step);
        etape=etape->suivant;
        step++;
        maxoccur--;      
    }while (scanx!=sx && scany!=sy && maxoccur!=0 && scanx>=0 && scanx<=lenx && scany>=0 && scany<=leny);
    if (maxoccur == 0){// erreur d'iterations (pb dans la matrice donné en paramètre)
        printf("\nnombre d'iterations dépassée\n");
        // affichange de la liste
        display_chain(head_pion);
    }
    printf("\n");
    return head_pion;
}


// end page