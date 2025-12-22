/* tools.h */
#ifndef TOOLS_H
#define TOOLS_H
#include <stdbool.h>

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
 * 
 * @brief récupère les coordonnées de l'entrée et la sortie du mazer 
 * selon leurs caractères passé en paramètres 
 * 0 nord 1 south 2 west 3 Est
 * 
 * @param matrix est la matrice d'entrée ou trouver l'entrée et la sortie
 * @param x taile de ma matrice verticale
 * @param y taile de la matrice horizontale
 * @param in est le caractère d'entrée
 * @param out est le caractère de sortie
 * @param ex est le paramètre de passage par référence 
 *  pour les coordonnées de sortie en x
 * @param ey '' pour les coordonnées de sortie en y
 * @param sx '' pour les coordonnées de sortie en x
 * @param sy '' pour les coordonnées de sortie en y
 * @param heading orientation (passsage par ref'')
 * 
 * @return renvoie si les coordonées sont trouvées dans le labyrinthe
 * 
*/
bool get_mazer_io(char**matrix,char in,char out,int x,int y,int*ex, 
 int*ey, int*sx, int*sy, int*heading_in, int*heading_out);


#endif

// end