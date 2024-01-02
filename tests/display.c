#include "../add_lib.h"
#include "../display.h"


void main(){
    char model[5][5]={
        "11311",
        "10551",
        "11151",
        "10151",
        "11121"
    };
    char ** matr = (char**)malloc(5 * sizeof(int*));
    for (int i=0;i<5;i++){
        matr[i] = (char*)malloc(5 * sizeof(int));
        for (int y=0;y<5;y++){
            *(*(matr+i)+y) = model[i][y];
        }
    }
    display(5, 5, matr);
}

// end page