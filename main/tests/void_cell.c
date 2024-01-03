// Online C compiler to run C program online
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <conio.h>  // random fuction requirements/librairies nécessaires a random
#include <time.h>

/*
on cherche a tester que'qu'il y a en dehors des matrices
quel affichage on va obtenir

*/

int main() {
    srand(time(NULL));     // initialisation 1 fois
    int alea = rand() % 10000;
    
    // on fait des tests que sur la première ligne
    int ** ielem = (int**)malloc(5 * sizeof(int*));
    ielem[0] = (int*)malloc(5*sizeof(int));
    int ieelem[5][5];
    char ** celem = (char**)malloc(5 * sizeof(char*));
    celem[0] = (char*)malloc(5*sizeof(char));
    char ceelem[5][5];
    char insert[5]="adehg";
    // insertions
    for (int i=0;i<4;i++){ // on met des éléments a toutes les cases sauf la dernière
        // int
        ielem[0][i] = alea;
        ieelem[0][i] = ++alea;
        // char
        celem[0][i] = insert[i];
        ceelem[0][i] = insert[i];
        // reset random
        alea = rand() % 10000;
    }
    // affichage du test (verif case vide)
    if (ielem[0][-1] == '\0'){
        printf("ielem O -1 is escape sequence (%c)\n", ielem[0][-1]);
    }
    if (ieelem[0][-1] == NULL){
        printf("ielem O -1 is null (%c)\n", ielem[0][-1]);
    }
    if (NULL == '\0'){
        printf("null and escape are same!\n");
    }
    /*
    for (int i=-1;i<5;i++){
        printf("int malloc[O][%d] = %d", i, ielem[O][i]);
        printf("int tab[O][%d] = %d", i, ieelem[O][i]);
        printf("char malloc[O][%d] = %d", i, celem[O][i]);
        printf("char tab[O][%d] = %d", i, ceelem[O][i]);
        // end 
        printf("\n");
        
    } 
    */






    return 0;
}



// end page