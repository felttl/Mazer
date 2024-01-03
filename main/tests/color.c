#include "../add_lib.h"


void main(){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            printf(" \033[7;%d%dm %d%d\033[0m \n", i, j, i, j);
        }
    }
    printf("\033[7;0m  Oo \033[0m\n");
    
    
}


// 740

// end page