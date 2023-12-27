#include "add_lib.h"



/**
 * author : felix TTL 
 * date : 24/12/2023 - 7/1/2024
 * project name : Mazer
 * 
*/




/**
 * @brief fonction d'affichage d'un labyrinthe dont les données soont extraites d'un fichier txt
 * dans lequel les données seront écrites avec des entiers mais extraites sous forme de caractères
 * dans une matrice fournie en paramètre
 * ┘┌ ┐└ ┴ ┬ ─ ┼ ┤├ | | ○ ⌂
 * 
 *              N       
 *         ┌ ──────── ┐
 *         |          |
 *     W   |          |   E 
 *         |          |   
 *         └ ──────── ┘
 *              S
 * règles de base :
 * pas de déplacement en diagonales + les autres règles générales
 * il est impossible de créer une entrée dans les 4 angles du labyrinthe car incohérence de déplacement
 * 
 * regles :
 * 0 passage
 * 1 mur
 * 2 entree
 * 3 sortie
 * 4 pour le pion (pour affichage successif si on veut voir l'avancée de "l'utilisateur") 
 * @param row nombre de lignes
 * @param column nombre de colonnes
 * @param matrice la matrice d'entrée que l'on doit afficher
 * @return la position de l'entrée (coordonnées x et y)
*/
int*display(int row, int column, char ** matrice){
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

    int coorXY[2] = {NULL,NULL}; // input coordinates
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
                } else if (matrice[line][col-1] == '1' && matrice[line][col+1] == '1'){
                    // mur horizontal
                    printf("%c", s);
                } else if (matrice[line][col-1] == '1' && matrice[line][col+1] == '1'){
                    // mur vertical
                    printf("%c", w);
                } else if (){
                    // jointure horizontal droite
                } else if (){
                    // jointure horizontal gauche
                } else if (){
                    // jointure verticale haut
                } else if (){
                    // jointure verticale bas
                } else if (){
                    // quadruple jointure
                } else if(){
                    // erreur si pas de points a priximité
                    printf("affichage impossible au point (%d,%d) pas de points autour", line, col);
                    exit(EXIT_FAILURE);
                }

            }else if (matrice[line][col] == '2'){// si entrée
                coorXY[0] = line;
                coorXY[1] = col;
                // position de la suite de l'entrée (2 cases obligatoires) (3 || 2) && (4 || 0)
                printf("%c", entree);
            }else if (){
            } else {// exit error
                printf("\nla valeur de la case (%d,%d) de la matrice n'est pas valide\n", line, col);
                exit(EXIT_FAILURE);
            }
        }
        printf("\n");
    }


    printf("\n");
    return coorXY;
}

// bash grey color 840
// \u{001B}[\(iii);\(ii)\(i)m
// \n{001B}[\8;40m

// end page