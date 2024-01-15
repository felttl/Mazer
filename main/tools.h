// package de librairies extérieures
#include "add_lib.h"





/**
 * @brief permet de récupérer les points qui sont au bords
 * d'une matrice de longueur et largeur définie
 * 
 * attention : la forme de la matrice peut soit être carrée
 * soit rectangulaire sinon la formule ne fonctionne plus
 * 
 * @param nblignes le nombre de lignes de la matrice
 * @param nbcolonnes le nombre de colonnes
 * @return les points qui sont au bords de la matrice
 * dans une liste (sauf les 4 angles) du type 
 * #tools file
 * int *2 var
 * 
 * exemple de la structure des données :
 * {{0, 1}, {0,2}, etc...}
 * 
*/
int ** get_borders(int nblignes, int nbcolonnes){
    // tous les bords sauf les angles
    int ** bords = (int**)malloc((2*(nblignes+nbcolonnes)-8) * sizeof(int*));
    
    // obligation de parcourir uniquement les bords
    // car les autres cases du labyrinthe ne nous servent a rien
    // et ce serait une perte de temps inutile (donc pas de double for)
    // ex matrice de 400 * 300 = 120 000 cases 
    // mais uniquement 2*400 + 2*300 - 8 = 1392 cases nous intéressent
    // les angles nous intéressent pas

    // ligne doit toujours être suppérieur a 2 comme le nb de colonnes
    if (nblignes > 2 && nbcolonnes > 2){
        // ajout des points
        int cpt = 0; // connaitre les coordonnées des points dans la liste "bords"
        unsigned const int lenhozitonal = 2*(nblignes-2); // connaitre le nombre de points horizontaux
        for (int x=1;x<nblignes-1;x++){
            bords[cpt] = (int*)malloc(2*sizeof(int));
            **(bords+cpt) = x;
            *(*(bords+cpt)+1) = 0;
            cpt++;        
            bords[cpt] = (int*)malloc(2*sizeof(int));
            **(bords+cpt) = x;
            *(*(bords+cpt)+1) = nbcolonnes-1;
            cpt++;
        }
        cpt=0;
        for (int y=1;y<nbcolonnes-1;y++){
            bords[cpt+lenhozitonal] = (int*)malloc(2*sizeof(int));
            **(bords+cpt+lenhozitonal) = 0;
            *(*(bords+cpt+lenhozitonal)+1) = y;
            cpt++;
            bords[cpt+lenhozitonal] = (int*)malloc(2*sizeof(int));
            **(bords+cpt+lenhozitonal) = nblignes-1;
            *(*(bords+cpt+lenhozitonal)+1) = y;
            cpt++;
        }
    } else {
        printf("error: le nombre de lignes ou colonnees n'est pas suffisament élevé pour cette fonction\n");
        exit(EXIT_FAILURE);
    } 
    return bords;      
}


/**
 * @brief permet de récupérer le longueur d'un array de points
 * qui se situent sur les bords d'une matrice de taille line col
 * @warning mais n'inclus pas les angles
 * #tools file
 * 
 * @param line nombre de lignes
 * @param col nombre de colonnes
 * @return le nombre déélément dans la liste
*/
int get_number_borders(int line, int col){
    return 2*(line+col-4);
}


/**
 * 
 * @brief récupère les coordonnées de l'entrée et la sortie du mazer 
 * selon leurs caractères passé en paramètres
 * 
 * @param matrix est la matrice d'entrée ou trouver l'entrée et la sortie
 * @param in est le caractère d'entrée
 * @param out est le caractère de sortie
 * @param ex est le paramètre de passage par référence 
 *  pour les coordonnées de sortie en x
 * @param ey '' pour les coordonnées de sortie en y
 * @param sx '' pour les coordonnées de sortie en x
 * @param sy '' pour les coordonnées de sortie en y
 * @param heading orientation (passsage par ref'')
 * 
 * @return renvoie si les coordonées sont trouvées dans le labyrinthe
 * 
*/
void get_mazer_io(char**matrix, char in, char out, int*ex, int*ey, int*sx, int*sy, int*heading_in, int*heading_out){
    // on récupère les données d'initialisation/collect data for init
    int found=0;// pas besoin de continuer le parcours quand on a trouvé les deux coordonnées
    for (int i=0;i<x&&found!=2;i++){
        for (int j=0;j<y&&found!=2;j++){
            if (matrix[i][j] == in){
                *ex=i;
                *ey=j;
                // calcul de l'orientation entrée
                if (*ex == 0){// we are in north
                    *heading_in=1;
                } else if (*ex == x-1){// we are in south
                    *heading_in=0;
                } else if (*ey == 0){// we are in est
                    *heading_in=2;
                } else if (*ey == y-1){// we are in west
                    *heading_in=3;
                }
                found++;
            } else if (matrix[i][j] == out){
                *sx=i;
                *sy=j;  
                // calcul de l'orientation (seulement pour le point d'entrée pas de sortie)
                if (*sx == 0){// we are in north
                    *heading_out=1;
                } else if (*sx == x-1){// we are in south
                    *heading_out=0;
                } else if (*sy == 0){// we are in est
                    *heading_out=2;
                } else if (*sy == y-1){// we are in west
                    *heading_out=3;
                } 
                found++;                             
            }
        }
    }
    // génération de problème de coordonnées si l'entrée ou la 
    // sortie n'est pas présente dans la suite du code
    return found == 2;
}




// end
