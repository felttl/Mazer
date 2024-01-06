
// package de librairies extérieures
#include "add_lib.h"

static int lines=0, cols=0;

/**
 * @brief charge les données d'un fichier dans une chaine de caractère
 * QUELQUE SOIT LA TAILLE DE CHAQUE LIGNE 
 *
*/
char * read_file_char_by_char(char * filename){
    // récupération du nb de lignes et colonnes
    // fichier de sortie
    int size = 5;// taille de départ qui sera réajusté
    FILE *fp=fopen(filename,"r");
    char*sortie_donnee=(char*)malloc(size*sizeof(char));
    // transfert d'addresse pour faire un free en dehors
    int count=0;
    if (fp!=NULL){
        while (!feof(fp)){
            // récupère un caractère a la fois
            char c=fgetc(fp);
            //printf("%c", c);                 
            strncat(sortie_donnee,&c,1); // concat un char dans un string
            // si pas assez de place en mémoire alors on double l'espace mémoire utilisable
            if (size<count){
                size=2*count;                
                sortie_donnee=(char*)realloc(sortie_donnee,size*sizeof(char));
            }
            if (sortie_donnee==NULL){// erreur donnnées
                printf("\n\nproblème de création de l'allocation de mémoire ");
                printf("dynamique dans la variable pointeur %c mémoire : %p\n", sortie_donnee[count], sortie_donnee+count);
                exit(EXIT_FAILURE);
            }
            if (c=='\n'){
                lines++;
                if (cols==0){
                    cols=count-2;
                }
            }
            count++;
        }
        // réajuste la taille allouée a la bonne taille (pas de perte de mémoire)
        sortie_donnee=(char*)realloc(sortie_donnee,strlen(sortie_donnee)*sizeof(char));
        sortie_donnee[strlen(sortie_donnee)*sizeof(char)-1]='\0';
        fclose(fp);    
        //printf("%d lignes, %d colonnes\n",++lines,++cols); // affiche le nombre de lignes et colonnes aprés lecture 
    } else {
        printf("\n\nerreur : le fichier '%s'n'existe pas ou n'as pas pu être ouvert\n", filename);
    }

    printf("\n");
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
void save(char**matr, int nbline){
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
        fputs("\n", fp);
    }
    fclose(fp);
}


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
 * 
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
        int cpt = 0;
        unsigned const int lenhozitonal = 2*(nblignes-2);
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




// end page