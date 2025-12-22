#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <conio.h>  // random fuction requirements/librairies nécessaires a random
#include <time.h>
#include <stdbool.h> // lib pour le while

/**
 * renvoie la liste dynamique de caractère trouvé dans le fichier
 * 
 * le dernier caractère est omis (concernant le format de fichier)
*/
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



void main(){
    // le but est d'afficher le nombre de caractère a chaque lignes
    //int a = get_nb_line_file("test.txt");
    char * sortie = (char*) malloc (sizeof(char));
    sortie = "";

    // on fait passer la varaible dans la fonction car allocation dynamique inconnu au début
    sortie = read_file_char_by_char("test.txt");
    printf("%s", sortie);
    printf("\n\nsuccess !\n");

    free(sortie);

}

/*
char ** charger_lab(str nomfichier){
    entier x = 0, y=0, nbchar=10, nbline=5, ataille=1;    
    matrice sortie_donnees = allouer_taille(nbline);
    char c;

    tq(fin du fichier pas fini)faire
        si (ataille == 1)faire // besoin d'espace pour une ligne
            matrice[x] = allouer_taille(nbchar);
            ataille--;
        fin si
        c = nouveau_char_du_fichier(nomfichier);
        si (c == fin_ligne)alors
            // mémoire pille a la bonne taille
            matrice[x] = realloue(get_nbchar(matrice[x]) * taille_char);
            x++;
            y=0;
            nbchar=10;
            ataille++;
        fin si
        matrice[x][y] = c;
        si (longueur(matrice[x]) == nbchar)alors
            nbchar *= 2;
            matrice[x] = realloue_memooire(nbchar);
        fin si
        si (x == nbline)alors// pas suffisament de lignes
            nbline *=2;
            matrice = realloue(nbline);
        fin si
    fin tq
    renvoyer sortie_donnees;
}
*/





// end page