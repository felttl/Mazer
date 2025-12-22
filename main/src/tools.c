/* tools.c */
// package de librairies extérieures
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <conio.h>  // random fuction requirements/librairies nécessaires a random
#include <time.h>
#include <stdbool.h> // lib pour le while


int** get_borders(int nblignes, int nbcolonnes){
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


int get_number_borders(int line, int col){
    return 2*(line+col-4);
}

bool get_mazer_io(char**matrix,char in,char out,int x,int y,int*ex, 
    int*ey, int*sx, int*sy, int*heading_in, int*heading_out){
    // on récupère les données d'initialisation/collect data for init
    int found=0;// pas besoin de continuer le parcours quand on a trouvé les deux coordonnées
    for (int i=0;i<x && found!=2;i++){
        for (int j=0;j<y && found!=2;j++){
            if (matrix[i][j] == in){
                *ex=i;
                *ey=j;
                // calcul de l'orientation entrée
                if (i == 0){// we are in north
                    *heading_in=1;
                } else if (i == x-1){// we are in south
                    *heading_in=0;
                } else if (j == 0){// we are in est
                    *heading_in=2;
                } else if (j == y-1){// we are in west
                    *heading_in=3;
                }
                found++;
            } else if (matrix[i][j] == out){
                *sx=i;
                *sy=j;  
                // calcul de l'orientation (seulement pour le point d'entrée pas de sortie)
                if (i == 0){// we are in north
                    *heading_out=1;
                } else if (i == x-1){// we are in south
                    *heading_out=0;
                } else if (j == 0){// we are in est
                    *heading_out=2;
                } else if (j == y-1){// we are in west
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
