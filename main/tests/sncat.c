#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
int main() {
    // allocation d'espace
    char ** a = (char**)malloc(5 * sizeof(char*));
    for (int i=0;i<5;i++){
        a[i] = (char*)malloc(5*sizeof(char));
    }
    // chaine
    char * b = (char*)malloc(25*sizeof(char));
    strcpy(b, "abcdefghijklmnopqrstuvwxy");
    
    // remplissage
    for (int x=0;x<5;x++){
        for (int y=0;y<5;y++){
            strncat(a[x], b+5*x+y, 1);
        }
    }
    
    // affichage
    for (int x=0;x<5;x++){
        for (int y=0;y<5;y++){
            printf("%c", *(*(a+x)+y)); 
        }
        printf("\n");
    }
    
    /**
     * permet de vérifier que l'on puisse ajouter une case a un endroit spécifique
     * 
     * -> faire des test avec la chaine b (rajouter les \n et vérifier que la boucle fonctionne
     * puis l'intégrer au fichier load.c)
    */
    
    
    

    return 0;
}