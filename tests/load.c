#include "../add_lib.h"
#include "../display.h"


static int inoutx, inouty;

/**
 * @brief charge les données du fichier txt pour le labyrinthe
 * récupére tous les caractères et les place dans une matrice 2d
*/
char ** load_maze(char * filename){
    // fichier de sortie
    int size = 5; // taille de base
    FILE *fp = fopen(filename,"r");
    // transfert d'addresse pour faire un free en dehors    
    char ** sortie_donnee = (char**) malloc (size * sizeof(char*));
    int x = 0, y = 0, addlloc = 1, nbchar = 10, carry=1;
    char c;
    if (fp != NULL){
        while(!feof(fp) && carry == 1){
            c = fgetc(fp);     
            printf("%c", c);        
            if (c == '\n' || c == '\0'){// si nouvelle ligne on change dans la matrice de ligne
                // on ajuste pour la dernière fois
                // la bonne taille de la mémoire pour cette ligne
                sortie_donnee[x] = (char*)realloc(sortie_donnee[x], strlen(sortie_donnee[x]) * sizeof(char));
                x++;
                nbchar = 10;
                addlloc++;
                if (inouty == 0){
                    inouty=y;                   
                }
                y=0;
                printf("preogmemb here\n");
                c = fgetc(fp);
                printf("is in and next : -%c-", c);                
            }   
                        
            if (addlloc == 1){// si de la mémoire supplémentaire est nécessaire
                sortie_donnee[x] = (char*)malloc(nbchar * sizeof(char));
                addlloc--;
            }    
            if (c != '\n' && c != '\0')         
                *(*(sortie_donnee+x)+y) = c;                               
            // pas assez d'espace dans la ligne actuelle
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
        sortie_donnee[x] = (char*)realloc(sortie_donnee[x], strlen(sortie_donnee[x]) * sizeof(char));    
        inoutx=++x;   
        inouty--; 
    } else {
        printf("\n\nerreur : le fichier '%s'n'existe pas ou n'as pas pu être ouvert\n", filename);
        exit(EXIT_FAILURE);
    }
    return sortie_donnee;
}

//OK
void releaze(char ** matr, int x){
    while (x-- != 0)
        free(matr[x]);
    free(matr);
}

int main(){
    char ** get_data = load_maze("test.txt");
    for (int i=0;i<inoutx;i++){
        for (int j=0;j<inouty;j++){
            printf("%c", *(*(get_data+i)+j));
        }
        printf("\n");
    }
    // printf("\n");
    // display(get_data, inoutx, inouty);


    releaze(get_data, inoutx);
    return 0;
}