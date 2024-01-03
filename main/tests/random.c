#include "../add_lib.h"
// compilation : sh ../*bash ./random.c







void main(){
    srand(time(NULL));     // initialisation 1 fois
    int alea = rand();

    printf("%d\n", alea);
    alea = rand();

    printf("%d\n", alea);
    
}




// end page
