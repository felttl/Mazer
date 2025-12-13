#include "add_lib.h"
#include <errno.h>
#include <math.h>

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
 * ┘┌ ┐└ ┴ ┬ ─ ┼ ┤├ | ○ ⌂
 * (13 cas)
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
 * (attention a bien englober les OU quand il y a des ET dans la même expression 
 * (règle de priorité des ET sur le OU)
 * regles :
 * 0 passage
 * 1 mur
 * 2 entree
 * 3 sortie
 * 5 pour le pion (pour affichage successif si on veut voir l'avancée de "l'utilisateur") 
 * @param row nombre de lignes
 * @param column nombre de colonnes
 * @param matrice la matrice d'entrée que l'on doit afficher
 * 
 * @warning lorsqu'un nombre ou symbole est trouvé a la périphérie de de la case
 * "scanné" qui n'est pas valide il y aura des R affichés
 * le programme renverra une erreur s'il tombe sur l'element en question (dans le scanne)
*/
void display(char ** matrice, int row, int column){
    // blocs muraux basiques
    const char nw[4] = "┌";
    const char h[4] = "─"; // horizontal
    const char ne[4] = "┐";
    const char v[4] = "|"; // vertical
    const char sw[4] = "└";
    const char se[4] = "┘";
    // jointures murales
    const char jn[4] = "┴";
    const char js[4] = "┬";
    const char star[4] = "┼"; // star
    const char je[4] = "├";
    const char jw[4] = "┤";
    // points spécifiques
    // const char nous[4] = "○"; // priorite 2 d'affichage
    const char entree[4] = "⌂"; // priorite 1 les autres 0   
    printf("\n  ");
    // // affichage des indexes 
    // for (int i=0;i<column-1;i++){
    //     printf("%d|", i);
    // }
    printf("\n");
    // affichage des éléments
    for (int line=0;line<row;line++){
        printf("%d\t", line);
        for (int col=0;col<column;col++){
            // pas de murs
            if (*(*(matrice+line)+col) == '0'){
                printf("%c", ' ');              
            } else if (*(*(matrice+line)+col) == '1'){ // si on a un mur
                // cas mur vertical (soit haut soit bas soit les deux 
                // (attention aux cases en dehors de la matrice))
                if (((line-1>=0 && matrice[line-1][col]=='1')||(line+1<row&&matrice[line+1][col]=='1'))&& 
                    ((col+1>=column)||(col+1<column&&matrice[line][col+1]!='1'))&&
                    ((col-1<0)||(col-1>=0&&matrice[line][col-1]!='1'))){
                    printf("%s", v);
                // cas mur horizontal
                } else if (((col-1>=0&&matrice[line][col-1]=='1')||(col+1<column&&matrice[line][col+1]=='1'))&&
                            ((line-1<0)||(line-1>=0&&matrice[line-1][col]!='1'))&&
                            ((line+1==row)||(line+1<row&&matrice[line+1][col]!='1'))){
                    printf("%s", h);
                // cas des angles
                } else if ((line+1<row&&matrice[line+1][col])=='1'&&
                           col+1<column&&matrice[line][col+1]=='1'&&
                           ((col-1<0)||(col-1>=0&&matrice[line][col-1]!='1'))&&     
                           ((line-1<0)||(line-1>=0&&matrice[line-1][col]!='1'))){
                    printf("%s", nw);
                } else if (col-1>=0&&matrice[line][col-1]=='1'&&
                           (line+1<row&&matrice[line+1][col])=='1'&&
                           ((col+1>=column)||(col+1<column&&matrice[line][col+1]!='1'))&& // mod
                           ((line-1<0)||(line-1>=0&&matrice[line-1][col]!='1'))){
                    printf("%s", ne);                    
                } else if (col-1>=0&&*(*(matrice+line)+col-1)=='1'&&
                           line-1>=0&&*(*(matrice+line-1)+col)=='1'&&
                           ((line+1>=row)||(line+1<row&&*(*(matrice+line+1)+col)!='1'))&&
                           ((col+1>=column)||(col+1<column&&*(*(matrice+line)+col+1)!='1'))){
                    printf("%s", se);                     
                } else if (col+1<column&&*(*(matrice+line)+col+1)=='1'&&
                           line-1>=0&&*(*(matrice+line-1)+col)=='1'&&
                           ((col-1<0)||(col-1>=0&&*(*(matrice+line)+col-1)!='1'))&&
                           ((line+1>=row)||(line+1<row&&*(*(matrice+line+1)+col)!='1'))){
                    printf("%s", sw);
                // jointure et etoile
                } else if (col+1<column&&*(*(matrice+line)+col+1)=='1'&&
                           ((col-1<0||col-1>=0)&&*(*(matrice+line)+col-1)!='1')&&
                           line-1>=0&&*(*(matrice+line-1)+col)=='1'&&
                           line+1<row&&*(*(matrice+line+1)+col)=='1'){
                    printf("%s", je);
                } else if (((col+1>=column)||(col+1<column&&*(*(matrice+line)+col+1)!='1'))&&
                           col-1>=0&&*(*(matrice+line)+col-1)=='1'&&
                           line-1>=0&&*(*(matrice+line-1)+col)=='1'&&
                           line+1<row&&*(*(matrice+line+1)+col)=='1'){
                    printf("%s", jw);
                } else if (col+1<column&&*(*(matrice+line)+col+1)=='1'&&
                           col-1>=0&&*(*(matrice+line)+col-1)=='1'&&
                           ((line-1<0)||(line-1>=0&&*(*(matrice+line-1)+col)!='1'))&&
                           line+1<row&&*(*(matrice+line+1)+col)=='1'){
                    printf("%s", js);
                } else if (col+1<column&&*(*(matrice+line)+col+1)=='1'&&
                           col-1>=0&&*(*(matrice+line)+col-1)=='1'&&
                           line-1>=0&&*(*(matrice+line-1)+col)=='1'&&
                           ((line+1>=row)||(line+1<row&&*(*(matrice+line+1)+col)!='1'))){
                    printf("%s", jn);
                } else if (col+1<column&&*(*(matrice+line)+col+1)=='1'&&
                           col-1>=0&&*(*(matrice+line)+col-1)=='1'&&
                           line-1>=0&&*(*(matrice+line-1)+col)=='1'&&
                           line+1<row&&*(*(matrice+line+1)+col)=='1'){
                    printf("%s", star);// etoile
                } else {
                    printf("\033[7;31mR\033[0m");// erreur de caractère
                }
            } else if(*(*(matrice+line)+col) == '5'){
                // affichage colorimétrique pour le passage du pion
                printf("\033[7;90m·\033[0m");
            } else if(*(*(matrice+line)+col+1) == '0' && *(*(matrice+line)+col-1) == '0' && *(*(matrice+line+1)+col) == '0' && *(*(matrice+line-1)+col) == '0'){
                // erreur si pas de points a proximité
                printf("affichage impossible au point (%d,%d) pas de points autour", line, col);
                exit(EXIT_FAILURE);
            } else if (*(*(matrice+line)+col) == '2'){// si entrée
                printf("\033[6;92m%s\033[0m", entree);                
            } else if(*(*(matrice+line)+col) == '3'){// si sortie
                printf("%c", ' ');
            } else {// exit error
                printf("\nla valeur de la case (%d,%d) de la matrice n'est pas valide\nchar : (%c)", line, col, *(*(matrice+line)+col));
                exit(EXIT_FAILURE);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// linux bash grey color 840
// \u{001B}[\(iii);\(ii)\(i)m
// \n{001B}[\8;40m




void simple_display(char**matr, int max_row, int max_column){
    for (int line=0;line<max_row;line++){
        printf("%d\t", line);
        for (int col=0;col<max_column;col++){    
            if (matr[line][col] == '1'){
                printf("██");
            } else {
                printf("  ");                
            }
        }
        printf("\n");
    }
}

/**
 * @brief représente les nombres sur plusieurs lignes verticallement
 * exemple (apperçut simplifié) : 
 * 12345678911111111112222222222333333333344444444445...9111111111111111111111
 *          01234567890123456789012345678901234567890...9000000000011111111112
 *                                                       012345678901234567890
 * 
 * formule pour connaitre le nombre de chiffre a afficher verticalement :
 * = (log10(n)+1) (n pour le chiffre à afficher, log10="log en math" car ln=log())
 * 
 * @param number le nombre de colonnes a afficher
 *  
*/
void complex_line_display(int number) {
    if (number <= 0) return;
    int height = (int)log10(number) + 1; // nombre de lignes = nombre de chiffres du plus grand nombre
    int row, j, num_digits, digit;
    for (row = 0; row < height; ++row) {
        for (j = 1; j <= number; ++j) {
            num_digits = (int)log10(j) + 1; // nombre de chiffres du nombre courant
            if (num_digits > row) {
                // on récupère le chiffre correspondant au poids fort de la ligne
                digit = (j / (int)pow(10, num_digits - row - 1)) % 10;
                putchar('0' + digit);
            } else {
                putchar(' '); // pas de chiffre à ce poids
            }
        }
        putchar('\n');
    }
}


// end page