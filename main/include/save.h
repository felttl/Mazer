/* save.h */
#ifndef SAVE_H
#define SAVE_H

/**
 * @brief sauvegarde les données d'une ligne 
 *  (séparateur avec \n pour plusieurs lignes)
 * #tools file
 * 
 *  -   ATTENTION : les données sont écrasées a chaque fois
 *  pour permettre de compiler plusieurs fois le même fichier
 *  de la même manière (si le fichier a la même nom)
 *  mais n'as pas forcément le même contenu dans le fichier d'entree
 * et de sortie
 * 
 * 
*/
void save_matr(char** matr, int nbline);

#endif

// end page
