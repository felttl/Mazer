#include "./generation.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <conio.h>  // random fuction requirements/librairies nécessaires a random
#include <time.h>
#include <stdbool.h> // lib pour le while


int ** generate(int nbline, int nbcol){
    srand(time(NULL));     // func aleatoire, initialisation 1 fois
    int** matrice = (int**)malloc(nbline*sizeof(int*));
    int entree = 3;
    int sortie = 4;

    // entrée et sortie
    int inx;
    int iny;
    int outx = 1;
    int outy = 0;

    // matrice remplie de murs
    if (nbline > 2 || nbcol > 2){
        // 
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
        //affichage de test d'abord (dans le fichier c de test)

        // algorithme DFS pour casser les murs dans la labyrinthe 'vierge'

    } else {
        perror("le nombre de lignes ou colonnes n'est pas suffisant\n");
        exit(EXIT_FAILURE);
    }
    return matrice;
}




// end page