
// package de librairies extérieures
#include "add_lib.h"

// lisite chainée
typedef struct Etape{
    int line, column;
    struct Etape * suivant;
} Etape ;


/**
 * @brief charger les données du fichier de données avec le labyrinthe
 * @param filename le nom du fichier (le chemin d'accés) pour extraire les données
 * @return la matrice sous forme de string affichable
*/
char ** load(char * filename){
    FILE * file;
    file = fopen(filename, 'r');


    int row_number = 1; // dynamic
    int col_number = 1; // dynamic
    char ** res_matr =  (char**)malloc(col_number * sizeof(char*));

    // parcours du fichier texte
    int i=0;
    int j=0;
    int carry = 1;

    while(carry == 1 && )

}



/**
 * sauvegarde les données d'une ligne 
 *  (séparateur avec \n pour plusieurs lignes)
 * 
 * -ATTENTION : les données sont écrasées a chaque fois
 *  pour permettre de compiler plusieurs fois le même fichier
 *  de la même manière (si le fichier a la même nom)
*/
int sauvegarderDonnees(char*data){
    FILE *fp;
    fp = fopen("out.txt", "w+");
	if(fp == NULL){
        /* File not created hence exit */
        printf("impossible de créer le fichier : (%s)\n", filename);
        exit(EXIT_FAILURE);
    }
    fputs(data, fp);
    fclose(fp);
    return EXIT_SUCCESS;
}


/*
    chercher la sortie en tournant
        - "méthode 1"
    @param depart étape de départ du labyrinthe
*/
void recherche_a_droite(Etape*depart){
    // parcours le bord du labyrinthe pour trouver l'entrée (valeur 3)

}



// end page