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
 * regles :
 * 0 passage
 * 1 mur
 * 2 entree
 * 3 sortie
 * (pas de 4 pour le pion car on connais déja l'entrée et le 
 * pion commencera toujours par l'entrée)
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
                // traitement des angles (4 angles)
                if (line == 0 && col == 0 || matrice[line][col+1] == '1' && matrice[line+1][col] == '1'){
                    printf("%c", nw);
                } else if (line == 0 && col == column-1 || matrice[line][col-1] == '1' && matrice[line+1][col] == '1'){
                    printf("%c", ne);
                } else if (line == row-1 && col == 0 || matrice[line-1][col] == '1' && matrice[line][col+1] == '1'){
                    printf("%c", sw);                    
                } else if (line == row-1 && col == column-1 || matrice[line][col-1] == '1' && matrice[line-1][col] == '1'){
                    printf("%c", se);
                }

            }else if (matrice[line][col] == '2' || matrice[line][col] == '3'){// si entrée ou sortie
                // position de la suite de l'entrée (2 cases obligatoires) (3 || 2) && (4 || 0)
                // si droite
                if(){

                } else if (){// gauche

                } else if (){// haut

                } else if (){// bas

                } else {// erreur
                    printf("\nla valeur de la case (%d,%d) de la matrice n'est pas valide\n", line, col);
                    exit(EXIT_FAILURE);
                }

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