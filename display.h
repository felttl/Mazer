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
 * 5 couleur grise (passage du pion)
 * @param row nombre de lignes
 * @param column nombre de colonnes
 * @param matrice la matrice d'entrée que l'on doit afficher
 * @return la position de l'entrée (coordonnées x et y)
*/
void display(int row, int column, char ** matrice){
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
    for (int i=0;i<row;i++){
        printf("%d", i);
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

                if (col-1 >= 0 && col+1 <= column-1 && *(*(matrice+line)+col-1)-'0'>0 && *(*(matrice+line)+col-1)-'0'<4&&*(*(matrice+line)+col+1)-'0'>0&&*(*(matrice+line)+col+1)-'0'<4){
                    // jointure nord ou sud
                    if (line-1 >= 0 && *(*(matrice+line-1)+col)-'0'>0 && *(*(matrice+line-1)+col)-'0'<4){// nord
                        printf("%s", jn);// jointure horizontale nord  
                    } else if (line+1 < row && *(*(matrice+line+1)+col)-'0'>0 && *(*(matrice+line+1)+col)-'0'<4){//sud
                        printf("%s", js);// jointure horizontale sud; 
                    }else {// pas de jointure just horizontal
                        printf("%s", h);
                    }
                } else if (line-1 >= 0 && line+1 < row && *(*(matrice+line-1)+col)-'0'>0&&*(*(matrice+line-1)+col)-'0'<4 && *(*(matrice+line+1)+col)-'0'>0&&*(*(matrice+line+1)+col)-'0'<4){
                    // jointure est ou west
                    if (col+1 < column && *(*(matrice+line)+col+1)-'0'>0 && *(*(matrice+line)+col+1)-'0'<4){// est
                        // star
                        if(col-1 >= 0 && *(*(matrice+line)+col-1)-'0'>0 && *(*(matrice+line)+col-1)-'0'<4){
                            printf("%s", star);// quadruple jointure 
                        } else {
                            printf("%s", je);// jointure verticale est 
                        }
                    } else if (col-1 >= 0 && *(*(matrice+line)+col-1)-'0'>0 && *(*(matrice+line)+col-1)-'0'<4){// west
                        printf("%s", jw);// jointure verticale west  
                    } else {// simple mur vertical
                        printf("%s", v);// mur vertical
                    } 
                // test pour les 4 angles
                } else if (line+1 <= row-1 && col+1 < column && *(*(matrice+line)+col+1)-'0'>0 && *(*(matrice+line)+col+1)-'0'<4 && *(*(matrice+line+1)+col)-'0' > 0 && *(*(matrice+line+1)+col)-'0' < 4 ){
                    printf("%s", nw);
                } else if (line-1 >= 0 && col+1 < column && *(*(matrice+line-1)+col)-'0' > 0 && *(*(matrice+line-1)+col)-'0' < 4 && *(*(matrice+line)+col+1)-'0' > 0 && *(*(matrice+line)+col+1)-'0' < 4){
                    printf("%s", sw); 
                } else if (line+1<row && col-1 >= 0 && *(*(matrice+line+1)+col)-'0' > 0 && *(*(matrice+line+1)+col)-'0' < 4 && *(*(matrice+line)+col-1)-'0' > 0 && *(*(matrice+line)+col-1)-'0' < 4 ){
                    printf("%s", ne); 
                } else if (line-1 >= 0 && col-1 >= 0 && *(*(matrice+line)+col-1)-'0' > 0 && *(*(matrice+line)+col-1)-'0' < 4 && *(*(matrice+line-1)+col)-'0' > 0 && *(*(matrice+line-1)+col)-'0' < 4){
                    printf("%s", se);                   
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
                printf("\nla valeur de la case (%d,%d) de la matrice n'est pas valide\n", line, col);
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