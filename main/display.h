#include "add_lib.h"



/**
 * author : felix TTL 
 * date : 24/12/2023 - 7/1/2024
 * project name : Mazer
 * 
*/








//OK
/**
 * @brief fonction d'affichage d'un labyrinthe dont les données soont extraites d'un fichier txt
 * dans lequel les données seront écrites avec des entiers mais extraites sous forme de caractères
 * dans une matrice fournie en paramètre
 * ┘┌ ┐└ ┴ ┬ ─ ┼ ┤├ | ○ ⌂
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
 * (attention a bien englober les OU quand il y a des ET dans la même expression 
 * (règle de priorité des ET sur le OU)
 * regles :
 * 0 passage
 * 1 mur
 * 2 entree
 * 3 sortie
 * 4 pour le pion (pour affichage successif si on veut voir l'avancée de "l'utilisateur") 
 * 5 couleur grise (passage du pion)
 * @param row nombre de lignes
 * @param column nombre de colonnes
 * @param matrice la matrice d'entrée que l'on doit afficher
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
    // affichage des indexes 
    for (int i=0;i<column;i++){
        printf("%c", i+97);
    }
    printf("\n");
    // affichage des éléments
    for (int line=0;line<row;line++){
        printf("%d ", line);
        for (int col=0;col<column;col++){
            // pas de murs
            if (*(*(matrice+line)+col) == '0'){
                printf("%c", ' ');
            } else if (*(*(matrice+line)+col) == '1'){ // si on a un mur
                // cas mur vertical (soit haut soit bas soit les deux 
                // (attention aux cases en dehors de la matrice))
                if (((line-1>=0 && *(*(matrice+line-1)+col)=='1')||(line+1<row&&*(*(matrice+line+1)+col)=='1'))&& 
                    ((col+1>=column)||(col+1<column&&*(*(matrice+line)+col+1)!='1'))&&
                    ((col-1<0)||(col-1>=0&&*(*(matrice+line)+col-1)!='1'))){
                    printf("%s", v);
                // cas mur horizontal
                } else if (((col-1>=0&&*(*(matrice+line)+col-1)=='1')||(col+1<column&&*(*(matrice+line)+col+1)=='1'))&&
                            ((line-1<0)||(line-1>=0&&*(*(matrice+line-1)+col)!='1'))&&
                            ((line+1>=row||line+1<row)&&*(*(matrice+line+1)+col)!='1')){
                    printf("%s", h);
                // cas des angles
                } else if (line+1<row&&*(*(matrice+line+1)+col)=='1'&&
                           col+1<column&&*(*(matrice+line)+col+1)=='1'&&
                           ((col-1<0)||(col-1>=0&&*(*(matrice+line)+col-1)!='1'))&&     
                           ((line-1<0)||(line-1>=0&&*(*(matrice+line-1)+col)!='1'))){
                    printf("%s", nw);
                } else if (col-1>=0&&*(*(matrice+line)+col-1)=='1'&&
                           line+1<row&&*(*(matrice+line+1)+col)=='1'&&
                           ((col+1>=column||col+1<column)&&*(*(matrice+line)+col+1)!='1')&&
                           ((line-1<0)||(line-1>=0&&*(*(matrice+line-1)+col)!='1'))){
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
                    printf("0");
                }
                
            } else if(*(*(matrice+line)+col) == '5'){
                // affichage colorimétrique pour le passage du pion
                printf("·");
            } else if(*(*(matrice+line)+col+1) == '0' && *(*(matrice+line)+col-1) == '0' && *(*(matrice+line+1)+col) == '0' && *(*(matrice+line-1)+col) == '0'){
                // erreur si pas de points a proximité
                printf("affichage impossible au point (%d,%d) pas de points autour", line, col);
                exit(EXIT_FAILURE);
            }else if (*(*(matrice+line)+col) == '2'){// si entrée
                printf("%s", entree);                
            }else if(*(*(matrice+line)+col) == '3'){
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

// end page