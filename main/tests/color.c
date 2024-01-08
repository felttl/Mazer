#include "../add_lib.h"

#include <math.h>

void color(){

    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            for (int k=0;k<10;k++){
                printf(" \033[%d;%d%dm%d%d%d \033[0m %d%d%d", i,j,k, i,j,k, i,j,k);
            }
            printf("\n"); 
        }
       
    }    
}

int main(){
    color();
    return 0;
}


// 740

// end page