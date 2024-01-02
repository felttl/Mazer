
// package de librairies extérieures
#include "add_lib.h"





/**
 * @brief charge les données du fichier txt pour le labyrinthe
*/
char ** load_maze(char * filename){
    // fichier de sortie
    int size = 5; // taille de base
    FILE *fp = fopen(filename,"r");
    // transfert d'addresse pour faire un free en dehors    
    char ** sortie_donnee = (char**) malloc (size * sizeof(char*));
    int x = 0, y = 0, addlloc = 1, nbchar = 10;
    char c;
    if (fp != NULL){
        while(!feof(fp)){
            if (addlloc == 1){// si de la mémoire supplémentaire est nécessaire
                sortie_donnee[x] = (char*)malloc(nbchar * sizeof(char));
                sortie_donnee[strlen(sortie_donnee)*sizeof(char)-1]='\0';
                addlloc--;
            }
            c = fgetc(fp);
            if (c == '\n'){// si nouvelle ligne on change dans la matrice de ligne
                // on ajuste pour la dernière fois
                // a la bonne taille la mémoire pour cette ligne
                sortie_donnee[x] = (char*)realloc(sortie_donnee[x], strlen(sortie_donnee[x] * sizeof(char)))
                x++;
                nbchar = 10;
                addlloc++;
                y=0;
            }
            *(*(sortie_donnee+x)+y) = c;            
            // pas assez d'espace
            if (strlen(sortie_donnee[x]) == nbchar){
                nbchar *= 2;
                sortie_donnee[x] = (char*)realloc(sortie_donnee, nbchar*sizeof(char));
            }
            if (x == nbline){// pas assez de place pour les lignes et colonnes
                nbline *=2;
                sortie_donnee = (char**)realloc(sortie_donnee, nbline*sizeof(char*));
            }
            y++;
        }
        // on peut réajuster définitivement la taille de la matrice
        // pour que le plus de mémoire soit libérée
        sortie_donnee = (char**)realloc(sortie_donnee, ++x*sizeof(char*));
    }

    return sortie_donnee;
}



/**
 * @brief sauvegarde les données d'une ligne 
 *  (séparateur avec \n pour plusieurs lignes)
 * 
 * 
 *  -   ATTENTION : les données sont écrasées a chaque fois
 *  pour permettre de compiler plusieurs fois le même fichier
 *  de la même manière (si le fichier a la même nom)
 *  mais n'as pas forcément le même contenu dans le fichier d'entree
 * et de sortie
 * 
*/
void save(char*data){
    FILE *fp;
    fp = fopen("out.txt", "w+");
	if(fp == NULL){
        /* File not created hence exit */
        printf("impossible de créer le fichier : (%s)\n", filename);
        exit(EXIT_FAILURE);
    }
    fputs(data, fp);
    fclose(fp);
}






// end page