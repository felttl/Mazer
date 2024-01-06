#include "../add_lib.h"
#include "../display.h"




// /**
//  * @brief charge les données du fichier txt pour le labyrinthe
//  * récupére tous les caractères et les place dans une matrice 2d
// */
// char ** load_maze(char * filename){
//     // fichier de sortie
//     int size = 5; // taille de base
//     FILE *fp = fopen(filename,"r");
//     // transfert d'addresse pour faire un free en dehors    
//     char ** sortie_donnee = (char**) malloc (size * sizeof(char*));
//     int x = 0, y = 0, addlloc = 1, nbchar = 10, carry=1;
//     char c;
//     if (fp != NULL){
//         while(!feof(fp)){
//             c = fgetc(fp);     
//             printf("%c", c);        
//             if (c == '\n'){// si nouvelle ligne on change dans la matrice de ligne
//                 // on ajuste pour la dernière fois
//                 // la bonne taille de la mémoire pour cette ligne
//                 sortie_donnee[x] = (char*)realloc(sortie_donnee[x], strlen(sortie_donnee[x]) * sizeof(char));
//                 x++;
//                 nbchar = 10;

//                 if (inouty == 0){
//                     inouty=y;                   
//                 }
//                 y=0;
//                 printf("preogmemb here\n");
//                 c = fgetc(fp);
//                 printf("is in and next : -%c-", c);  
//                 // mémoire de base ("ligne suivante")
//                 sortie_donnee[x] = (char*)malloc(nbchar * sizeof(char));              
//             }    
//             *(*(sortie_donnee+x)+y) = c;                                        
//             // pas assez d'espace dans la ligne actuelle
//             if (strlen(sortie_donnee[x]) == nbchar){
//                 nbchar *= 2;
//                 sortie_donnee[x] = (char*)realloc(sortie_donnee, nbchar*sizeof(char));
//             }  
//             if (x == size){// pas assez de place pour les lignes et colonnes
//                 size *= 2; 
//                 sortie_donnee = (char**)realloc(sortie_donnee, size*sizeof(char*));
//             }
//             y++;
//         }
//         // on peut réajuster définitivement la taille de la matrice
//         // pour que le plus de mémoire soit libérée
//         sortie_donnee[x] = (char*)realloc(sortie_donnee[x], strlen(sortie_donnee[x]) * sizeof(char));    
//         inoutx=++x;   
//         inouty--; 
//     } else {
//         printf("\n\nerreur : le fichier '%s'n'existe pas ou n'as pas pu être ouvert\n", filename);
//         exit(EXIT_FAILURE);
//     }
//     return sortie_donnee;
// }

static int lines=0, cols=0;
char * read_file_char_by_char(char * filename){
    // fichier de sortie
    int size = 5;
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
                sortie_donnee=(char*)realloc(sortie_donnee,2*count*sizeof(char));
                size=2*count;
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
        printf("%d lignes, %d colonnes\n",++lines,++cols); // affiche le nombre de lignes et colonnes aprés lecture 
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

int main(){ // gdb debugger

    // récupère la chaine de données
    char * get_datas = read_file_char_by_char("test.txt");
    // convertit la chaine de char en matrice de char
    char ** get_data;
    // allocation d'espace
    get_data = (char**)malloc(lines * sizeof(char*));
    for (int i=0;i<cols;i++)get_data[i]=(char*)malloc(cols * sizeof(char));

    printf("extracted data:\n\n%s\n\n", get_datas);

    int x=0, y=0;

    for (int i=0;i<strlen(get_datas);i++){

        if (get_datas[i] == '\n'){// changement de ligne   
            // fin de string
            get_data[x][y]='\0';      
            x++;
            y=0;
        } else {
            // récupération du caractère et mise dans la matrice
            get_data[x][y] = get_datas[i]; // concat un char dans un string
            y++;            
        }

    }
    // fermeture de pointeur
    *(*(get_data+x)+y) = '\0';

    printf("loop extracted data:\n\n");
    // affichage simple
    for (int i=0;i<strlen(get_datas);i++){
            printf("%c", *(get_datas+i));
    } 

    printf("\n\nour formatted data:\n\n");
    // affichage simple
    for (int i=0;i<lines;i++){
        for (int j=0;j<cols;j++){
            printf("%c", *(*(get_data+i)+j));
        }
        printf("\n");
    }  
    printf("\nnumeric display:\n\n");
    for (int i=0;i<lines;i++){
        for (int j=0;j<cols;j++){
            printf("%d ", *(*(get_data+i)+j));
        }
        printf("\n");        
    }    
    printf("\n\nlinear own display(char by char):\n\n");
    for (int i=0;i<lines;i++){
        for (int j=0;j<cols;j++){
            printf("%c", *(*(get_data+i)+j));
        }
        printf("\n");
    }    
    printf("\n\nlinear own display(str by str):\n\n");
    for (int i=0;i<lines;i++){
        printf("%s", get_data[i]);
        printf("\n");
    }   
    printf("\n");
    display(get_data, lines, cols);

    free(get_datas);
    releaze(get_data, lines);
    return 0;
}