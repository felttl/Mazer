#include "add_lib.h"



/**
 *  ┘┌ ┐└ ┴ ┬ ─ ┼ ┤├ | | ○ ⌂
 * 
 *               N
 *          ┌ ──────── ┐
 *          |          |
 *      W   |          |   E 
 *          |          |   
 *          └ ──────── ┘
 *               S
 * règles de base :
 * pas de déplacement en diagonales + les autres règles générales
 * il est impossible de créer une entrée dans les 4 angles du labyrinthe car incohérence de déplacement
 * 
*/


// blocs muraux basiques
char nw = '┌';
char n = '─';
char s = n;
char ne = '┐';
char e = '|';
char w = e;
char sw = '└';
char se = '┘';
// jointures murales
char jn = '┴';
char js = '┬';
char s = '┼'; // star
char je = '├';
char jw = '┤';
// points spécifiques
char nous = '○'; // priorite 2 d'affichage
char entree = '⌂'; // priorite 1 les autres 0

int display(int row, int column, char ** matrice){
    int result=0;
    printf("\n ");

    // affichage des indexes 
    for (int i=0;i<row;i++){
        printf("%d|", i);
    }
    printf("\n");
    // affichage des éléments
    for (int ligne=0;ligne<row;ligne++){
        for (int col=0;col<column;col++){
            // pas de murs
            if (matrice[ligne][col] == ' '){ 
                printf(' ');
            } else { // si on a un mur
                // traitement des cas particuliers
                if (ligne == 0 || ligne == row - 1){
                    // si les 2 points de départ 
                    if (matrice[0][col] == 0){

                    }
                } else if (col == 0){
                    
                } else if (col == column - 1){

                } else {
                    // pas au bord
                }
            }
        }
    }


    printf("\n");
    return result;
}

// bash grey color 840
// \u{001B}[\(iii);\(ii)\(i)m
// \n{001B}[\8;40m

// end page