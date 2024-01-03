#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main() {
    char ** matrice = (char**)malloc(6 * sizeof(char*));

    for (int i=0;i<6;i++){
        matrice[i] = (char*)malloc(5* sizeof(char));
    }
    
    matrice[0][0]= '1';
    matrice[0][1]= '1';
    matrice[0][2]= '3';
    matrice[0][3]= '1';
    matrice[0][4]= '1';

    matrice[1][0]='1';
    matrice[1][1]='1';
    matrice[1][2]='0';
    matrice[1][3]='0';
    matrice[1][4]='1';

    matrice[2][0]='1';
    matrice[2][1]='1';
    matrice[2][2]='1';
    matrice[2][3]='0';
    matrice[2][4]='1';

    matrice[3][0]='1';
    matrice[3][1]='0';
    matrice[3][2]='1';
    matrice[3][3]='0';
    matrice[3][4]='1';

    matrice[4][0]='1';
    matrice[4][1]='0';
    matrice[4][2]='4';
    matrice[4][3]='0';
    matrice[4][4]='1';
    strcpy(matrice[5], "11211");
    

    for (int i=0;i<6;i++){
        for (int j=0;j<5;j++){
            printf("%c", *(*(matrice+i)+j));
        }
        printf("\n"); 
    }
    
        //unique
    for (int i=0;i<6;i++){
        free(matrice[i]);
    }    
    // global
    free(matrice); 
    
}