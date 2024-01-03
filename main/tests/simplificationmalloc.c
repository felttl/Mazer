#include "../add_lib.h"

void main() {
    int ** a = (int**)malloc(4*sizeof(int*));
    // insert
    int c=21;
    for (int x=0;x<4;x++){    
        a[x] = (int*)malloc(5*sizeof(int));
        for (int y=0;y<5;y++){
            a[x][y] = c;
            c--;
        }
    }
    // display
    for (int x=0;x<4;x++){
        for (int y=0;y<5;y++){
            printf("%d ", *(*(a+x)+y));
        }
        printf("\n");
    }
    // test de simplification d'écriture
    printf("un veut la coordonné (1,0)(simplifié) : %d\n", **(a+1));//////////////
    printf("un veut la coordonné (1,0)(non direct) : %d\n", *(*(a+1)+0));
    printf("un veut la coordonné (0,2)(non direct) : %d\n", *(*(a+0)+2));
    printf("un veut la coordonné (0,2)(non direct) : %d\n", *(*a+2));/////////////

    // release
    for (int x=0;x<4;x++){    
        free(a[x]);
    }   
    free(a);


}