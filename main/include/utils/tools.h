/* tools.h */
#ifndef TOOLS_H
#define TOOLS_H

#include "map.h"
#include <stdbool.h> // bool

/**
 * @brief permet de récupérer les points qui sont au bords
 * d'une matrice de longueur et largeur définie
 * 
 * attention : la forme de la matrice peut soit être carrée
 * soit rectangulaire sinon la formule ne fonctionne plus
 * 
 * @param nblignes le nombre de lignes de la matrice
 * @param nbcolonnes le nombre de colonnes
 * @return les points qui sont au bords de la matrice
 * dans une liste (sauf les 4 angles) du type 
 * #tools file
 * int *2 var
 * 
 * exemple de la structure des données :
 * {{0, 1}, {0,2}, etc...}
 * 
*/
int** get_borders(int nblignes, int nbcolonnes);

/**
 * @brief permet de récupérer le longueur d'un array de points
 * qui se situent sur les bords d'une matrice de taille line col
 * sans inclure les 4 angles
 * @warning mais n'inclus pas les angles
 * #tools file
 * 
 * @param line nombre de lignes
 * @param col nombre de colonnes
 * @return le nombre déélément dans la liste
*/
int get_number_borders(int line, int col);

/**
 * @brief récupère les coordonnées de l'entrée et la sortie du mazer 
 * selon leurs caractères passé en paramètres 
 * 0 nord 1 south 2 west 3 Est
 * 
 * @param matrix est la matrice d'entrée ou trouver l'entrée et la sortie
 * @param in est le caractère d'entrée
 * @param out est le caractère de sortie
 * @param x taile de ma matrice verticale
 * @param y taile de la matrice horizontale
 * @param ex est le paramètre de passage par référence 
 * pour les coordonnées d'entrée en x
 * @param ey '' coordonnées d'entrée en y
 * @param sx '' coordonnées de sortie en x
 * @param sy '' coordonnées de sortie en y
 * @param heading_in orientation de l'entrée (passsage par ref'')
 * @param heading_out orientation de la sortie (passsage par ref'')
 * @return bool : renvoie si les coordonées sont trouvées dans le labyrinthe 
 */
bool get_mazer_io(char** matrix,char in,char out,int x,int y,int* ex, 
 int* ey, int* sx, int* sy, _4d_heading*heading_in, _4d_heading*heading_out);


#endif

// end