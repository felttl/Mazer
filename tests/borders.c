#include "../matr_utils.h"


int ** get_borders(int nblignes, int nbcolonnes);


void main() {

    int line, col;

    printf("entrer le nombre de lignes :\t");
    scanf("%d", &line);
    printf("entrer le nombre de colonnes :\t");
    scanf("%d", &col);

    int ** res;
    res = get_borders(line, col);
    // test verification
    for (int i=0;i<2*(line+col)-8;i++){
        printf("%d(%d,%d)\n", i, **(res+i), *(*(res+i)+1));
    }

    //free
    for (int i=0;i<2*(line+col)-8;i++){
        free(res[i]);
    }
    free(res);


}
/**
 * de 1 x a line-2
 * de 1 y a col -2
 * 
 * 
*/




// end page