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
        while(!feof(fp)){
            c = fgetc(fp);     
            printf("%c", c);        
            if (c == '\n'){// si nouvelle ligne on change dans la matrice de ligne
                // on ajuste pour la dernière fois
                // la bonne taille de la mémoire pour cette ligne
                sortie_donnee[x] = (char*)realloc(sortie_donnee[x], strlen(sortie_donnee[x]) * sizeof(char));
                x++;
                nbchar = 10;

                if (inouty == 0){
                    inouty=y;                   
                }
                y=0;
                printf("preogmemb here\n");
                c = fgetc(fp);
                printf("is in and next : -%c-", c);  
                // mémoire de base ("ligne suivante")
                sortie_donnee[x] = (char*)malloc(nbchar * sizeof(char));              
            }    
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

char * read_file_char_by_char(char * filename){
    // fichier de sortie
    int size = 5;
    FILE *fp = fopen(filename,"r");
    char * sortie_donnee = (char*) malloc (size * sizeof(char));
    // transfert d'addresse pour faire un free en dehors
    int count = 0;
    int done = 0;
    int nblignes=0;
    if (fp != NULL){
        while (!feof(fp)){
            // récupère un caractère a la fois
            char c = fgetc(fp);
            //printf("%c", c);                 
            strncat(sortie_donnee, &c, 1); // concat un char dans un string
            // si pas assez de place en mémoire alors on double l'espace mémoire utilisable
            if (size < count){
                sortie_donnee = (char*) realloc (sortie_donnee, 2 * count * sizeof(char));
                size = 2 * count;
            }
            if (sortie_donnee == NULL){// erreur donnnées
                printf("\n\nproblème de création de l'allocation de mémoire ");
                printf("dynamique dans la variable pointeur %s mémoire : %x\n", sortie_donnee, &sortie_donnee);
                exit(EXIT_FAILURE);
            }
            if (c == '\n'){nblignes++;}
            count++;
        }
        // réajuste la taille allouée a la bonne taille (pas de perte de mémoire)
        sortie_donnee = (char*) realloc (sortie_donnee, strlen(sortie_donnee) * sizeof(char));
        sortie_donnee[strlen(sortie_donnee) * sizeof(char) - 1] = '\0';
        fclose(fp);    
        printf("nombre de lignes : %d\n", ++nblignes);            
    } else {
        printf("\n\nerreur : le fichier '%s'n'existe pas ou n'as pas pu être ouvert\n", filename);
    }

    printf("\n");
    return sortie_donnee;
}

//OK
void releaze(char ** matr, int x){
    while (x-- != 0)
        free(matr[x]);
    free(matr);
}

int main(){

    // récupère la chaine de données
    char * get_datas = read_file_char_by_char("test.txt");
    // convertit la chaine de char en matrice de char
    char ** get_data;

    int x=0, y=0;
    for (int i=0;i<strlen(get_datas);i++){
        if (*(get_datas) == '\n'){// changement de ligne
            x++;
            y=0
        } else if (*(get_datas) == '\0'){// fin de fichier

        } else {
            
        }
        y++;
    }



    
    // affichage simple
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