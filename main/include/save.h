/* save.h */
#ifndef SAVE_H
#define SAVE_H

/**
 * @brief 
 * 
 *  -   ATTENTION : 
 * 
*/



/**
 * @brief sauvegarde les données d'une ligne 
 *  (séparateur avec \\n pour plusieurs lignes)
 * #tools file
 * @warning les données sont écrasées a chaque fois
 *  pour permettre de compiler plusieurs fois le même fichier
 *  de la même manière (si le fichier a la même nom)
 *  mais n'as pas forcément le même contenu dans le fichier d'entree
 * et de sortie
 * 
 * @param matr char** : matrice de données a 
 * sauvegarder (numbre de 1 a 9 max, pour 
 * chaque état de cellule (murs, pion, visité, etc...))
 * @param nbline int : nombre de lignes de la matrice
 * @param filepath char* : nom du fichier incluant le 
 * chemin (ex: "../../file_out.txt")
 */
void save_matr(char** matr, int nbline, char* filepath);

#endif

// end page
