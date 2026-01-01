/* display.c */

// internal librairies
#include "../../../include/ui/term/display.h"
#include "../../../include/utils/time_and_date.h"
// external librairies
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <conio.h>  // random fuction requirements/librairies nécessaires a random
#include <time.h>
#include <stdbool.h> // lib pour le while
#include <errno.h>
#include <math.h>

/**
 * author : felix TTL 
 * date : 24/12/2023 - 7/1/2024
 * update : 21/12/2025
 * project name : Mazer
 * 
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
                } else if (((line+1<row)&&(matrice[line+1][col])=='1')&&
                           col+1<column&&matrice[line][col+1]=='1'&&
                           ((col-1<0)||(col-1>=0&&matrice[line][col-1]!='1'))&&     
                           ((line-1<0)||(line-1>=0&&matrice[line-1][col]!='1'))){
                    printf("%s", nw);
                } else if (col-1>=0&&matrice[line][col-1]=='1'&&
                           ((line+1<row)&&(matrice[line+1][col])=='1')&&
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


void simple_display(char** matr, int max_row, int max_column){
    double start = get_time_sec();
    const char reset[] = "\x1B[0m";
    const char us[7] = "◖◗";//"⊂⊃";//⏴⏵ // display prior 2
    //const char entert[7] = "◀▶";//"◢◣";//◖◗"; // prior 1 others 0
    const char enter[7] = "[]";//◖◗"; // prior 1 others 0
    const char visited[] = "░░"; // background grey nothing else
    const char next[] = "\x1B[1;5;30;44m";// background blue; black bold front
    const char wall[] = "██";
    const char way[] = "\x1B[7;90m██";
    const char out[7] = "[]";
    // 𖨆
    const char bold_g_on_grey_bg[] = "\033[1;32;100m";
    const char bold_r_on_grey_bg[] = "\033[1;33;100m";
    const int bold = 1;
    const int black_bg = 40;
    const int red_fg = 31;
    const int green_fg = 32;
    printf("\033[H"); // cursor top left       
    printf("exit : \033[1;91m%s%s\t pawn:    %s\n", out, reset, us);
    printf("enter : \033[1;92m%s%s\t visited: %s\n", enter, reset, visited);
    printf("exit+pawn : %s%s%s\t wall:    %s\n", bold_r_on_grey_bg, out, reset, wall);
    printf("enter+pawn : %s%s%s\t way:     %s%s\n", bold_g_on_grey_bg, enter, reset, way, reset);
    printf("\n");
 
    for (int line=0;line<max_row;line++){
        printf("%d\t", line);
        for (int col=0;col<max_column;col++){
            if (matr[line][col] == '1'){
                printf("%s", reset);
                printf("%s", wall);                
                printf("%s", reset);
            } else if (matr[line][col] == '0'){
                printf("%s", way);
                printf("%s", reset);    
            } else if (matr[line][col] == '4') {
                printf("%s", us);
                printf("%s", reset);
            } else if (matr[line][col] == '5') { // visited
                printf("%s", way);
                printf("%s", reset);
            } else if (matr[line][col] == '6'){ // us + enter
                printf("%s",bold_g_on_grey_bg);
                printf("%s", enter);
                printf("%s", reset);
            } else if (matr[line][col] == '7') { // us + out
                printf("%s", bold_r_on_grey_bg);
                printf("%s", out);
                printf("%s", reset);
            } else if (matr[line][col] == '2'){
                //printf("\033[1;92m"); // vert + bold sans fond
                printf("\x1B[%d;%d;%dm", bold, green_fg, black_bg); // printf("\x1B[1;32;40m[]\x1B[0m");
                printf("%s", enter);
                printf("%s", reset);
            } else if (matr[line][col] == '3'){
                printf("\033[1;91m"); // rouge + bold sans fond
                printf("%s", out);
                printf("%s", reset);
            } else {
                perror("invalid matrix value");
                exit(EXIT_FAILURE);
            }
        }
        printf("\n");
    }
    printf("simple_display(...) in %.9f seconds\n", get_time_sec() - start);
    fflush(stdout);
}

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