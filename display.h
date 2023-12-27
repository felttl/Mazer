#include "add_lib.h"



/**
 * author : felix TTL 
 * date : 24/12/2023 - 7/1/2024
 * project name : Mazer
 * 
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
    printf("\n\n ");

    // affichage des indexes 
    for (int i=0;i<row;i++){
        printf("%d|", i);
    }
    printf("\n");
    // affichage des éléments
    for (int line=0;line<row;line++){
        printf("%d ", line);
        for (int col=0;col<column;col++){
            // pas de murs
            if (matrice[line][col] == '0'){ 
                printf(' ');
            } else if (matrice[line][col] == '1'){ // si on a un mur
                // traitement des cas particuliers
                if (line == 0){
                    // horizontal nord
                    if (col == 0){
                        printf('%c', nw);
                    } else if (col == column-1){
                        printf('%c', ne);
                    } else {
                        printf('%c', n);
                    }
                } else if (line == row-1){
                    // horizontal sud
                    if ()
                    
                } else if (col == column - 1){

                } else {
                    // pas au bord
                }
            }else if (matrice[line][col] == '2' || matrice[line][col] == '3'){// si entrée ou sortie

            } else {// exit error
                printf("\nla valeur de la case (%d,%d) de la matrice n'est pas valide\n", line, col);
                exit(EXIT_FAILURE);
            }
        }
        printf("\n");
    }


    printf("\n");
    return result;
}

// bash grey color 840
// \u{001B}[\(iii);\(ii)\(i)m
// \n{001B}[\8;40m

// end page