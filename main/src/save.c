/* save.c */
// internal librairies
#include "../include/save.h"
// external librairies
#include <string.h>
#include <stdio.h>
#include <stdlib.h> // import EXIT_FAILURE

void save_matr(char**matr, int nbline){
    FILE *fp;
    fp = fopen("out.txt", "w+");
	if(fp == NULL){
        /* File not created hence exit */
        printf("impossible de créer le fichier : (%s)\n", "out.txt");
        exit(EXIT_FAILURE);
    }
    // pour chaque ligne
    for (int i=0;i<nbline;i++){
        fputs(matr[i], fp);
    }
    fclose(fp);
}
