// Online C compiler to run C program online
#include <stdio.h>
#include <time.h>
int main() {
    int nbline = 4;
    int nbcol = 4;
    srand(time(NULL));     // func aleatoire, initialisation 1 fois
    int alea;
    int iny, inx;
    inx = rand() % nbline; // nord est sud west
    if (inx == 0 || inx == nbline-1){
        alea = rand();
        iny = (alea%(nbcol-2))+1;
        printf("inx ==0 || inx == %d, original %d, iny, %d, alea %d \n", nbline-1, inx, iny, alea);
    } else {
        iny = (rand()%2)*(nbcol-1);
    }
    // 3, 2
    for (int i=0;i<nbline;i++){
        for (int j=0;j<nbcol;j++){
            if (i == inx && j == iny){
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
    printf("(x,y) = (%d,%d)\n", inx, iny);
}
/*
on choisi x aleatoire entre 0 et nbx-1 inclus
si x est 0 ou il est nbx-1 alors
	y sera entre 1 et nby-2
sinon
	y sera 0 ou le nby-1
*/
	
//