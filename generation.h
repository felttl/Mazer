#include "add_lib.h"


/**
 * 

*/

/**
 * @brief fonction pour générer un labyrinthe aléatoirement avec DFS
 * la fonction renvoie la matrice (dynamique)
 * 
 * @warning ATTENTION :
 * - il ne doit pas y avoir l'entrée et la sortie trop près
 * - il faut calculer la direction au départ parmis les 4 possibilités
 * - il ne doit pas y avoir de blocage (on doit toujours pouvoir atteindre la sortie)
 * - lors d'un passsage les configurations ou les angles des murs manquantes ne sont pas 
 * autorisés (tous les angles doivent être présents) exemple :
 * 
 * 010                                                 111
 * 101 est considérer comme une impasse incorrecte     101
 * 101  le chemin est correct a droite                 101
 * 
 * fonctionnalité : 
 * - pouvoir avoir des murs qui ne forment pas des cercles (perte de cases a l'intérieur d'un bloc)
 * exemple :
 * []  |____.
 * __  |____|
 * 
 * 
 * @example de structure de la matrice labyrinthe (tous sont des 
 * chiffres écrits dans un fichier et extraits sous forme de caractères)
 * [[a, b, c],
 *  [d, e, f],
 *  [g, h, i]]
 * 
*/

int ** generate(int nbline, int nbcol){
    srand(time(NULL));     // func aleatoire, initialisation 1 fois
    int ** matrice = (int**)malloc(nbline*sizeof(int*));
    int entree = 3;
    int sortie = 4;
    int alea;

    // matrice remplie de murs
    if (nbline > 2 || nbcol > 2){
        for (int x=0;x<nbline;x++){
            matrice[x] = (int*)malloc(nbcol*sizeof(int));
            for (int y=0;y<nbcol;y++){    
                *(*(matrice+nbline)+nbcol) = 1;

            }        
        }
        // placement entrée sortie
        alea = rand();


        // algorithme DFS pour casser les murs dans la labyrinthe 'vierge'

    } else {
        printf("le nombre de lignes ou colonnes n'est pas suffisant\n");
        exit(EXIT_FAILURE);
    }



    


    // contenu
    for (int x=0;x<nbline;x++){
        for (int y=0;y<nbcol;y++){
            if 
        }
    }

    return matrice;
}

int verifierMatr(int ** matrice){
    int res = 1;

    // prog principal


    return res;
}



// end page