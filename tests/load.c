#include "../add_lib.h"
#include "../display.h"

/**
 * @brief charge les données du fichier txt pour le labyrinthe
 * récupére tous les caractères et les place dans une matrice 2d
*/
char ** load_maze(char * filename, int inoutx, int inouty){
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
                addlloc--;
            }
            c = fgetc(fp);
            if (c == '\n'){// si nouvelle ligne on change dans la matrice de ligne
                // on ajuste pour la dernière fois
                // a la bonne taille la mémoire pour cette ligne
                sortie_donnee[x] = (char*)realloc(sortie_donnee[x], strlen(sortie_donnee[x]) * sizeof(char));
                sortie_donnee[strlen(sortie_donnee[x])*sizeof(char)-1]='\0';
                x++;
                nbchar = 10;
                addlloc++;
                inouty=y;
                y=0;
            }
            *(*(sortie_donnee+x)+y) = c;            
            // pas assez d'espace
            if (strlen(sortie_donnee[x]) == nbchar){
                nbchar *= 2;
                sortie_donnee[x] = (char*)realloc(sortie_donnee, nbchar*sizeof(char));
            }
            if (x == size){// pas assez de place pour les lignes et colonnes
                size *= 2;
                sortie_donnee = (char**)realloc(sortie_donnee, size*sizeof(char*));
            }
            y++;
        }
        // on peut réajuster définitivement la taille de la matrice
        // pour que le plus de mémoire soit libérée
        sortie_donnee = (char**)realloc(sortie_donnee, ++x*sizeof(char*));
    } else {
        printf("\n\nerreur : le fichier '%s'n'existe pas ou n'as pas pu être ouvert\n", filename);
    }
    inoutx=x;
    inouty=y;
    return sortie_donnee;
}

//OK
void releaze(char ** matr, int x){
    while (x-- != 0)
        free(matr[x]);
    free(matr);
}

void main(){
    int xa=0, ya=0;
    char ** get_data = load_maze("test.txt", xa, ya);
    display(xa, ya, get_data);


    releaze(get_data, xa);
}