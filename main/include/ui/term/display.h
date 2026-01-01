/*display.h*/
#ifndef DISPLAY_H
#define DISPLAY_H
/**
 * author : felix TTL 
 * date : 24/12/2023 - 7/1/2024
 * update : 21/12/2025
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
 * (attention a bien englober les OU quand il y a des ET dans la même expression)
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
void display(char ** matrice, int row, int column);
/**
 * affichage uniligne
 */
void simple_display(char**matr, int max_row, int max_column);

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
void complex_line_display(int number);

#endif

// end page