#include "../add_lib.h"

int main() {
    int ligne = 4;
    int colonne = 5;
    // tous les angles sauf les bords
    int angles[2*(ligne+colonne)-8][2];
    

    // obligation de parcourir uniquement les bords
    // car les autres cases du labyrinthe ne nou servent a rien
    // et ce serait une perte de temps inutile (donc pas de double for)
    // ex matrice de 400 * 300 = 120 000 cases 
    // mais uniquement 2*400 + 2*300 - 8 = 1392 cases nous intéressent
    // les angles nous intéressent pas

    // ligne doit toujours être suppérieur a 2 comme le nb de colonnes

    // ajout des points
    int cpt = 0;
    unsigned const int lenhozitonal = 2*(ligne-2);
    for (int x=1;x<ligne-1;x++){
        angles[cpt][0] = x;
        angles[cpt][1] = 0;
        cpt++;        
        angles[cpt][0] = x;
        angles[cpt][1] = colonne-1;
        cpt++;
    }
    cpt=0;
    for (int y=1;y<colonne-1;y++){
        angles[cpt+lenhozitonal][0] = 0;
        angles[cpt+lenhozitonal][1] = y;
        cpt++;
        angles[cpt+lenhozitonal][0] = ligne-1;
        angles[cpt+lenhozitonal][1] = y;
        cpt++;
    }
    // test verification
    for (int i=0;i<2*(ligne+colonne)-8;i++){
        printf("%d(%d,%d)\n", i, angles[i][0], angles[i][1]);
    }


    return 0;
}
/**
 * de 1 x a line-2
 * de 1 y a col -2
 * 
 * 
*/

// end page