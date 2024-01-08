#include "./add_lib.h"
/**
 * @brief sauvegarde les données d'une ligne 
 *  (séparateur avec \n pour plusieurs lignes)
 * #tools file
 * 
 *  -   ATTENTION : les données sont écrasées a chaque fois
 *  pour permettre de compiler plusieurs fois le même fichier
 *  de la même manière (si le fichier a la même nom)
 *  mais n'as pas forcément le même contenu dans le fichier d'entree
 * et de sortie
 * 
*/
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
