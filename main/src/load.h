/*load.h*/
#ifndef LOAD_H
#define LOAD_H


/**
 * @brief fonction pour mettre les données d'un fichier 
 * dans une matrice de char 2d dynamique 
 * @ref https://github.com/portfoliocourses/c-example-code/blob/main/files_lines_to_dynamic_array.c
 * 
 * @param filename nom du fichier ou extraire la matrice
 * @param finallines est modifié pour pouvoir connaitre le nombre de lignes dans la matrice
 * @param finalcols renvoie le nombre de colonnes a travers cette variable (sert de return)
 * 
 * @warning none (les problèmes sont résolus dans la fonctions)
*/
char ** get_char_array_fromfile(char*filename, int*finallines, int*finalcols);

/**
 * #tools file
 * @brief charge les données d'un fichier dans une chaine de caractère
 * QUELQUE SOIT LA TAILLE DE CHAQUE LIGNE 
 *
*/
char * read_file_char_by_char(char * filename, int*nblines, int*nbcols);

#endif

// end page