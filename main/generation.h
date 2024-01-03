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

    // entrée et sortie
    int inx;
    int iny;
    int outx = 1;
    int outy = 0;

    // matrice remplie de murs
    if (nbline > 2 || nbcol > 2){
        for (int x=0;x<nbline;x++){
            matrice[x] = (int*)malloc(nbcol*sizeof(int));
            for (int y=0;y<nbcol;y++) *(*(matrice+nbline)+nbcol) = 1;     
        }
        // placement entrée sortie
        inx = rand() % nbline; // nord est sud west
        if (inx == 0 || inx == nbline-1){
            iny = (rand()%(nbcol-2))+1;
        } else {
            iny = (rand()%2)*(nbcol-1);
        }
        // on vérifie que l'entrée ne soit pas trop près
        // de la sortie dans l'insertion suivante
        do{
            outx = rand() % nbline; // nord est sud west
            if (outx == 0 || outx == nbline-1){
                outy = (rand()%(nbcol-2))+1;
            } else {
                outy = (rand()%2)*(nbcol-1);
            }            
        } while (!(outx == inx || outy == iny));
        // algorithme DFS pour casser les murs dans la labyrinthe 'vierge'


    } else {
        printf("le nombre de lignes ou colonnes n'est pas suffisant\n");
        exit(EXIT_FAILURE);
    }
    return matrice;
}

int verifierMatr(int ** matrice){
    int res = 1;

    // prog principal


    return res;
}



// end page